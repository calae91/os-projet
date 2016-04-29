#include "constante.h"
#include "fonction.c"

//Utiliser atof(chaine) pour convertir une chaine de caractère (char* chaine) en flottant

typedef struct donnee{
	int fichier;
	int nombre;
	int first;
	float valeur;
	pthread_mutex_t mutex;
}DONNEE;

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void* min(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	
	pthread_mutex_lock(&f->mutex);
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
	pthread_mutex_unlock(&f->mutex);
	return NULL;
	
}

void* max(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	
	pthread_mutex_lock(&mutex);
	int i=0;
	
	read(f->fichier,tbuf,1);
	
	if(f->first)
	{//Bloc pour initialiser la varibale max
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
		if((f->valeur) < atof(buf))
			f->valeur = atof(buf);
		read(f->fichier,tbuf,1);
		free(buf);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
	
}

void* avg(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	
	pthread_mutex_lock(&mutex);
	int i=0;
	
	read(f->fichier,tbuf,1);
	
	if(f->first)
	{//Bloc pour initialiser la varibale
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
		f->valeur = f->valeur + atof(buf);
		read(f->fichier,tbuf,1);
		free(buf);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;

}

void* sum(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	
	pthread_mutex_lock(&mutex);
	int i=0;
	
	read(f->fichier,tbuf,1);
	
	if(f->first)
	{//Bloc pour initialiser la varibale
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
		f->valeur = f->valeur + atof(buf);
		read(f->fichier,tbuf,1);
		free(buf);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;

}



void* odd(void* arg){
	DONNEE* f = (DONNEE*)arg;
	char* tbuf = malloc(sizeof(char));
	int compteur = 0;
	
	pthread_mutex_lock(&mutex);
	int i=0;
	
	read(f->fichier,tbuf,1);
	
	if(f->first)
	{//Bloc pour initialiser la varibale
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
		
		compteur = compteur + modulof(f->valeur);
		
		
		f->valeur = compteur;
		read(f->fichier,tbuf,1);
		free(buf);
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
	
}


