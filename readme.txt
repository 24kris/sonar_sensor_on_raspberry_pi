I have tested my python and c++ codes for 3 pin Sonar Sensor TS601-01 and they give very good accuracy for distance in centimeters for range in 2cm to 300cm.

_____________________________________________________

FOR PYTHON CODE

For using most of the 3 pin or 4 pin sonar sensor with Python code on RaspberryPi 
Install Python Module RPi.GPIO
The RPi.GPIO python module offers easy access to the general purpose IO pins on the Raspberry Pi.
To get the latest version of this, you can take a little diversion to follow the instructions in Adafruit's Raspberry Pi Lesson 4. GPIO Setup.
If you're comfortable, you can probably skip the lesson above and issue the following command in a terminal window:

sudo apt-get install python-dev python-rpi.gpio


Then run the code on your RPi :)

______________________________________________________________________________

FOR C++ CODE

For using most of the 3 pin or 4 pin sonar sensor with C++ code on RaspberryPi 

first Download and Install WiringPi, see here: http://wiringpi.com/download-and-install/
Then write the code on your RPi.
While compiling your file you need to link the wiringPi library by using:

g++ fiename.cpp -o filename -lwiringPi

and run it by:

./filename

ENJOY :)

======================================================================================


