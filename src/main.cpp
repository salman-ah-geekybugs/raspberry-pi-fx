#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
// Pin connected to the LED
const uint8_t ledPin = PICO_DEFAULT_LED_PIN;
uint16_t count;

void concatIntAndFloat(uint16_t integer, float floatingPoint, char *result)
{
  sprintf(result, "%d, %.2f\n", integer, floatingPoint);
}

void setup()
{
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  count = 0;
  printf("running the setup");
}

void loop()
{
  if (!Serial.available())
  {
    return;
  }

  if (count < 1000)
  {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    char some_data[30];
    sprintf(some_data, "count %d\n", count);
    Serial.print(some_data);
    char output[20];

    float y = 5 * sin(10 * count); // test sine wave

    concatIntAndFloat(count, y, output);
    Serial.write(output);
    count += 100;
    memset(output, 0, sizeof(output));
    Serial.flush();
    // Wait for 1 second
    delay(800);

    // Turn off the LED
    digitalWrite(ledPin, LOW);

    // Wait for 1 second
    delay(200);
  }
}
