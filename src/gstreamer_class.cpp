#include "gstreamer_class.h"
#include "gstreamer_helpers.h"

#include <gst/gst.h>
#include <gst/app/gstappsink.h>
#include <gst/gstbuffer.h>
#include <gst/gstbuffer.h>
#include <gst/gstcaps.h>



void Gstreamer::_bind_methods() {
	godot::ClassDB::bind_method(D_METHOD("element_factory_find", "String"), &Gstreamer::element_factory_find);
}

void Gstreamer::element_factory_find(const Variant &p_variant) const {
	int argc = 0;
	char **argv = nullptr;
	gst_init(&argc, &argv);

	GstElementFactory* srcfactory = gst_element_factory_find(GodotStringToGChar(p_variant));
	if (!srcfactory)
	{
		print_error("Failed to find ", p_variant, " element factory.\n");
	}
}
