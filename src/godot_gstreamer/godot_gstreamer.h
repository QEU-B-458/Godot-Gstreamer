//
// Created by starblob on 8/3/25.
//
extern "C" {
#include <gst/gst.h>
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


class Gstreamer : public RefCounted {
	GDCLASS(Gstreamer, RefCounted);

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

//######################################################################################################################
	GstElement* element = nullptr;


protected:
	static void _bind_methods();


public:
	Gstreamer() = default;
	~Gstreamer() override = default;

	void gststreamer_init();
	Variant element_factory_find(const Variant& p_variant);
	GstElementWrapper* element_factory_make(const Variant &a_variant,const Variant &b_variant);
	void set_element(int ptr);
	int get_element() const;
	//void g_parse_launch(const Variant &a_variant, const Variant &b_variant);
	//void g_bin_get_by_name(const Variant &a_variant, const Variant &b_variant);
	//void g_app_sink_set_emit_signals(const Variant &a_variant, const Variant &b_variant);
	//void g_app_sink_set_drop(const Variant& a_variant, bool b_variant);
	//void g_app_sink_set_max_buffers(const Variant &a_variant,int b_variant);





};
