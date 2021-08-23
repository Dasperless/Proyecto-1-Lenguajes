#ifndef CLASSROOM_H
#define CLASSROOM_H
typedef struct Classroom
{
	char name[100];
	int capacity;
	struct Classroom *next;
} classroom;

/**
 * @brief Funcion para agregar nuevos nodos de tipo aula.
 * 
 * @param name 		El nombre del aula.
 * @param capacity 	La capacidad del aula.
 * @param head 		La referencia de la cabeza de la lista.
 */

void addClassroom(char *name, int capacity, classroom **head)
{
	classroom *newClassroom = (classroom *)malloc(sizeof(classroom));
	classroom *last = *head;

	strcpy(newClassroom->name,name);
	newClassroom->capacity = capacity;

	if (*head == NULL)
	{
		(*head) = newClassroom;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = newClassroom;
	return;
}

/**
 * @brief Obtiene objetos Classroom por indice.
 * 
 * @param index El indice del aula.
 * @param head 	La cabeza de la lista de aulas.
 * @return classroom* 
 */
classroom* getClassroom(int index, classroom *head){
	for(int i =0; i <= index || head!=NULL; head = head->next, i++){
		if(i == index)
			return head;
	}
}

/**
 * @brief Elimina los nodos de tipo aula por indice.
 * 
 * @param index Indice a eliminar.
 * @param head  La cabeza de la lista.
 */
void deleteClassroom(int index, classroom **head)
{
	classroom *current = (*head);
	classroom *prev;
	for (int i = 0; i <= index || current != NULL; i++, prev = current, current = current->next)
	{
		if (i == index)
		{
			if(index == 0){
				(*head) = current->next;
			}else{
				prev->next = current->next;
				current->next = NULL;
			}

			
		}
	}
}

/**
 * @brief Edita el nombre del aula
 * 
 * @param index 	Indice del profesor a editar.
 * @param newName 	Nuevo nombre del profesor.
 */
void editClassroomName(int index, char* newName,classroom **head){
	classroom *node = getClassroom(index,(*head));
	strcpy(node->name,newName);
}

/**
 * @brief Edita la capacidad del aula
 * 
 * @param index 		indice del aula.
 * @param newCapacity 	nueva capacidad del aula.
 * @param head 			cabeza de la lista de aulas.
 */
void editClassroomCapacity(int index, int newCapacity, classroom **head){
	classroom *node = getClassroom(index, (*head));
	node->capacity = newCapacity;

}

/**
 * @brief Imprime todos los nodos de una lista de tipo aula
 * 
 * @param head la cabeza de la lista.
 */
void printClassrooms(classroom *head)
{	
	for (int i = 0; head != NULL; i++, head = head->next)
	{
		printf("[%d] Aula: %s | Capacidad: %d\n", i, head->name, head->capacity);
	}
	printf("\n\n");
}
#endif