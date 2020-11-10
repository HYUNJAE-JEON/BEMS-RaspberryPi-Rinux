import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(25, GPIO.IN)
try:
    
        while True:
            if GPIO.input(25)==True:
                print("Sensor On!!")
                GPIO.output(18, True)
                time.sleep(0.2)
            if GPIO.input(25)==False:
                print("Sensor Off!!")
                GPIO.output(18, False)
except KeyboardInterrupt:
    GPIO.cleanup()
    