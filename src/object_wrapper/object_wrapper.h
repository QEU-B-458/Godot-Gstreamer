//
// Created by starblob on 8/4/25.
//
#pragma once

extern "C" {
#include <gst/gst.h>
#include <gstreamer-1.0/gst/gstelement.h>
}

#include <glib.h>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <memory>

using namespace godot;

class ObjectWrapper : public Object {
    GDCLASS(ObjectWrapper, Object)

public:
    using ObjectWrapperSharedPtr = std::shared_ptr<GstElement>;

private:
    ObjectWrapperSharedPtr element;

    struct GoObjectDeleter {
        void operator()(GstElement* element) const {
            if (element) {
                print_line("Godot-cpp: Unreferencing GstElement.");
                gst_object_unref(element);
            }
        }
    };

protected:
    static void _bind_methods();

public:
	GstElement* get_element() const { return element.get(); }
    static ObjectWrapper* create(GstElement* element) {
        ObjectWrapper* wrapper = memnew(ObjectWrapper());

        if (element) {
            wrapper->element = ObjectWrapperSharedPtr(element, GoObjectDeleter());
            print_line("Godot-cpp: GstElementWrapper created with GstElement.");
        } else {
            print_error("Godot-cpp: Failed to create GstElementWrapper with null element.");
        }

        return wrapper;
    }
	
    ObjectWrapper() = default;
    ~ObjectWrapper() override = default;

	String get_name(ObjectWrapper* wrapper);


};

