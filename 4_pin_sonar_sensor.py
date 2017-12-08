#read the readme.txt file
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
timeout = 0.020
#attach sonar sensor's Vcc pin at 3.3V(recommended) or at 5V(with voltage divider from signal of 3.3V) of RaspberryPi,  GND pin at RaspberryPi, trigger pin at GPIO4(pin 7), echo pin at GPIO27(pin 13) 
tpin = 7 # named pin7 as tpin
epin = 13 # named pin13 as epin
while 1:
        GPIO.setup(tpin, GPIO.OUT)
	GPIO.setup(epin, GPIO.IN)
        #cleanup output
        GPIO.output(tpin, 0)

        time.sleep(0.000002)

        #send signal
        GPIO.output(tpin, 1)

        time.sleep(0.000005) #change 5 microseconds delay to the timerequired by your sensor's trigger pin to send a pulse

        GPIO.output(tpin, 0)

        goodread=True
        watchtime=time.time()
        while GPIO.input(epin)==0 and goodread:
                starttime=time.time()
                if (starttime-watchtime > timeout):
                        goodread=False

        if goodread:
                watchtime=time.time()
                while GPIO.input(epin)==1 and goodread:
                        endtime=time.time()
                        if (endtime-watchtime > timeout):
                                goodread=False
        
        if goodread:
                duration=endtime-starttime
                distance=duration*34000/2
                print distance
