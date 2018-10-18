#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void* hilo1(void* args) {
	char *msg = "Hola";
	int i;
	int aleatorio;
	for(i = 0; i < strlen(msg); i++) {
		printf("%c", msg[i]);
		fflush(stdout);
		aleatorio = rand();
		sleep(1 + (aleatorio % 5));
	}
	return NULL;
}
void* hilo2(void* args) {
	char *msg = "mundo";
	int i;
	int aleatorio;
	for (i = 0; i < strlen(msg); i++) {
		printf("%c", msg[i]);
		fflush(stdout);
		aleatorio = rand();
		sleep(1 + (aleatorio % 5));
	}
	return NULL;
}
int main(int argc, char *argv[]) {
	srand((unsigned) time(NULL));
	pthread_t h1;
	pthread_t h2;

	pthread_create(&h1, NULL, hilo1, NULL);
	pthread_create(&h2, NULL, hilo2, NULL);
	pthread_join(h1 , NULL);
	pthread_join(h2 , NULL);
	printf("Fin\n");
}
