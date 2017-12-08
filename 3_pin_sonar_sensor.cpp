//read the readme.txt file
#include <iostream>
#include <wiringPi.h>


using namespace std;
//attach sonar sensor's Vcc pin at 3.3V(recommended) or at 5V of RaspberryPi,  GND pin at RaspberryPi, signal pin at GPIO4(pin 7)
int main(void){
        wiringPiSetup();
        unsigned int timeout = 20000;
        int pin = 7;

        while(1){

		unsigned long int starttime, endtime;
                pinMode( pin, OUTPUT );
                digitalWrite( pin,0 );
                delayMicroseconds( 2 );
                digitalWrite( pin, 1 );
                delayMicroseconds( 5 );
                digitalWrite( pin, 0 );
                pinMode( pin, INPUT );
                bool goodread= true;
                unsigned long int watchtime= micros();
                while(digitalRead(pin)==0 && goodread){
                        starttime= micros();
                        if(starttime-watchtime > timeout){
                                goodread= false;
	                }
                }
                if(goodread){
                        watchtime=micros();
                        while(digitalRead(pin) && goodread){
                                endtime= micros();
                                if(endtime-watchtime>timeout){
                                        goodread= false;
                                }
                        }
                }

                if(goodread){
                        unsigned int duration= endtime - starttime;
                        float distance= (duration*34.0)/2000.0;
                        cout << distance << endl;
                }
        }
	return 0;
}

