#include "constante.h"

//Utiliser atof(chaine) pour convertir une chaine de caractère (char* chaine) en flottant

typedef struct donnee{
	int fichier;
	int nombre;
	int first;
	float valeur;
}DONNEE;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* Min(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	
	pthread_mutex_lock(&mutex);
	int i=0;
	
	read(f->fichier,tbuf,1);
	
	if(f->first)
	{//Bloc pour initialiser la varibale min
		char* buf = (char*)malloc(sizeof(char));
		while(*tbuf!='\n'){
			buf=strcat(buf,tbuf);
			read(f->fichier,tbuf,1);
		}
			f->valeur=atof(buf);
		read(f->fichier,tbuf,1);
		free(buf);
		
		i=1;
		
		f->first=0;
	}
	
	while(i<f->nombre && *tbuf!='\0')
	{
		char* buf = (char*)malloc(sizeof(char));
		while(*tbuf!='\n' && *tbuf!='\0'){
			buf=strcat(buf,tbuf);
			read(f->fichier,tbuf,1);
		}
		if((f->valeur)>atof(buf))
			f->valeur =atof(buf);
		read(f->fichier,tbuf,1);
		free(buf);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
	
}
