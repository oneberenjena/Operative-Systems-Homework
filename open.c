#include <stdio.h>
#include <stdlib.h>
#include "listapreg.h"
#include <string.h>

FILE *fp;
char entero[500];
char linea[450];
char *linea2[1][5];
LISTA *first;
LISTA *listapreg;

void main(){
	fp = fopen("entrada.txt", "r");

	if (fp == NULL)
		perror("fopen: ");

	int i = 0, j = 0, counter = 0;

	while ((fscanf(fp, "%c", &entero)) != EOF){

		while (entero[0] != '\n'){
			linea[i] = entero[0];
 			i++;
 			break;
 		}
 		/*
 		 *	Una vez haya terminado de leer una linea, se empieza
 		 *	a tokenizar el string y empezamos a crear la lista
 		 *	enlazada
 		 */
 		if (entero[0] == '\n'){

 			char *token;
 			token = strtok(linea, "\"");
 			char *strArr[6];
 			int p = 0, count = 0;

 			/* Primero tokenizamos la linea entera y guardamos en un arreglo 
 				cada pedazo del string. Cada pedazo es (1) un string que 
 				engloba codigo, nivel y area, (2) la pregunta, (3, 4 y 5) 
 				las respuestas posibles y (6) la respuesta correcta como un 
 				solo caracter.
 			*/
 			while (token != NULL ){
 				if (count % 2 != 0 || count == 8 || count == 0){ 
 					strArr[p] = token;
 					p++;
 				}

 				token = strtok(NULL, "\"");
 				count++;
 			}

 			/*
 				A partir de aqui se crearan las listas, hay casos dado que
 				es necesario crear primero una lista apuntada por 'first'
 				que sera nuestra guia para recorrer la lista enlazada
 				apuntando a la primera lista, el segundo ingresado que
 				sera apuntado por first->next y las demas cajas insertadas
 			 */
 			if (counter == 0){

 				// PARA LA CREACION DE LA PRIMERA CAJA
 				first = (LISTA *)malloc(sizeof(LISTA));
 				token = strtok(strArr[0], " ");
 				int atCount = 0, m = 0;

 				// Se pasan los atributos codigo, nivel y area
 				while ( token != NULL){
					if (atCount == 0)
						first->code = atoi(token);

					if (atCount == 1)
						first->level = atoi(token);

					if (atCount == 2)
						first->area = token;

 					token = strtok(NULL, " ");
 					atCount++;
 				}

 				// Se pasan los atributos de pregunta y respuestas
 				strcpy(first->question,strArr[1]);
 				strcpy(first->ans1,strArr[2]);
 				strcpy(first->ans2,strArr[3]);
 				strcpy(first->ans3,strArr[4]);

 				// Se pasa el atributo de respuesta correcta
 				token = strtok(strArr[5], " ");
 				first->trueAns = atoi(token);

 				// first es el ultimo de la lista
 				first->next = NULL;
 				
 				printf("El code %d\n", first->code);
 				printf("El level %d\n", first->level);
 				printf("El area %s\n", first->area);
 				printf("La question %s\n", first->question);
 				printf("La ans1 %s\n", first->ans1);
 				printf("La ans2 %s\n", first->ans2);
 				printf("La ans3 %s\n", first->ans3);
 				printf("La real %d\n", first->trueAns);

 				break;						
 			}
 			//memset(linea, 0, 450);
 			i = 0;
		}		
			
 		

 	
	}
	fclose(fp);
}
