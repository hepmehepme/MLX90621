/*
* A class for interfacing the Melexis 90621 Sensor 
* 2013 by Felix Bonowski
* Based on a forum post by maxbot: http://forum.arduino.cc/index.php/topic,126244.msg949212.html#msg949212
* This code is in the public domain.
*


#include "MLX90621.h"

MLX90621 sensor; // create an instance of the Sensor class

void setup(){ 
  Serial.begin(19200);
  Serial.println("trying to initialize sensor...");
  sensor.initialise (16); // start the thermo cam with 8 frames per second
  Serial.println("sensor initialized!");
}
void loop(){
  sensor.measure(); //get new readings from the sensor
  for(int y=0;y<4;y++){ //go through all the rows
    Serial.print("[");
    
    for(int x=0;x<16;x++){ //go through all the columns
      double tempAtXY= sensor.getTemperature(y+x*4); // extract the temperature at position x/y
      Serial.print(tempAtXY);
         
      if (x<15) Serial.print(",");
    }
    Serial.print("]");
    if (y<3)Serial.print("~"); 
  }
  Serial.print("\n");
  delay(31);
};



