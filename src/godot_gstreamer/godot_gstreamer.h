#pragma once

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "object_wrapper/object_wrapper.h"


using namespace godot;

class Gstreamer : public RefCounted {
	GDCLASS(Gstreamer, RefCounted)

protected:
	static void _bind_methods();

public:
	Gstreamer() = default;
	~Gstreamer() override = default;

	void gststreamer_init();
	ObjectWrapper* element_factory_find(const Variant& p_variant);
	ObjectWrapper* element_factory_make(const String &a_variant,const String &b_variant);
	ObjectWrapper* element_factory_create(const ObjectWrapper* a_variant,const String &b_variant);
	ObjectWrapper* g_parse_launch(const Variant &a_variant);

};
