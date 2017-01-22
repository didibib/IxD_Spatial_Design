#include <Wire.h>
#include <Adafruit_L3GD20.h>

Adafruit_L3GD20 gyro;

void setup()
{
  while (!Serial)
    Serial.begin(9600);

  gyro.begin();

  // Try to initialise and warn if we couldn't detect the chip
  if (!gyro.begin(gyro.L3DS20_RANGE_250DPS))
    //if (!gyro.begin(gyro.L3DS20_RANGE_500DPS))
    //if (!gyro.begin(gyro.L3DS20_RANGE_2000DPS))
  {
    Serial.println("Oops ... unable to initialize the L3GD20. Check your wiring!");
    while (1);
  }
}

void loop()
{
  //we are sending data to unity so wait for the transmission of outgoing serial data to complete.  
  Serial.flush();

  gyro.read();  

  // the gyro is deviating +3 on the x-axis so we add 3
  Serial.print((int)gyro.data.x + 3);

  // in unity we read the serial data per line, but we can split the data
  // we can use any letter or symbol, but here we use a comma.
  Serial.print(","); 

  // the gyro is deviating +7 on the y-axis so we add 7
  Serial.print((int)gyro.data.y + 7);

  Serial.print(",");

  Serial.println((int)gyro.data.z);

  delay(100);
}

