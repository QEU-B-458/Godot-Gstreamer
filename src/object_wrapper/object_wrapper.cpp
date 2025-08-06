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
    godot::ClassDB::bind_method(D_METHOD("get_dynamicName", "ObjectWrapper"), &ObjectWrapper::get_dynamicName);
}


String ObjectWrapper::get_dynamicName(ObjectWrapper* wrapper){
    if (wrapper && wrapper->dynamic) {
        GstElement* elem = reinterpret_cast<GstElement*>(wrapper->dynamic.get());  // Accessing the element of the passed-in wrapper
        const char* name = GST_OBJECT_NAME(elem);
        return String(name);
    }
    return "NULL_ELEMENT";
}


