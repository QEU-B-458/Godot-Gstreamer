//
// Created by starblob on 8/3/25.
//
extern "C"{
#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
}
#include "../godot_gstreamer.h"
//#include "gst_umapstore.h"
#include <godot_cpp/classes/rendering_server.hpp>
#include <memory>







//std::unordered_map<std::string, std::any> g_umap::g_umapgst;
//std::unordered_map<std::string, GstElement*> g_umap::elements;
void Gstreamer::_bind_methods()
{
	godot::ClassDB::bind_method(D_METHOD("gstreamer_init_function"), &Gstreamer::gststreamer_init);
	godot::ClassDB::bind_method(D_METHOD("element_factory_find", "element_name"), &Gstreamer::element_factory_find);
	godot::ClassDB::bind_method(D_METHOD("element_factory_create", "element_name"), &Gstreamer::element_factory_make);
	ClassDB::bind_method(D_METHOD("set_element", "ptr"), &Gstreamer::set_element);
	ClassDB::bind_method(D_METHOD("get_element"), &Gstreamer::get_element);
	//godot::ClassDB::bind_method(D_METHOD("g_parse_launch", "terminal_syntax_string", "name_the_element"), &Gstreamer::g_parse_launch);
	//godot::ClassDB::bind_method(D_METHOD("g_bin_get_by_name", "element_name","name_the_element"), &Gstreamer::g_bin_get_by_name);
	//godot::ClassDB::bind_method(D_METHOD("g_app_sink_set_emit_signals","bool"), &Gstreamer::g_app_sink_set_emit_signals);
	//godot::ClassDB::bind_method(D_METHOD("g_app_sink_set_drop","bool"), &Gstreamer::g_app_sink_set_drop);
	//godot::ClassDB::bind_method(D_METHOD("g_app_sink_set_max_buffers","int"), &Gstreamer::g_app_sink_set_max_buffers);
}


void Gstreamer::gststreamer_init()
{
	int argc = 0;
	char **argv = nullptr;
	gst_init(&argc, &argv);
}


Variant Gstreamer::element_factory_find(const Variant& p_variant) {
	String godotstring = p_variant;
	std::string test = godotstring.utf8().get_data();
	GstElementFactory *srcfactory = gst_element_factory_find(test.c_str());
	if (srcfactory) {
		print_line("Found ", p_variant, " element factory.");
	} else {
		print_error("Failed to find ", p_variant, " element factory.");
	}

	return p_variant;
}


Gstreamer::GstElementWrapper* Gstreamer::element_factory_make(const Variant &a_variant, const Variant &b_variant){


	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	String d = b_variant;
	std::string b_var = d.utf8().get_data();
	GstElement *element = gst_element_factory_make(a_var.c_str(), b_var.c_str());


	if (element) {
		print_line("created ", a_variant, " element factory.");
	} else {
		print_error("Failed to find ", a_variant, " element factory.");
	}

	return initialize(element);
}

void Gstreamer::set_element(int a_variant) {
	int ptr = a_variant;
	element = reinterpret_cast<GstElement*>(ptr);
}

int Gstreamer::get_element() const
{
	return reinterpret_cast<int>(element);
}

/*
void Gstreamer::g_parse_launch(const Variant &a_variant, const Variant &b_variant)
{
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	String d = b_variant;
	std::string b_var = d.utf8().get_data();
	GstElement *element = gst_parse_launch(a_var.c_str(), NULL);
	if (element) {
		print_line("created ", a_variant, " ", GST_OBJECT_NAME(element),".");
		//g_umap::gstelement(b_var,element);
		g_umap::add_element(b_var,element);
	} else {
		print_error("Failed to create ", a_variant, " ", b_variant,".");
	}
}

void Gstreamer::g_bin_get_by_name(const Variant &a_variant, const Variant &b_variant)
{
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	String d = b_variant;
	std::string b_var = d.utf8().get_data();
	const auto it = g_umap::get_element(b_var);
	GstElement *element = gst_bin_get_by_name(GST_BIN(it),b_var.c_str());
	if (!element) {
		print_line("created ", a_variant, " ", b_variant,".");
		g_umap::add_element(b_var,element);
	} else {
		print_error("Failed to create ", a_variant, " ", b_variant,".");
	}
}


void Gstreamer::g_app_sink_set_emit_signals(const Variant &a_variant, const Variant &b_variant){
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	const auto it = g_umap::get_element(a_var);
	gst_app_sink_set_emit_signals(reinterpret_cast<GstAppSink*>(it),b_variant);
}


void Gstreamer::g_app_sink_set_drop(const Variant &a_variant, const bool b_variant = true){
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	const auto it = g_umap::get_element(a_var);
	gst_app_sink_set_drop(reinterpret_cast<GstAppSink*>(it),b_variant);

}

void g_app_sink_set_max_buffers(const Variant &a_variant,const int b_variant = 1){
	String c = a_variant;
	std::string a_var = c.utf8().get_data();
	const auto it = g_umap::get_element(a_var);
	gst_app_sink_set_max_buffers(reinterpret_cast<GstAppSink*>(it), b_variant);
}
*/