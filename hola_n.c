#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAXTHREAD 257

void * imprimir (void* x )
{
	pthread_t id ; 
	id =  pthread_self(); 
	
	printf("hola %u \n", id ); 
}



int main (int argc , char ** argv )
{
	//long array[MAXTHREAD];
	pthread_t threadArray[MAXTHREAD] ; 
	int numHilos; 

	if (argc != 2)
	{
		printf("Por favor digite un numero hilos a usar\n");
		printf("\t%s <numhilos>\n",argv[0]);
		exit(-1);

	}

	numHilos = atoi(argv[1]);
	
	if (numHilos > MAXTHREAD || numHilos == 0 )
	{
		printf("Máximo número de hilos es %d, solicitó: %d \n" , MAXTHREAD, numHilos);
		exit(-1); 

	}


	for (int i = 0 ; i < numHilos ; i++)
	{
	//	array[i] = (long) i; 
		pthread_create(&threadArray[i]  , NULL,& imprimir,NULL) ;
		
		
	}

	for (int  i = 0; i < numHilos;  i++) 
	{
		pthread_join (threadArray [i] , NULL); 
		
	}



	
	return 0; 
}
