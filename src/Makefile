CC=gcc
CFLAGS=-Wall
LIBS=-lwiringPi
EXECUTABLE=semaforo

.DEFAULT_GOAL := semaforo

semaforo: semaforo.c
	$(CC) $(CFLAGS) -o $(EXECUTABLE) semaforo.c $(LIBS) 

clean: 
	@rm -f $(EXECUTABLE)