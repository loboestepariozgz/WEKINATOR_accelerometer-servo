
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
//COSASWIFIS
char ssid[] = "TP-Link_9468";          // your network SSID (name)
char pass[] = "99836092";                    // your network password

WiFiUDP Udp; // A UDP instance to let us send and receive packets over UDP
const IPAddress outIp(172,10,20,11);     // remote IP (not needed for receive)
const unsigned int outPort = 9999;          // remote port (not needed for receive)
const unsigned int localPort = 12000;       // local port to listen for UDP packets (here's where we send the packets)
OSCErrorCode error;


//ESTADOS
const int recivoA = 1;
const int recivoB = 2;
const int recivoC = 3;
const int recivoD = 4;
const int recivoE = 0;
int pos = 0;
int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2;


//VARIABLES
int estado;
float estadof;




void setup() {
  Serial.begin(115200);

  //Givememywififirstwarn
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif
 // ServosOnfireBitch
 /*servo1.attach(2); //D4
 servo2.attach(1); //D4*/
  

}

void recallestados(OSCMessage &msg) {
  estadof = msg.getFloat(0);
  estado = int(estadof);
  Serial.print("/wekiout: ");
  Serial.println(estadof);

}

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/wekiout", recallestados);
      controlarServos();
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}

void controlarServos() {
  
  switch (estado){
    case recivoA:
      ejecutoA();
      Serial.println("EjecutoA");
      break;

    case recivoB:
      ejecutoB();
      Serial.println("EjecutoB");
      break;

    case recivoC:
      ejecutoC();
      Serial.println("EjecutoC");
      break;

    case recivoD:
      ejecutoD();
      Serial.println("EjecutoD");
      break;

    case recivoE:
      ejecutoE();
      Serial.println("EjecutoE");
      break;
  }
  delay(1);
}
void ejecutoA() {
   Serial.println("muevoA");
 
 int a1=90;
 int a2=90;
   servo1.attach(2); //D4
 servo2.attach(1); //D4
  servo1.write(a1);
  servo2.write(a2);
  delay(50);
    
}
void ejecutoB() {
   Serial.println("muevoB");
   int b1 = 135;
   int b2= 90;
 servo1.attach(2); //D4
 servo2.attach(1); //D4
  servo1.write(b1);
  servo2.write(b2);
    delay(50);
    


}

void ejecutoC() {
 Serial.println("muevoC");
    servo1.attach(2); //D4
 servo2.attach(1); //D4
servo1.write(c1);
  servo2.write(c2);
    delay(50);}
   
void ejecutoD() {
   Serial.println("muevoD");
    servo1.attach(2); //D4
 servo2.attach(1); //D4

  servo1.write(0);
  servo2.write(90);
    delay(50);

}
void ejecutoE() {
   Serial.println("muevoE");
   servo1.attach(2); //D4
 servo2.attach(1); //D4
  servo1.write(0);
  servo2.write(0);
    delay(50);

}
