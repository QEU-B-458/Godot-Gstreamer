extends Node


func _ready() -> void:
	var gst := Gstreamer.new()
	gst.gstreamer_init_function()
	var element = gst.element_factory_find("audioconvert")
	
	gst.store_element("audioconvert", element)
	gst.element_factory_create("audioconvert")
	var retrieved := gst.get_element("audioconvert")
	print("Same object:", element == retrieved)
