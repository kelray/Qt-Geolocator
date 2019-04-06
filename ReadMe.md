This is a simple demo desktop application in Qt to geolocate using a USB GPS and display your current location on the map. 
The application uses QMap library for map graphics: https://github.com/bbglab/qmap

A screenshot of the application:

<img width="361" alt="location_GPS map viewer_SFU surrey" src="https://user-images.githubusercontent.com/8460504/55594893-4620a980-56f6-11e9-8c9e-4c67623d20a2.png">

This application has been tested with two different GPS modules:
- VK-172 USB GPS.
![vk172](https://user-images.githubusercontent.com/8460504/55594488-aa426e00-56f4-11e9-9571-0460fe966326.png)

- uBlox Neo-6 serial GPS module with MCP2221A USB-to-UART bridge:


MCP2221A USB-to-UART bridge IC:

![mcp2221](https://user-images.githubusercontent.com/8460504/55594481-a4e52380-56f4-11e9-8e93-cbfb0e0d4ef3.png)

uBlox Neo-6 serial GPS module:

![Neo-6M-Pakistan-600x600](https://user-images.githubusercontent.com/8460504/55594482-a4e52380-56f4-11e9-803e-abd2556f7372.png)


Doesn't look very glamorous but works like charm:

![Neo6_mcp2221_GPS module_2](https://user-images.githubusercontent.com/8460504/55595378-56398880-56f8-11e9-90ea-991c34a62acd.jpg)

For details on the MCP2221A USB to UART bridge wiring and circuitry please check this blog post: 
http://elrayescampaign.blogspot.com/2016/06/mcp2221-tutorial-easy-usb-interfacing.html
