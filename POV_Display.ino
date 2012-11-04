//============================================================
// POV Display using Arduino Uno
//
// Author: Karan Thakkar
// Last Modified: June 6, 2012
//
// Description:   Code for POV Display using 8 LED's
//		  See http://karanjthakar.wordpress.com
//		  for more details.
//============================================================

int pins[] = {2,3,4,5,6,7,8,9};	// an array of pin numbers
int rows= 8;		        // Total LED's in a row

//data corresponding to the each alphabet and a few characters to be displayed
byte N[]={B11111111,B00000110,B00001100,B00011000,B00110000,B01100000,B11000000,B11111111};
byte E[]={B00000000,B11111111,B11011011,B11011011,B11011011,B11011011,B11000011,B11000011};
byte H[]={B11111111,B11111111,B00011000,B00011000,B00011000,B00011000,B11111111,B11111111}; 
byte A[]={B00000111,B00001100,B00111000,B11001000,B11001000,B00111000,B00001100,B00000111};
byte K[]={B10000001,B10000001,B11000011,B01100110,B00111100,B00011000,B11111111,B11111111};
byte R[]={B00000001,B01000011,B11100110,B10101100,B10111000,B10110000,B11111111,B11111111};
byte L[]={B00000000,B11111111,B11111111,B00000011,B00000011,B00000011,B00000011,B00000011};
byte O[]={B00000000,B11111111,B11111111,B11000011,B11000011,B11000011,B11111111,B11111111};
byte V[]={B00000000,B11100000,B00111000,B00001110,B00000011,B00001110,B00111000,B11100000};
byte I[]={B00000000,B11000011,B11000011,B11000011,B11111111,B11000011,B11000011,B11000011};
byte S[]={B00100010,B01100110,B01000111,B10001001,B10010001,B01010010,B01110110,B00100100};
byte fullstop[]={B00000000,B00000000,B00000000,B00000011,B00000011,B00000000,B00000000,B00000000};
byte comma[]={B00000000,B00000000,B00000000,B00000110,B00000101,B00000000,B00000000,B00000000};
byte heart[]={B00100000,B11111000,B01111110,B00111111,B00111111,B01111110,B11111000,B00100000};


// customizable parameters
int timer1 = 2.2;			        // time between columns
int timer2 = 20;		                // time between frames
int frame_len = 8;		                // frame length

void setup()
{
  int i;
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
  for (i = 0; i < rows; i++)
    pinMode(pins[i], OUTPUT);	// set each pin as an output
}

void loop()
{
  int b=0;
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  delay(timer2);
  show(heart);
  delay(timer2);
  show(N);
  delay(timer2);
  show(A);
  delay(timer2);
  show(R);
  delay(timer2);
  show(A);
  delay(timer2);
  show(K);
  while(digitalRead(10) != 1)
  {
    
  }
}

void show( byte* image )
{
  int a,b,c;
  
  // go through all data for all columns in each frame.
    for (b = 0; b < frame_len; b++)
    {
      for (c = 0; c < rows; c++)
      {
        digitalWrite(pins[c], bitRead(image[b], c));
      }
      delay(timer1);
    }
    for (c = 0; c < rows; c++)
    {
      digitalWrite(pins[c], LOW);
    }
}
