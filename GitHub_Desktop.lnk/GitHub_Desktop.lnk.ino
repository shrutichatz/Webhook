// -----------------------------------------------------------------
// Function and Variable with photo sensors (resistor or transistor)
// -----------------------------------------------------------------
// In this example, we're going to register a Particle.variable() with the cloud so that we can read brightness levels from the photoresistor or phototransistor.
// We'll also register a Particle.function so that we can turn the LED on and off remotely.

// We're going to start by declaring which pins everything is plugged into.

int led = D6; // This is where your LED is plugged in. The other side goes to a resistor connected to GND.

int photosensor = A0; // This is where your photoresistor or phototransistor is plugged in. The other side goes to the "power" pin (below).

int analogvalue; // Here we are declaring the integer variable analogvalue, which we will use later to store the value of the photoresistor or phototransistor.



// Next we go into the setup function.

void setup() {
  // This is here to allow for debugging using the USB serial port
  Serial.begin();

  // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.
  pinMode(led, OUTPUT); // Our LED pin is output (lighting up the LED)
  digitalWrite(led, HIGH);

  // We are going to declare a Particle.variable() here so that we can access the value of the photosensor from the cloud.
  Particle.variable("analogvalue", &analogvalue, INT);
  // This is saying that when we ask the cloud for "analogvalue", this will reference the variable analogvalue in this app, which is an integer variable.

  
}


// Next is the loop function...


void loop() 
{

    

  analogvalue = analogRead(photosensor);
  Serial.printlnf("%d", analogvalue);
  Particle.publish("light", String(analogvalue), PRIVATE);
  
  digitalWrite(led, HIGH);   // Turn ON the LED
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 second
  
  
   
    

}




