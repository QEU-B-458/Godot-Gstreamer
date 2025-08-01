extends Node


func _ready() -> void:
	var gst := Gstreamer.new()
	gst.gstreamer_init_function()
	gst.element_factory_find("autovideosink")
