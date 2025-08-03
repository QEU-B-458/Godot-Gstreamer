#pragma once
#include <any>
#include <map>
#include <memory>
extern "C"{
#include <gstreamer-1.0/gst/gst.h>
}
#include <glib.h>
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include <unordered_map>

using namespace godot;

std::string name;

class Gstreamer : public RefCounted {
	GDCLASS(Gstreamer, RefCounted)


	class godot_gstreamer : public RefCounted {
	public:
		static std::unordered_map<std::string, std::shared_ptr<godot_gstreamer>> Gstelementfactory;

		static std::shared_ptr<godot_gstreamer> create(const std::string& name, GstElementFactory* factory) {
			auto instance = std::make_shared<godot_gstreamer>(factory);
			Gstelementfactory[name] = instance;
			return instance;
		}

		godot_gstreamer(GstElementFactory* factory) {
			print_error("Thing created\n");
		}

		~godot_gstreamer() {
			print_error("Thing destroyed\n");
		}
	};

protected:
	static void _bind_methods();


public:
	std::unordered_map<std::string, Gstreamer*> Gstelement;


	Gstreamer() = default;
	~Gstreamer() override;

	void gststreamer_init();
	void element_factory_find(const Variant& p_variant);
	//void element_factory_create(const Variant &p_variant);
	//Ref<Gstreamer> get_element(const String &name) const;





};
