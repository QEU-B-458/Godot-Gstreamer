#include "godot_gstreamer.h"

#include <memory>

#include "gstreamer_helpers.h"
#include <godot_cpp/classes/ref_counted.hpp>
extern "C"{
#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <gst/gstbuffer.h>
#include <gst/gstbuffer.h>
#include <gst/gstcaps.h>
}


GstElement *example_class_new;
void Gstreamer::_bind_methods()
{
	godot::ClassDB::bind_method(D_METHOD("gstreamer_init_function"), &Gstreamer::gststreamer_init);
	godot::ClassDB::bind_method(D_METHOD("element_factory_find", "Factory_name"), &Gstreamer::element_factory_find);
	//godot::ClassDB::bind_method(D_METHOD("element_factory_create", "Factory_name"), &Gstreamer::element_factory_create);
	//godot::ClassDB::bind_method(D_METHOD("get_element", "name"), &Gstreamer::get_element);

}


void Gstreamer::gststreamer_init()
{
	int argc = 0;
	char **argv = nullptr;
	gst_init(&argc, &argv);
}


void Gstreamer::element_factory_find(const Variant& p_variant){

	String godotstring = p_variant;
	std::string test = godotstring.utf8().get_data();
	GstElementFactory *srcfactory = gst_element_factory_find(test.c_str());
	//GstElement *element = gst_element_factory_create(srcfactory, test.c_str())
	godot_gstreamer::create(test, srcfactory);
	if (!srcfactory)
	{
		print_error("Failed to find ", p_variant, " element factory.\n");
	}
}
/*
void Gstreamer::element_factory_create(const Variant &p_variant)
{
	String p = p_variant;
	std::string p_var = p.utf8().get_data();
	GstElement *element = nullptr;
	GstElement  gst_element_factory_create(p_var, p_var.c_str());
	//auto result = elements.try_emplace(p_var, element);

	if (!element)
	{
		print_error("Failed to find ", p_variant, " element factory.\n");
	}
	*/

	/*
	if (!result.second) {
		// The key already exists, so insertion failed
		print_error("Error: Key ", p_variant, "already exists in the elements map.");

		// Optional: Handle the case, like updating, throwing, logging, etc.
		// Example: throw std::runtime_error("Duplicate key insertion attempted.");
	} else {
		print_line("Element successfully inserted for key ",p_variant, ".");
	}



}
*/
/*
Ref<Gstreamer> Gstreamer::get_element(const String &name) const {
	auto it = element_map.find(name);
	if (it != element_map.end()) {
		return it->second;
	}
	return nullptr;
}
*/

