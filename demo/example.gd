extends Node


func _ready() -> void:
	var gst := Gstreamer.new()
	gst.element_factory_find("")
