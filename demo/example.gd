extends Node


func _ready() -> void:
	var ow := ObjectWrapper.new()
	var gst := Gstreamer.new()
	gst.gstreamer_init_function()
	var g_element = gst.element_factory_find("uridecodebin")
	var g_sink = gst.g_parse_launch("videotestsrc ! videoconvert ! video/x-raw,format=RGBA ! appsink name=sink")
	var g_source = gst.element_factory_create(g_element,"source")
	var temp = ow.get_dynamicName(g_source)
	var temp1 = ow.get_dynamicName(g_element)
	var temp2 = ow.get_dynamicName(g_sink)
	print(temp)
	print(temp1)
	print(temp2)
	#gst.g_parse_launch("videotestsrc ! videoconvert ! video/x-raw,format=RGBA ! appsink name=sink","pipeline")
	#gst.g_bin_get_by_name("pipeline","sink")
	#gst.g_app_sink_set_drop("sink",true)
