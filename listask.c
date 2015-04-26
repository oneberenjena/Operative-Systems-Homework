
#include "listapreg.h"


void printList(){

LISTA *l;
l = first;

do
{
	printf("%d %d %s %s %s %s %s %d\n",l->code, l->level, l->area, l->question, l->ans1, l->ans2, l->ans3, l->trueAns);
	l = l->next;
} while (l != NULL);

}

int printByLevel(int level){

	LISTA *l;
	l = first;

	if (level > 2 || level < 0){
		printf("Nivel de complejidad invalido.\n");
		return 0;
	}


	int count = 0;
	while (l != NULL){
		if(l->level == level){
			count++;
		}
		l = l->next;
	}

	if (count == 0){
		printf("No hay preguntas con el nivel solicitado.\n");
		return 0;
	}

	return 1;
}		

LISTA codeExists(int code)
{
	LISTA *l;
	l = first;
	int count = 0;

	while (l != NULL){
		if(l->code != code){
			l = l->next;
			count++;
		}
		else
			return l;

	return NULL;
}

void deleteQuestion(int code){
	LISTA *l, *tmp;
	l = first;
	int count = 0;
	int tam = sizeofList(first);

	

	while (l != NULL){
		if(l->code != code){
			tmp = l;
			l = l->next;
			count++;
		}

		else{
			if (count == 0){
				tmp = first;
				if (first->next != NULL){
					first = tmp->next;
					tmp->next = NULL;
					
					free(tmp);
					
					
					count++;
					}
			}

			else {
				if(l->next != NULL){
					tmp->next = l->next;
					l->next = NULL;
					free(l);
				}
				
				if (l->next == NULL){
					tmp->next = NULL;
					free(l);
				}

			}
			break;
		}
	}
	if (count == tam)
		printf("Error: El codigo ingresado no se encuentra en la base de datos.\n");
}

int sizeofList(){

	LISTA *l;
	l = first;

	int size = 0;
	
	do
	{
		l = l->next;
		size++;		
	} while (l != NULL);

	return size;
}
