//
// Created by starblob on 8/3/25.
//
extern "C"{
#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
}
#include "godot_gstreamer.h"
#include <godot_cpp/classes/rendering_server.hpp>
#include "../object_wrapper/object_wrapper.h"



using namespace godot;

void Gstreamer::_bind_methods()
{
	godot::ClassDB::bind_method(D_METHOD("gstreamer_init_function"), &Gstreamer::gststreamer_init);
	godot::ClassDB::bind_method(D_METHOD("element_factory_find", "element_name"), &Gstreamer::element_factory_find);
	godot::ClassDB::bind_method(D_METHOD("element_factory_create", "element_name"), &Gstreamer::element_factory_make);
	godot::ClassDB::bind_method(D_METHOD("g_parse_launch", "terminal_syntax_string"), &Gstreamer::g_parse_launch);
}


void Gstreamer::gststreamer_init()
{
	int argc = 0;
	char **argv = nullptr;
	gst_init(&argc, &argv);
}


void Gstreamer::element_factory_find(const Variant& p_variant) {
	String godotstring = p_variant;
	std::string test = godotstring.utf8().get_data();
	GstElementFactory *srcfactory = gst_element_factory_find(test.c_str());
  //ObjectWrapper* obj = ObjectWrapper::create(srcfactory);
	if (srcfactory) {
		print_line("Found ", p_variant, " element factory.");
	} else {
		print_error("Failed to find ", p_variant, " element factory.");
	}

}

 ObjectWrapper* Gstreamer::element_factory_make(const Variant &a_variant, const Variant &b_variant){


	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	String d = b_variant;
	std::string b_var = d.utf8().get_data();
	GstElement *element = gst_element_factory_make(a_var.c_str(), b_var.c_str());

	ObjectWrapper* obj = ObjectWrapper::create(element);
	if (element) {
		print_line("created ", a_variant, " element factory.");
	} else {
		print_error("Failed to find ", a_variant, " element factory.");
	}
	return obj;
}



ObjectWrapper* Gstreamer::g_parse_launch(const Variant &a_variant)
{
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	GstElement *element = gst_parse_launch(a_var.c_str(), NULL);
	ObjectWrapper* obj = ObjectWrapper::create(element);
	if (element) {
		print_line("created ", a_variant, ".");
		
	} else {
		print_error("Failed to create ", a_variant, ".");
	}
	return obj;
}

