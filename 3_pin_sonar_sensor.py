#read the readme.txt file
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
timeout = 0.020
#attach sonar sensor's Vcc pin at 3.3V(recommended) or at 5V of RaspberryPi,  GND pin at RaspberryPi, signal pin at GPIO4(pin 7) 
spin=7 # named pin7 as spin
while 1:
        GPIO.setup(spin, GPIO.OUT)
        #cleanup output
        GPIO.output(spin, 0)

        time.sleep(0.000002)

        #send signal
        GPIO.output(spin, 1)

        time.sleep(0.000005)  #change 5 microseconds delay to the timerequired by your sensor's trigger pin to send a pulse

        GPIO.output(spin, 0)

        GPIO.setup(spin, GPIO.IN)
        
        goodread=True
        watchtime=time.time()
        while GPIO.input(spin)==0 and goodread:
                starttime=time.time()
                if (starttime-watchtime > timeout):
                        goodread=False

        if goodread:
                watchtime=time.time()
                while GPIO.input(spin)==1 and goodread:
                        endtime=time.time()
                        if (endtime-watchtime > timeout):
                                goodread=False
        
        if goodread:
                duration=endtime-starttime
                distance=duration*34000/2
                print distance
