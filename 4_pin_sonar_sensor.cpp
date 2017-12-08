//read the readme.txt file
#include <iostream>
#include <wiringPi.h>


using namespace std;
//attach sonar sensor's Vcc pin at 3.3V(recommended) or at 5V of RaspberryPi,  GND pin at RaspberryPi, trigger pin at GPIO4(pin 7), echo pin at GPIO27(pin 13)

int main(void){
        wiringPiSetup();
        unsigned int timeout = 20000;
        int tpin = 7; //trigger pin
	int epin = 13; //echo pin
        while(1){

		unsigned long int starttime, endtime;
                pinMode( tpin, OUTPUT );
		pinMode( epin, INPUT );
                digitalWrite( tpin, 0 );
                delayMicroseconds( 2 );
                digitalWrite( tpin, 1 );
                delayMicroseconds( 5 );
                digitalWrite( tpin, 0 );
                bool goodread= true;
                unsigned long int watchtime= micros();

                while(digitalRead(epin)==0 && goodread){
                        starttime= micros();
                        if(starttime-watchtime > timeout){
                                goodread= false;
	                }
                }
                if(goodread){
                        watchtime=micros();
                        while(digitalRead(epin) && goodread){
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

