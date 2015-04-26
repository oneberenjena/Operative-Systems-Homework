#include "listapreg.h"


void printList(LISTA *l){

do
{
	printf("%d %d %s %s %s %s %s %d\n",l->code, l->level, l->area, l->question, l->ans1, l->ans2, l->ans3, l->trueAns);
	l = l->next;
} while (l != NULL);

}

void printByLevel(LISTA *l, int level){

	int count = 0;
	while (l != NULL){
		if(l->level == level){
			printf("%s\n", l->question);
			count++;
		}
		l = l->next;
	}

	if (count == 0)
		printf("No hay preguntas con el nivel solicitado.\n");
}

void deleteQuestion(LISTA *l,int code){

	LISTA *tmp;
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

int sizeofList(LISTA *l){

	int size = 0;
	
	do
	{
		l = l->next;
		size++;		
	} while (l != NULL);

	return size;
}
