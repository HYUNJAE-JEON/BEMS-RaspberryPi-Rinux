#include <wiringPi.h>
#include <stdio.h>

#define SW 12
#define CDS 0
#define LED 27

int cdsControl()
{
	int i;

	pinMode(SW, INPUT);
	pinMode(CDS, INPUT);
	pinMode(LED, OUTPUT);

	for(;;) {
		if(digitalRead(CDS)==LOW){
			digitalWrite(LED, HIGH);
			delay(1000);
			digitalWrite(LED, LOW);
		}
	}
	return 0;
}

int main()
{
	wiringPiSetup();
	cdsControl();
	return 0;
}

