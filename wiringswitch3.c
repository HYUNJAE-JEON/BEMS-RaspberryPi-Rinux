#include <wiringPi.h>
#include <stdio.h>

#define SW1 12
#define SW2 13
#define SW3 14
#define LED1 27
#define LED2 28
#define LED3 29

int switchControl()
{
	int i;

	pinMode(SW1, INPUT);
	pinMode(LED1, OUTPUT);
	pinMode(SW2, INPUT);
	pinMode(LED2, OUTPUT);
	pinMode(SW3, INPUT);
	pinMode(LED3, OUTPUT);

	for (;;) {
		if(digitalRead(SW1)==LOW) {
			digitalWrite(LED1, HIGH);
			delay(1000);
			digitalWrite(LED1, LOW);
		}		
		if(digitalRead(SW2)==LOW) {
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
		}
		if(digitalRead(SW3)==LOW) {
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
		}
		delay(10);
	}
	return 0;
}

/*int switchControl2()
{
	int i;

	pinMode(SW2, INPUT);
	pinMode(LED2, OUTPUT);

	for (;;) {
		if(digitalRead(SW2)==LOW) {
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
		}
		delay(10);
	}
	return 0;
}


int switchControl3()
{
	int i;

	pinMode(SW3, INPUT);
	pinMode(LED3, OUTPUT);

	for (;;) {
		if(digitalRead(SW3)==LOW) {
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
		}
		delay(10);
	}
	return 0;
}

*/
int main(int argc, char **argv)
{
	wiringPiSetup();
	switchControl();
	return 0;
}

