#include "example_class.h"
#include "gstreamer_helpers.h"
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
	godot::ClassDB::bind_method(D_METHOD("element_factory_find", "String"), &Gstreamer::element_factory_find);
	godot::ClassDB::bind_method(D_METHOD("gstreamer_init_function"), &Gstreamer::gststreamer_init);
}


void Gstreamer::gststreamer_init()
{
	int argc = 0;
	char **argv = nullptr;
	gst_init(&argc, &argv);
}



void Gstreamer::element_factory_find(const Variant &p_variant) const {

	GstElementFactory* srcfactory = gst_element_factory_find(GodotStringToGChar(p_variant));
	if (!srcfactory)
	{
		print_error("Failed to find ", p_variant, " element factory.\n");
	}
}
