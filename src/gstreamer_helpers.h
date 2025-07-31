//
// Created by starblob on 7/31/25.
//
#pragma once
#include <glib-2.0/glib.h>


class GodotStringToGChar {
    godot::String godot_str;
    godot::CharString utf8;
public:
    GodotStringToGChar(const godot::Variant& v) {
        godot_str = godot::String(v);
        utf8 = godot_str.utf8();
    }

    operator const gchar*() const {
        return utf8.get_data();  // This is safe: utf8 is stored in the object
    }
};
