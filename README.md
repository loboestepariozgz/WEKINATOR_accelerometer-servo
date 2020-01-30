///1. ESPIGA-ESP12E (3 SERVO GIMBAL)
///&
///2. HandTool-ESP32 (HAMMER WITH ACCELEROMETER AND GYROSCOPE)

First file its for an esp 8266 wifi arduino module and second its for an esp32 arduino module.

ESPIGA-ESP12E one send the MPU 6050 accelerometer gyroscope detector to wekinator, then wekinator classifies this movements into 6 differents states that are send to the second wifi-arduino module with the Handtool-esp32, that translate them into servo movements.

I change the default message to make it easier to understand.



HAMMER+MPU6050+esp12e: OSC --------> WEKINATOR: OSC--------->SERVOSGIMBAL+esp32

IMPORTANT NOTES:

1. I needed to choose diferent type wifi modules because of the good/bad behaviour with the servos.

2. Choose your own SSID and pasword, note that not all wifi routers will allow this comunications.

3. I did not use default messages for wekinator inputs outputs, use your owns (also ports)


# WEKINATOR_accelerometer-servo
A Wekinator project where we take MPU6050 data send it to Wekinator "translate it" and resend it to a servo motorized sculpture


