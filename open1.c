#include <stdio.h>
#include <stdlib.h>
#include "listapreg.h"
#include <string.h>


FILE *fp;
char entero[500];
char linea[450];
char *linea2[1][5];
LISTA *first;
LISTA *last;
LISTA *tmp;
int globalCount = 0;
//void printList(LISTA *l);
void main(){
	
	if (globalCount == 0){

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
 				cada pedazo del string-> Cada pedazo es (1) un string que 
 				engloba codigo, nivel y area, (2) la pregunta, (3, 4 y 5) 
 				las respuestas posibles y (6) la respuesta correcta como un 
 				solo caracter->
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
 				first = (LISTA*)malloc(sizeof(LISTA));
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

				// Se apunta a null el siguiente elemento 				
 				first->next = NULL;

 				last = first;

 				counter++;
 				memset(linea, 0, 450);
 				i = 0;
 				//break;						
 			}
 			
 			else{
 				tmp = malloc(sizeof(LISTA));

 				token = strtok(strArr[0], " ");
 				int atCount = 0, m = 0;

 				// Se pasan los atributos codigo, nivel y area
 				while ( token != NULL){
					if (atCount == 0)
						tmp->code = atoi(token);

					if (atCount == 1)
						tmp->level = atoi(token);

					if (atCount == 2)
						tmp->area = token;

 					token = strtok(NULL, " ");
 					atCount++;
 				}

 				// Se pasan los atributos de pregunta y respuestas
 				strcpy(tmp->question,strArr[1]);
 				strcpy(tmp->ans1,strArr[2]);
 				strcpy(tmp->ans2,strArr[3]);
 				strcpy(tmp->ans3,strArr[4]);

 				// Se pasa el atributo de respuesta correcta
 				token = strtok(strArr[5], " ");
 				tmp->trueAns = atoi(token);

 				// Hacemos que sea el ultimo de la lista y asignamos a null su next
 				tmp->next = NULL;
 				last->next = tmp;
 				last = tmp;

 				counter++;
 				memset(linea, 0, 450);
 				i = 0;
 			}
		}			
	}
	fclose(fp);

	}
	
	globalCount++;
}

void saveState(){

	// Se borra el archivo de entrada existente del disco
	int state;
	state = remove("entrada.txt");

	if( status != 0 )
   {
      printf("No se pudo eliminar el archivo.\n");
      perror("Error");
   }

   // Se crea un archivo con el mismo nombre
   
   FILE *fp;
   LISTA *tmp;
   tmp = first;

   fp = fopen("entrada.txt", "w");

   // Se agregan las preguntas que se encuentran en la base de datos
   while (tmp != NULL){
   		fprintf(fp, "%d %d %s %s %s %s %s %d\n",tmp->code, tmp->tmp->level, tmp->area, tmp->question, tmp->ans1, tmp->ans2, tmp->ans3, tmp->trueAns);
  		tmp = tmp->next;
  }

}
