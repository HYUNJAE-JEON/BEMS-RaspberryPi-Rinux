
#include <wiringPi.h>
#include <stdio.h>

#define MAXTIMINGS 85
#define DHTPIN   26



int dhtVal[5] = { 0, 0, 0, 0, 0 };



void readData()
{
 int laststate = HIGH;
 int counter  = 0;
 int j  = 0, i;
 float f; 
 dhtVal[0] = dhtVal[1] = dhtVal[2] = dhtVal[3] = dhtVal[4] = 0;

 pinMode( DHTPIN, OUTPUT );
 digitalWrite( DHTPIN, LOW );
 delay( 18 );
 
 digitalWrite( DHTPIN, HIGH );
 delayMicroseconds( 40 );
 
 pinMode( DHTPIN, INPUT );

 for ( i = 0; i < MAXTIMINGS; i++ )
 {
  counter = 0;
  while ( digitalRead( DHTPIN ) == laststate )
  {
   counter++;
   delayMicroseconds( 1 );
   if ( counter == 255 )
   {
    break;
   }
  }
  
  laststate = digitalRead( DHTPIN );

  if ( counter == 255 )
   break;

  if ( (i >= 4) && (i % 2 == 0) )
  {
   dhtVal[j / 8] <<= 1;
   if ( counter > 16 )
    dhtVal[j / 8] |= 1;
   j++;
  }
 }

 if ( (j >= 40) &&
      (dhtVal[4] == ( (dhtVal[0] + dhtVal[1] + dhtVal[2] + dhtVal[3]) & 0xFF) ) )
 {
  f = dhtVal[2] * 9. / 5. + 32;
  printf( "Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",
   dhtVal[0], dhtVal[1], dhtVal[2], dhtVal[3], f );
 }else  {
  printf( "Invalid Data! \n" );
 }
 return;
}



int main( void )
{
 printf( "Raspberry Pi wiringPi DHT11 Temperature test program\n" );

 if ( wiringPiSetup() == -1 )
  return -1;

 while ( 1 )
 {
  readData();
  delay( 3000 ); 
 }

 return(0);
}

