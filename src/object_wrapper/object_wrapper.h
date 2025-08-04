
#include <godot-cpp/gen/include/godot_cpp/classes/object.hppc >
//
// Created by starblob on 8/4/25.
//
extern "C" {
#include <gst/gst.h>
#include <gstreamer-1.0/gst/gstelement.h>
}
#pragma once
#include <glib.h>
#include <boost/array.hpp>
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <memory>



using namespace godot;
class ObjectWrapper : public Object {
	GDCLASS(ObjectWrapper, Object);

	using GstElementSharedPtr = std::shared_ptr<GstElement>;
	GstElementSharedPtr g_element;

	struct GstObjectDeleter {
		void operator()(GstElement* element) const {
			if (element) {
				print_line("Godot-cpp: Unreferencing GstElement: ");
				gst_object_unref(element);
			}
		}
	};

	class GstElementWrapper : public godot::Object{
		GDCLASS(GstElementWrapper, Object);
	public:
		GstElementSharedPtr element;
	};

	GstElement* get_gstreamer_element()
	{
		return g_element.get();
	}

	GstElementWrapper* initialize(GstElement* element) {
		GstElementWrapper* wrapper = memnew(GstElementWrapper());
		if (element) {

			// Take ownership of the raw pointer with the custom deleter.
			wrapper->element = GstElementSharedPtr(element, GstObjectDeleter());
			g_element = wrapper->element;
			print_line("Godot-cpp: GstElementWrapper initialized with GstElement: ");
		} else {
			// Handle error case
			g_element = nullptr;
			print_error("Godot-cpp: Failed to initialize GstElementWrapper with null element.");
		}

		return wrapper;
	}

	godot::String get_name()
	{
		if (g_element) {
			return godot::String(GST_OBJECT_NAME(g_element.get()));
		}
		return "NULL_ELEMENT";
	}



protected:
	static void _bind_methods();


public:
	ObjectWrapper() = default;
	~ObjectWrapper() override = default;


};
