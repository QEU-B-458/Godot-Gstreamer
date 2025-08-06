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

protected:
    static void _bind_methods();
public:
    std::shared_ptr<GstObject> dynamic;
    
    

public:
    //GstElementFactory* elem = a_variant->ObjectWrapper::get_as<GstElementFactory>();
    template<typename T>
    static ObjectWrapper* createDynamic(T* element) {
            ObjectWrapper* wrapper = memnew(ObjectWrapper());

        if (element) {
             // T must inherit from GstObject
            wrapper->dynamic = std::shared_ptr<GstObject>(
            reinterpret_cast<GstObject*>(element),
            [](GstObject* e) {
                if (e) {
                    print_line("Godot-cpp: Unreferencing dynamic GstObject.");
                    gst_object_unref(e);
                }
            }
        );
    } else {
        print_error("Godot-cpp: Failed to create wrapper with null element.");
    }

    return wrapper;
}

template<typename T>
T* get_as() const {
    return reinterpret_cast<T*>(dynamic.get());
}




    ObjectWrapper() = default;
    ~ObjectWrapper() override = default;
    
    String get_dynamicName(ObjectWrapper* wrapper);


};