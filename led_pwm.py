import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

pwm = GPIO.PWM(18, 5000)
pwm.start(0)

a = 0
while a < 100:
    pwm.ChangeDutyCycle(a)
    a=a+1
    time.sleep(0.1)
GPIO.cleanup()
pwm.stop()