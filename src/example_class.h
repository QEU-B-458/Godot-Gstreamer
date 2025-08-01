#pragma once
#include <glib.h>
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
//#include <unordered_map>

using namespace godot;

class Gstreamer : public RefCounted {
	GDCLASS(Gstreamer, RefCounted)





protected:
	static void _bind_methods();

//std::unordered_map<char*, GstElement> elements;


public:
	Gstreamer() = default;
	~Gstreamer() override = default;

	void element_factory_find(const Variant &p_variant) const;
	void gststreamer_init();
};
