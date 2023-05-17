
See also: [device](device.md), [notifications](notifications.md)


# Initialization

In order to stream, a client must know the stream names, available formats, etc.

The only way for a client to get these is by subscribing to the `notification` topic. When the server detects a subscriber on this topic, it will broadcast initialization messages in the following order:

- `device-header`
- `device-options` - optional
- For each stream:
    - `stream-header`
    - `stream-options`

These initialization messages should only have effect on devices that are not already initialized. They are expected in the above order.

Once all streams have been received, the device is initialized and ready to use. See [Streaming](streaming.md).


#### `device-header`

This is the very first message, for example:

```JSON
{
    "id": "device-header",
    "n-streams": 5,
    "extrinsics": [
        ["Depth","Gyro",[1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0,-0.005520000122487545,0.005100000184029341,0.011739999987185001]]
        ["Depth","Infrared 2",[1.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,1.0,-0.04986396059393883,0.0,0.0]]
    ]
}
```

Mainly the number of streams to expect. The device will wait for this many stream headers to arrive to finish initialization.


#### `device-options`

This is optional: not all devices have options.

```JSON
{
    "id": "device-options",
    "options": [
        {"description":"Enable/Disable global timestamp","name":"Global Time Enabled","range-default":1.0,"range-max":1.0,"range-min":0.0,"range-step":1.0,"value":1.0},
        {"description":"HDR Option","name":"Hdr Enabled","range-default":0.0,"range-max":1.0,"range-min":0.0,"range-step":1.0,"value":0.0}
    ]
}
```

Each option is a floating point `value`, with a `name`, `description`, valid range (`default`, `min`, `max`, `step`).

These options will be shown in the Viewer.


#### `stream-header`

Information about a specific stream:
- `name` is the stream name, e.g. `Color`
    - This will be shown in the Viewer
    - This is also the name of the topic containing the stream data
        - E.g., `rt/<topic-root>_Color`
        - If it contains a space, the space will be replaced by `_` - e.g., `rt/<topic-root>_Infrared_1`
- `profiles` array
    - Each profile is itself an array of `[frequency, format, width, height]`
    - Format is a string representation, similar to the image encoding in ROS
- `default-profile-index` is the index into the `profiles` for the default profile
- `sensor-name` is the name of the sensor
    - Sometimes, a single sensor may produce multiple streams, e.g. `Stereo Module` produces a `Depth` stream and also `Infrared`
    - Streaming one stream requires starting the sensor, and so may have effect on the other streams, depending on the server implementation
    - This allows streams to be grouped by the client and may affect its logic
- `type` is one of `ir`, `depth`, `color`, `fisheye`, `confidence`, `accel`, `gyro`, `pose` - similar to the librealsense `rs2_stream` enum
- `metadata-enabled` is `true` if a `metadata` topic for the device will be written to


```JSON
{
    "default-profile-index": 29,
    "id": "stream-header",
    "metadata-enabled": true,
    "name": "Color",
    "profiles": [
        [30,"rgb8",1280,800],
        [30,"BYR2",1280,800],
        [30,"Y16",1280,800],
        ...
    ],
    "sensor-name": "RGB Camera",
    "type": "color"
}
```

#### `stream-options`

- `stream-name` is the name of the stream, same as in `stream-header`
- `intrinsics` is an array of (width,height)-specific intrinsic values
    - Each is itself an array of `[width, height, principal_point_x, principal_point_y, focal_lenght_x, focal_lenght_y, distortion_model,  distortion_coeffs[0], distortion_coeffs[1], distortion_coeffs[2], distortion_coeffs[3], distortion_coeffs[4]]`
- `options` is an array of option objects, same as `device-options` above

```JSON
{
    "id": "stream-options",
    "intrinsics": [
        [640,480,320.14276123046875,238.4058837890625,378.80572509765625,378.80572509765625,4,0.0,0.0,0.0,0.0,0.0],
        [1280,720,640.2379150390625,357.3431396484375,631.3428955078125,631.3428955078125,4,0.0,0.0,0.0,0.0,0.0]
    ],
    "options": [
        {"description":"Enable / disable backlight compensation","name":"Backlight Compensation","range-default":0.0,"range-max":1.0,"range-min":0.0,"range-step":1.0,"value":0.0},
        {"description":"UVC image brightness","name":"Brightness","range-default":0.0,"range-max":64.0,"range-min":-64.0,"range-step":1.0,"value":0.0},
        {"description":"UVC image contrast","name":"Contrast","range-default":50.0,"range-max":100.0,"range-min":0.0,"range-step":1.0,"value":50.0}
    ],
    "stream-name":"Infrared 1"
}
```