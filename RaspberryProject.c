#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define LED 1
#define LEDW 6
#define LEDY 26
#define LEDR 28
#define LEDRR 24
#define LEDWW 2
#define LEDGG 5

#define pinPir 4

int emergency()
{

	pinMode(pinPir, INPUT);
	pinMode(LED, OUTPUT);
	pinMode(LEDW, OUTPUT);
	pinMode(LEDY, OUTPUT);
	pinMode(LEDR, OUTPUT);
	pinMode(LEDRR, OUTPUT);
	pinMode(LEDWW, OUTPUT);
	pinMode(LEDGG, OUTPUT);


	int count = 0;

	for(;;){
	
	
	if(digitalRead(pinPir) == HIGH && count == 0) {
			digitalWrite(LED,HIGH);
			delay(5000);
			digitalWrite(LED, LOW);
			count++;		
			
			}		

		if(digitalRead(pinPir) == HIGH && count <=2) {
						
			digitalWrite(LEDW, HIGH);
			delay(1000);
			count++;
		}
		if(digitalRead(pinPir) == HIGH && count <=4 && count >2) {
			digitalWrite(LEDW, LOW);
			digitalWrite(LEDY, HIGH);
			delay(1000);
			count++;
		}
		if(digitalRead(pinPir) == HIGH && count <=6 && count >4) {
			digitalWrite(LEDW, LOW);
			digitalWrite(LEDY, LOW);
			digitalWrite(LEDR, HIGH);			
			delay(1000);			
			count++;
		}
		if(digitalRead(pinPir) == HIGH && count >=8)
		{
			digitalWrite(LEDW, LOW);
			digitalWrite(LEDY, LOW);
			digitalWrite(LEDR, LOW);
			delay(1000);		
			count++;
		}	 
			digitalWrite(LEDW, LOW);
			digitalWrite(LEDY, LOW);
			digitalWrite(LEDR, LOW);
			digitalWrite(LED, LOW);

			digitalWrite(LEDRR. HIGH);
			delay(1000);
			digitalWrite(LEDGG. HIGH);
			digitalWrite(LEDRR. LOW);
			delay(1000);
			digitalWrite(LEDRR. HIGH);
			digitalWrite(LEDWW. HIGH);
			digitalWrite(LEDGG. LOW);
			delay(1000);
			digitalWrite(LEDRR. HIGH);
			delay(1000);
			digitalWrite(LEDGG. HIGH);
			digitalWrite(LEDRR. LOW);
			delay(1000);
			digitalWrite(LEDRR. HIGH);
			digitalWrite(LEDWW. HIGH);
			digitalWrite(LEDGG. LOW);
			delay(1000);
			digitalWrite(LEDRR. HIGH);
			delay(1000);
			digitalWrite(LEDGG. HIGH);
			digitalWrite(LEDRR. LOW);
			delay(1000);
			digitalWrite(LEDRR. HIGH);
			digitalWrite(LEDWW. HIGH);
			digitalWrite(LEDGG. LOW);
			delay(1000);


}





	return 0;
}


	
/*


int ledControl(int gpio)
{
	int i;

	pinMode(gpio, OUTPUT);

	for (i = 0; i < 5; i++) {
		digitalWrite(gpio, HIGH);
		delay(1000);
		digitalWrite(gpio, LOW);
		delay(1000);
		}
	return 0;
}

int main(int argc, char **argv)
{
	int gno;
	

	if(argc <2) {
		printf("Usage : %s GPIO_NO\n", argv[0]);
		return -1;
	}
	gno = atoi(argv[1]);
	
	wiringPiSetup();
	ledControl(gno);
	
	return 0;
}

*/

int main()
{
	wiringPiSetup();
	emergency();
	return 0;
}

