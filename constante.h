//include

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <pthread.h>
#include <semaphore.h>

#include <time.h>
#include <string.h>

//constante
	///ERREUR
		#define VIDE 2 //si un fichier est vide

	///operateur
		#define MIN 1
		#define MAX 2
		#define AVG 3
		#define SUM 4
		#define ODD 5
