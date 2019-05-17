# CarDashboard

car dashboard is a crossplatform application ( android / ios / windows / linux / max ) that monitor current data recieved from OBD2 ( ELM327 ) in real time , the data retreived can be shared via a server app (https://github.com/AmineHouari98/birdge-licence-usto-2018) ,this app worsk as imiter/receiver depending on the which client is connected to the OBD-II 

![](https://github.com/AmineHouari98/CarDashboard_licence_usto_2018/blob/master/cardashboard-GIF.gif)

# Current Status

- C++ :
    + [X] reads standard PIDS 
    + [X] sends data and gps position (android/ios only) to a distant server
    
# TODO
- QML & C++
    + [ ] add custom chart
    + [ ] change the UI to a more ergonomic one
    + [ ] dynamic standard PIDS reading
    + [ ] acces data on the distant server
    + [ ] multiple clients on the server in real time
    

# Note

this app has been tested on a ford fiesta 2013 if a pid is not supported by your car you can modify it in the serial.cpp file (line 691) and bluetoothmodule.cpp (line 701)


# How to use it
----------------
For windows :

1- connect your pc to the bluetooth OBD-II

2- start the application if you don't have any input change the COM port in the handler.cpp file

For Android :

1- start the app

2- go in the settings and click on "connect bluetooth"

Distant Server :

1- compile and run this project : https://github.com/AmineHouari98/birdge-licence-usto-2018

2- go on settings in the app

3- enter the port and ip address of the server in the "server section" and click connect

4-do the same thing in the receiver side

# License & copyright

(c) Houari Amine amine.houari@outlook.com .

(c) Remmache Mohammed Amine amine.med.remmache@gmail.com

Licensed under the [GPL License](LICENSE).
