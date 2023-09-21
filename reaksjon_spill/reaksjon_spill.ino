#include <Adafruit_NeoPixel.h>
#define LED_COUNT 32
int LED_PIN = 2;
Adafruit_NeoPixel pixels(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


int button = 5;

unsigned long int buttonTime;
unsigned long int buttonTimeOld = 0;

void setup()
{
  Serial.begin(9600);
  pixels.begin();
  pinMode(button,INPUT);
  pixels.clear();
  pixels.show();
  delay (random(500,5000));
  buttonTimeOld = millis();
 
}

void reaksjon()
{
    if((digitalRead(button)) == LOW)
    {
       for(int i = 0; i < LED_COUNT; i++)
          {
          pixels.setPixelColor(i,255,0,0);
          pixels.show();
          }
    }
    else
    {
        pixels.clear();
        pixels.show();
        buttonTime = millis();
        Serial.print("du brukte ");
        Serial.print(buttonTime-buttonTimeOld);
        Serial.println(" millisekunder");
        delay(5000);
        buttonTimeOld = millis();
    }
}
   

void loop()
{
    reaksjon();
}