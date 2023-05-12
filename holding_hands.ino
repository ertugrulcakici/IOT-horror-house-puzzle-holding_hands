#include <Arduino.h>

// Define long variables for time
long time1 = 0;
long time2 = 0;
// The setup function runs once when you press reset or power the board
void setup()
{
  // Initialize the serial communication at baud rate 9600
  Serial.begin(9600);

  // Configure pin 7 and 8 as INPUT
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  // Configure pin 9 as OUTPUT
  pinMode(9, OUTPUT);
}

// The loop function runs over and over again forever
void loop()
{
  // Set pin 9 to HIGH
  digitalWrite(9, HIGH);

  // Check if pin 7 and 8 are both LOW
  if (digitalRead(7) == LOW && digitalRead(8) == LOW)
  {
    // If the 'duration' function returns true, execute 'open' function
    if (duration())
    {
      open();
    }
  }
}

// Function to calculate the duration when both pins are LOW
bool duration()
{
  // Reset time1 and time2
  time1 = 0;
  time2 = 0;

  // Variable to store the time difference
  int delta = 0;

  // Infinite loop
  while (1)
  {
    // Check if both pins are LOW
    if (digitalRead(7) == LOW && digitalRead(8) == LOW)
    {
      // If delta is less than 10000, increment it by 300 and wait for 300ms
      if (delta < 10000)
      {
        delta += 300;
        delay(300);
      }
      // If delta has reached 10000, return 1 (true)
      else
      {
        return true;
      }
    }
    // If both pins are not LOW, return 0 (false)
    else
    {
      return false;
    }
  }
}

// open the door
void open()
{
  // Set pin 9 to LOW
  digitalWrite(9, LOW);

  // Wait for 3 seconds (3000ms)
  delay(3000);

  // Set pin 9 back to HIGH
  digitalWrite(9, HIGH);
}
