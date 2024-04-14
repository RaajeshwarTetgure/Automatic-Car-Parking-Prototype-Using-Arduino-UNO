# Automatic-Car-Parking-Prototype-Using-Arduino-UNO
A parking plot has a certain capacity of cars. Number of empty spots should be displayed on the display outside the Parking Plot and the spots available is to be indicated.

<b> OBJECTIVE: </b>

To create a car parking system using an Arduino microcontroller board, an I2C 20x4 LCD display, a SG90 servo motor, and an IR sensor. The parking system will help automate the process of parking a car by providing real-time information and guiding the driver through the parking space.

<b> COMPONENTS USED: </b>

•
Arduino Uno

•
IR Sensor

•
20×4 LCD Display with I2C

•
Servo Motor SG90

•
Jumper Wires

•
Single strand wires

•
Breadboard




<b> WORKING PRINCIPLE: </b>


•
When a vehicle enters a parking space, the IR sensor detects the change in infrared reflection and sends this information to the Arduino Uno.

•
The Arduino processes the sensor data and updates the count of available parking spaces. It then sends this count to the LCD Display using the I2C interface.

•
The LCD Display shows the current count of empty parking spots in real-time, allowing drivers to quickly identify available spaces.

•
The SG90 servo motor is responsible for controlling the barrier or gate at the entrance and exit of the parking lot. The Arduino sends commands to the servo motor based on inputs from the IR sensor to open and close the gate during the entry and exit of vehicles.

•
As vehicles enter and exit the parking area, the system continuously updates the display and servo motor opens and closes the gate.

![Prototype Img 3](https://github.com/RaajeshwarTetgure/Automatic-Car-Parking-Prototype-Using-Arduino-UNO/assets/106911654/4de38ab7-4f70-4386-8c17-d931c1243d2a)


