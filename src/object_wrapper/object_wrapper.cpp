//
// Created by starblob on 8/3/25.
//
extern "C"{
#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
}
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/rendering_server.hpp>
#include "../object_wrapper/object_wrapper.h"




void ObjectWrapper::_bind_methods()
{
	godot::ClassDB::bind_method(D_METHOD("get_name", "ObjectWrapper"), &ObjectWrapper::get_name);
}

String ObjectWrapper::get_name(ObjectWrapper* wrapper) {
    if (wrapper && wrapper->element) {
        GstElement* elem = wrapper->element.get();  // Accessing the element of the passed-in wrapper
        const char* name = GST_OBJECT_NAME(elem);
        return String(name);
    }
    return "NULL_ELEMENT";
}
