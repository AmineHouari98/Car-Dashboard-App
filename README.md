# CarDashboard

car dashboard is a crossplatform application ( android / ios / windows / linux / max ) that monitor current data recieved from OBD2 ( ELM327 ) in real time 

![](https://github.com/AmineHouari98/CarDashboard_licence_usto_2018/blob/master/cardashboard-GIF.gif)

# Current Status

    + [X] reads standard PIDS (tried on a ford fiesta 2013 if a pid is not supported by your car you can modify it in the serial.cpp file (line 691) and bluetoothmodule.cpp (line 701)
    + [X] sends data and gps position (android/ios only) to a distant server
    
# TODO
- QML & C++
    + [ ] add custom chart
    + [ ] change the UI to a more ergonomic one
    + [ ] dynamic standard PIDS reading
    + [ ] acces data on the distant server
    + [ ] multiple clients on the server in real time
    

# How to use it
----------------
For windows

1- connect your pc to the bluetooth OBD-II
2- start the application if you don't have any input change the COM port in the handler.cpp file

For Android

1- start the app
2- go in the settings and click on "connect bluetooth"

# License & copyright

(c) Houari Amine amine.houari@outlook.com .

(c) Remmache Mohammed Amine amine.med.remmache@gmail.com

Licensed under the [GPL License](LICENSE).
