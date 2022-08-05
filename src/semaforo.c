#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define SEMAFORO_1_VERDE               23  // RPi GPIO 1
#define SEMAFORO_1_AMARELO             39  // RPi GPIO 26
#define SEMAFORO_1_VERMELHO            34  // RPi GPIO 21
#define SEMAFORO_2_VERDE               35  // RPi GPIO 20
#define SEMAFORO_2_AMARELO             32  // RPi GPIO 16
#define SEMAFORO_2_VERMELHO            33  // RPi GPIO 12
#define BOTAO_PEDESTRE_1               21  // RPi GPIO 8
#define BOTAO_PEDESTRE_2               22  // RPi GPIO 7
#define SENSOR_PASSAGEM_1              15  // RPi GPIO 14
#define SENSOR_PASSAGEM_2               2  // RPi GPIO 15
#define SENSOR_VELOCIDADE_1_A           4  // RPi GPIO 18
#define SENSOR_VELOCIDADE_1_B           5  // RPi GPIO 23
#define SENSOR_VELOCIDADE_2_A          18  // RPi GPIO 24
#define SENSOR_VELOCIDADE_2_B          19  // RPi GPIO 25




static void apagarLuzes();
static void interruptHandler(const int);

static void apagarLuzes() {
	digitalWrite(SEMAFORO_1_VERMELHO, LOW);
	digitalWrite(SEMAFORO_1_AMARELO, LOW);
	digitalWrite(SEMAFORO_1_VERDE, LOW);
    digitalWrite(SEMAFORO_2_VERMELHO, LOW);
	digitalWrite(SEMAFORO_2_AMARELO, LOW);
	digitalWrite(SEMAFORO_2_VERDE, LOW);
    printf("apagar todas as luzes!\n");
}

static void interruptHandler(const int signal) {
	apagarLuzes();
	exit(0);
}

int main(void) {
	signal(SIGINT, interruptHandler);

	if (-1 == wiringPiSetup()) {
		printf("Falha na Wiring Pi!\n");
		return 1;
	}

	pinMode(SEMAFORO_1_VERMELHO, OUTPUT);
	pinMode(SEMAFORO_1_AMARELO, OUTPUT);
	pinMode(SEMAFORO_1_VERDE, OUTPUT);

    pinMode(SEMAFORO_2_VERMELHO, OUTPUT);
	pinMode(SEMAFORO_2_AMARELO, OUTPUT);
	pinMode(SEMAFORO_2_VERDE, OUTPUT);

	apagarLuzes();

	while(1) {
		// Red
		digitalWrite(SEMAFORO_1_VERMELHO, HIGH);
		delay(3000);

		/* // Red and Yellow
		digitalWrite(SEMAFORO_1_AMARELO, HIGH);
		delay(1000); */

		// verde 1
		digitalWrite(SEMAFORO_1_VERMELHO , LOW);
		digitalWrite(SEMAFORO_1_AMARELO  , LOW);
		digitalWrite(SEMAFORO_1_VERDE    , HIGH);
        delay(5000);
         printf("Semaforo 1!\n");
        
		// vermelho 2
        digitalWrite(SEMAFORO_2_VERMELHO , HIGH);
		digitalWrite(SEMAFORO_2_AMARELO  , LOW);
		digitalWrite(SEMAFORO_2_VERDE    , LOW);
		delay(5000);
         printf("Semaforo 2!\n");

		// amarelo
		digitalWrite(SEMAFORO_1_VERDE   , LOW);
		digitalWrite(SEMAFORO_1_AMARELO , HIGH);
		delay(2000);

		// Yellow off
		digitalWrite(SEMAFORO_1_AMARELO, LOW);
        
	}

	return 0;
}