{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 3,
			"revision" : 3,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"rect" : [ 1479.0, 56.0, 1017.0, 763.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "Default Max 7",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 336.0, 284.0, 41.0, 22.0 ],
					"style" : "",
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-32",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "FullPacket" ],
					"patching_rect" : [ 707.0, 652.0, 53.0, 22.0 ],
					"style" : "",
					"text" : "o.flatten"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-30",
					"linecount" : 7,
					"maxclass" : "o.compose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 428.0, 568.0, 231.0, 106.0 ],
					"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 47, 116, 121, 112, 101, 0, 0, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 12, 47, 119, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 12, 47, 104, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 12, 47, 120, 0, 0, 44, 102, 0, 0, 67, -43, 14, 0, 0, 0, 0, 12, 47, 121, 0, 0, 44, 102, 0, 0, 66, 82, -100, 0, 0, 0, 0, 20, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 44, 102, 0, 0, 64, -120, 90, -31, 0, 0, 0, 20, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103 ],
					"saved_bundle_length" : 156,
					"text" : "/type : \"rectangle\",\n/w : 30.,\n/h : 30.,\n/x : 426.109,\n/y : 52.6523,\n/time/start : 4.26109,\n/duration : 0.3",
					"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-29",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 250.0, 76.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-31",
					"maxclass" : "o.expr.codebox",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "FullPacket", "FullPacket" ],
					"patching_rect" : [ 61.0, 291.0, 150.0, 30.0 ],
					"textcolor" : [ 0.0, 0.0, 0.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-28",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "FullPacket" ],
					"patching_rect" : [ 707.0, 583.0, 93.0, 22.0 ],
					"style" : "",
					"text" : "o.route /symbol"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "FullPacket" ],
					"patching_rect" : [ 707.0, 698.0, 71.0, 22.0 ],
					"style" : "",
					"text" : "o.downcast"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "FullPacket" ],
					"patching_rect" : [ 707.0, 619.0, 59.0, 22.0 ],
					"style" : "",
					"text" : "o.route /*"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 707.0, 481.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-21",
					"linecount" : 9,
					"maxclass" : "o.compose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 14.5, 489.0, 424.0, 133.0 ],
					"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 24, 47, 116, 105, 109, 101, 47, 108, 111, 111, 107, 117, 112, 0, 0, 0, 0, 44, 102, 0, 0, 64, 66, -113, 92, 0, 0, 0, 36, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 116, 105, 109, 101, 47, 108, 111, 99, 97, 108, 0, 44, 102, 0, 0, 63, 77, 85, 94, 0, 0, 0, 40, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 116, 121, 112, 101, 0, 0, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 119, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 104, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 120, 0, 0, 44, 102, 0, 0, 67, -117, -8, 0, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 121, 0, 0, 44, 102, 0, 0, 67, 40, 124, 0, 0, 0, 0, 36, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 44, 102, 0, 0, 64, 51, 40, -11, 0, 0, 0, 36, 47, 115, 121, 109, 98, 111, 108, 115, 65, 116, 84, 105, 109, 101, 47, 48, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103 ],
					"saved_bundle_length" : 336,
					"text" : "/time/lookup : 3.04,\n/symbolsAtTime/0/time/local : 0.802084,\n/symbolsAtTime/0/type : \"rectangle\",\n/symbolsAtTime/0/w : 30.,\n/symbolsAtTime/0/h : 30.,\n/symbolsAtTime/0/x : 279.938,\n/symbolsAtTime/0/y : 168.484,\n/symbolsAtTime/0/time/start : 2.79937,\n/symbolsAtTime/0/duration : 0.3",
					"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-20",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "FullPacket" ],
					"patching_rect" : [ 707.0, 554.0, 63.0, 22.0 ],
					"style" : "",
					"text" : "o.explode"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-19",
					"linecount" : 7,
					"maxclass" : "o.compose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 443.0, 65.0, 231.0, 106.0 ],
					"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 47, 116, 121, 112, 101, 0, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 12, 47, 120, 0, 0, 44, 102, 0, 0, 66, 108, 0, 0, 0, 0, 0, 12, 47, 121, 0, 0, 44, 102, 0, 0, 67, -120, 0, 0, 0, 0, 0, 12, 47, 119, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 12, 47, 104, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 44, 102, 0, 0, 63, 23, 10, 61, 0, 0, 0, 20, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 0, 44, 102, 0, 0, 62, -103, -103, -102 ],
					"saved_bundle_length" : 152,
					"text" : "/type : \"circle\",\n/x : 59.,\n/y : 272.,\n/w : 30.,\n/h : 30.,\n/time/start : 0.59,\n/duration : 0.3",
					"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-24",
					"linecount" : 7,
					"maxclass" : "o.compose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 641.0, 345.0, 231.0, 106.0 ],
					"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20, 47, 116, 121, 112, 101, 0, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 12, 47, 120, 0, 0, 44, 102, 0, 0, 66, 108, 0, 0, 0, 0, 0, 12, 47, 121, 0, 0, 44, 102, 0, 0, 67, -120, 0, 0, 0, 0, 0, 12, 47, 119, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 12, 47, 104, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 44, 102, 0, 0, 63, 23, 10, 61, 0, 0, 0, 20, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 0, 44, 102, 0, 0, 62, -103, -103, -102 ],
					"saved_bundle_length" : 152,
					"text" : "/type : \"circle\",\n/x : 59.,\n/y : 272.,\n/w : 30.,\n/h : 30.,\n/time/start : 0.59,\n/duration : 0.3",
					"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "FullPacket" ],
					"patching_rect" : [ 575.0, 299.0, 71.0, 22.0 ],
					"style" : "",
					"text" : "o.downcast"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "FullPacket" ],
					"patching_rect" : [ 767.0, 202.0, 100.0, 22.0 ],
					"style" : "",
					"text" : "o.route /symbol/*"
				}

			}
, 			{
				"box" : 				{
					"fontface" : 0,
					"fontsize" : 12.0,
					"id" : "obj-12",
					"linecount" : 7,
					"maxclass" : "o.compose",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 767.0, 50.0, 231.0, 106.0 ],
					"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 120, 0, 44, 100, 0, 0, 64, 77, -128, 0, 0, 0, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 121, 0, 44, 100, 0, 0, 64, 113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 119, 0, 44, 100, 0, 0, 64, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 104, 0, 44, 100, 0, 0, 64, 62, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 100, 0, 0, 63, -30, -31, 71, -82, 20, 122, -31, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 100, 0, 0, 63, -45, 51, 51, 51, 51, 51, 51 ],
					"saved_bundle_length" : 236,
					"text" : "/symbol/0/type : \"circle\",\n/symbol/0/x : 59.,\n/symbol/0/y : 272.,\n/symbol/0/w : 30.,\n/symbol/0/h : 30.,\n/symbol/0/time/start : 0.59,\n/symbol/0/duration : 0.3",
					"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-22",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patcher" : 					{
						"fileversion" : 1,
						"appversion" : 						{
							"major" : 7,
							"minor" : 3,
							"revision" : 3,
							"architecture" : "x64",
							"modernui" : 1
						}
,
						"rect" : [ 38.0, 79.0, 1012.0, 681.0 ],
						"bglocked" : 0,
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 1,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 1,
						"objectsnaponopen" : 1,
						"statusbarvisible" : 2,
						"toolbarvisible" : 1,
						"lefttoolbarpinned" : 0,
						"toptoolbarpinned" : 0,
						"righttoolbarpinned" : 0,
						"bottomtoolbarpinned" : 0,
						"toolbars_unpinned_last_save" : 0,
						"tallnewobj" : 0,
						"boxanimatetime" : 200,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"description" : "",
						"digest" : "",
						"tags" : "",
						"style" : "",
						"subpatcher_template" : "Default Max 7",
						"boxes" : [ 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-1",
									"index" : 1,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 25.0, 31.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"fontface" : 0,
									"fontsize" : 12.0,
									"id" : "obj-18",
									"linecount" : 77,
									"maxclass" : "o.compose",
									"numinlets" : 2,
									"numoutlets" : 1,
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 100.0, 542.0, 1057.0 ],
									"saved_bundle_data" : [ 35, 98, 117, 110, 100, 108, 101, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 120, 0, 44, 102, 0, 0, 67, 15, 26, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 121, 0, 44, 102, 0, 0, 67, -106, -21, -128, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 63, -73, 43, -123, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 48, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 120, 0, 44, 102, 0, 0, 67, 54, -115, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 121, 0, 44, 102, 0, 0, 67, -121, 97, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 63, -23, -86, 61, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 49, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 120, 0, 44, 102, 0, 0, 67, 73, -38, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 121, 0, 44, 102, 0, 0, 67, 104, 51, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 1, 47, 92, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 50, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 120, 0, 44, 102, 0, 0, 67, 82, 124, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 121, 0, 44, 102, 0, 0, 67, 31, 19, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 6, -75, -62, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 51, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 120, 0, 44, 102, 0, 0, 67, 101, -65, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 121, 0, 44, 102, 0, 0, 67, -124, -93, -128, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 19, 9, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 52, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 120, 0, 44, 102, 0, 0, 67, 102, -8, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 121, 0, 44, 102, 0, 0, 67, 65, 87, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 19, -47, -21, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 53, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 120, 0, 44, 102, 0, 0, 67, 106, -65, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 121, 0, 44, 102, 0, 0, 66, -6, -126, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 22, 60, -51, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 54, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 99, 105, 114, 99, 108, 101, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 120, 0, 44, 102, 0, 0, 67, -127, -18, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 121, 0, 44, 102, 0, 0, 67, 97, -16, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 38, 79, 92, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 55, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 120, 0, 44, 102, 0, 0, 67, -117, -8, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 121, 0, 44, 102, 0, 0, 67, 40, 124, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 51, 40, -11, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 56, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 116, 121, 112, 101, 0, 0, 44, 115, 0, 0, 116, 114, 105, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 119, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 104, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 120, 0, 44, 102, 0, 0, 67, -85, 83, -128, 0, 0, 0, 20, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 121, 0, 44, 102, 0, 0, 67, 3, -20, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 0, 44, 102, 0, 0, 64, 91, 76, 41, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 57, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 0, 44, 102, 0, 0, 62, -103, -103, -103, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 116, 121, 112, 101, 0, 44, 115, 0, 0, 114, 101, 99, 116, 97, 110, 103, 108, 101, 0, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 119, 0, 0, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 104, 0, 0, 0, 0, 44, 102, 0, 0, 65, -16, 0, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 120, 0, 0, 0, 0, 44, 102, 0, 0, 67, -43, 14, 0, 0, 0, 0, 24, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 121, 0, 0, 0, 0, 44, 102, 0, 0, 66, 82, -100, 0, 0, 0, 0, 32, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 116, 105, 109, 101, 47, 115, 116, 97, 114, 116, 0, 0, 0, 44, 102, 0, 0, 64, -120, 90, -31, 0, 0, 0, 28, 47, 115, 121, 109, 98, 111, 108, 47, 49, 48, 47, 100, 117, 114, 97, 116, 105, 111, 110, 0, 44, 102, 0, 0, 62, -103, -103, -103 ],
									"saved_bundle_length" : 2208,
									"text" : "/symbol/0/type : \"rectangle\",\n/symbol/0/w : 30.,\n/symbol/0/h : 30.,\n/symbol/0/x : 143.102,\n/symbol/0/y : 301.84,\n/symbol/0/time/start : 1.43102,\n/symbol/0/duration : 0.3,\n/symbol/1/type : \"circle\",\n/symbol/1/w : 30.,\n/symbol/1/h : 30.,\n/symbol/1/x : 182.551,\n/symbol/1/y : 270.758,\n/symbol/1/time/start : 1.82551,\n/symbol/1/duration : 0.3,\n/symbol/2/type : \"circle\",\n/symbol/2/w : 30.,\n/symbol/2/h : 30.,\n/symbol/2/x : 201.852,\n/symbol/2/y : 232.199,\n/symbol/2/time/start : 2.01852,\n/symbol/2/duration : 0.3,\n/symbol/3/type : \"circle\",\n/symbol/3/w : 30.,\n/symbol/3/h : 30.,\n/symbol/3/x : 210.484,\n/symbol/3/y : 159.074,\n/symbol/3/time/start : 2.10484,\n/symbol/3/duration : 0.3,\n/symbol/4/type : \"circle\",\n/symbol/4/w : 30.,\n/symbol/4/h : 30.,\n/symbol/4/x : 229.746,\n/symbol/4/y : 265.277,\n/symbol/4/time/start : 2.29746,\n/symbol/4/duration : 0.3,\n/symbol/5/type : \"circle\",\n/symbol/5/w : 30.,\n/symbol/5/h : 30.,\n/symbol/5/x : 230.969,\n/symbol/5/y : 193.34,\n/symbol/5/time/start : 2.30969,\n/symbol/5/duration : 0.3,\n/symbol/6/type : \"rectangle\",\n/symbol/6/w : 30.,\n/symbol/6/h : 30.,\n/symbol/6/x : 234.746,\n/symbol/6/y : 125.254,\n/symbol/6/time/start : 2.34746,\n/symbol/6/duration : 0.3,\n/symbol/7/type : \"circle\",\n/symbol/7/w : 30.,\n/symbol/7/h : 30.,\n/symbol/7/x : 259.859,\n/symbol/7/y : 225.938,\n/symbol/7/time/start : 2.59859,\n/symbol/7/duration : 0.3,\n/symbol/8/type : \"rectangle\",\n/symbol/8/w : 30.,\n/symbol/8/h : 30.,\n/symbol/8/x : 279.938,\n/symbol/8/y : 168.484,\n/symbol/8/time/start : 2.79937,\n/symbol/8/duration : 0.3,\n/symbol/9/type : \"triangle\",\n/symbol/9/w : 30.,\n/symbol/9/h : 30.,\n/symbol/9/x : 342.652,\n/symbol/9/y : 131.922,\n/symbol/9/time/start : 3.42652,\n/symbol/9/duration : 0.3,\n/symbol/10/type : \"rectangle\",\n/symbol/10/w : 30.,\n/symbol/10/h : 30.,\n/symbol/10/x : 426.109,\n/symbol/10/y : 52.6523,\n/symbol/10/time/start : 4.26109,\n/symbol/10/duration : 0.3",
									"textcolor" : [ 0.188, 0.188, 0.188, 1.0 ]
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-20",
									"index" : 2,
									"maxclass" : "inlet",
									"numinlets" : 0,
									"numoutlets" : 1,
									"outlettype" : [ "FullPacket" ],
									"patching_rect" : [ 573.0, 40.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
, 							{
								"box" : 								{
									"comment" : "",
									"id" : "obj-21",
									"index" : 1,
									"maxclass" : "outlet",
									"numinlets" : 1,
									"numoutlets" : 0,
									"patching_rect" : [ 50.0, 2046.0, 30.0, 30.0 ],
									"style" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-1", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-21", 0 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-18", 0 ]
								}

							}
, 							{
								"patchline" : 								{
									"destination" : [ "obj-18", 1 ],
									"disabled" : 0,
									"hidden" : 0,
									"source" : [ "obj-20", 0 ]
								}

							}
 ]
					}
,
					"patching_rect" : [ 707.0, 519.0, 50.0, 22.0 ],
					"saved_object_attributes" : 					{
						"description" : "",
						"digest" : "",
						"globalpatchername" : "",
						"style" : "",
						"tags" : ""
					}
,
					"style" : "",
					"text" : "p score"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 314.0, 245.0, 41.0, 22.0 ],
					"style" : "",
					"text" : "dump"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 148.0, 411.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 336.0, 81.0, 45.0, 45.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-15",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 148.0, 116.0, 100.0, 22.0 ],
					"style" : "",
					"text" : "scale 0. 1. 0. 2."
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-16",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 148.0, 18.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "float" ],
					"patching_rect" : [ 148.0, 83.0, 81.0, 22.0 ],
					"style" : "",
					"text" : "snapshot~ 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "signal" ],
					"patching_rect" : [ 148.0, 51.0, 81.0, 22.0 ],
					"style" : "",
					"text" : "phasor~ 1"
				}

			}
, 			{
				"box" : 				{
					"format" : 6,
					"id" : "obj-14",
					"maxclass" : "flonum",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 77.0, 98.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 363.0, 179.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-4",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 82.0, 326.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 82.0, 358.0, 82.0, 22.0 ],
					"style" : "",
					"text" : "getsymbol $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-6",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 90.0, 202.0, 50.0, 22.0 ],
					"style" : "",
					"text" : "time $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 257.0, 130.0, 24.0, 24.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 250.0, 163.0, 100.0, 22.0 ],
					"style" : "",
					"text" : "del 10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 250.0, 213.0, 37.0, 22.0 ],
					"style" : "",
					"text" : "open"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "FullPacket", "FullPacket" ],
					"patching_rect" : [ 257.0, 345.0, 61.0, 22.0 ],
					"style" : "",
					"text" : "symbolist"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-1", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-13", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-10", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-15", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-19", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-28", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-20", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 1,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-30", 1 ],
					"disabled" : 0,
					"hidden" : 0,
					"order" : 0,
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-32", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-28", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 4 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-29", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-25", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-32", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-7", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-4", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-8", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "symbolist.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.compose.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.route.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.downcast.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.explode.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.expr.codebox.mxo",
				"type" : "iLaX"
			}
, 			{
				"name" : "o.flatten.mxo",
				"type" : "iLaX"
			}
 ],
		"autosave" : 0,
		"bgfillcolor_type" : "gradient",
		"bgfillcolor_color1" : [ 0.376471, 0.384314, 0.4, 1.0 ],
		"bgfillcolor_color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
		"bgfillcolor_color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
		"bgfillcolor_angle" : 270.0,
		"bgfillcolor_proportion" : 0.39
	}

}
