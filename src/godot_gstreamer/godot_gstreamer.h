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
	void element_factory_find(const Variant& p_variant);
	ObjectWrapper* element_factory_make(const Variant &a_variant,const Variant &b_variant);
	ObjectWrapper* g_parse_launch(const Variant &a_variant);

};
