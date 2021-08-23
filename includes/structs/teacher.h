#ifndef TEACHERS_H
#define TEACHERS_H
typedef struct Teacher
{
	char name[100];
	int idCard;
	struct Teacher *next;

}teacher;


/**
 * @brief Agrega nuevos nodos de tipo aula.
 * 
 * @param name 		Nombre del profesor.
 * @param idCard 	Cedula del profesor.
 * @param head 		Puntero al inicio de la lista.
 */
void addTeacher(char* name, int idCard, teacher **head){
	teacher *newTeacher = (teacher *)malloc(sizeof(teacher));
	teacher *last = *head;

	strcpy(newTeacher->name,name);
	newTeacher->idCard = idCard;

	if (*head == NULL)
	{
		(*head) = newTeacher;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = newTeacher;
	return;	
}

/**
 * @brief Obtiene objetos Teacher por indice.
 * 
 * @param index El indice del profesor.
 * @param head 	Puntero al inicio de la lista.
 * @return teacher* 
 */
teacher* getTeacher(int index, teacher *head){
	for(int i =0; i <= index || head!=NULL; head = head->next, i++){
		if(i == index)
			return head;
	}
}

/**
 * @brief Edita la cedula del profesor.
 * 
 * @param index 		indice del profesor.
 * @param idCard 	nueva cedula del profesor.
 * @param head 			puntero al inicio de la lista.
 */
void editTeacherIdCard(int index, int idCard, teacher **head){
	teacher *node = getTeacher(index, (*head));
	node->idCard = idCard;

}

/**
 * @brief Edita el nombre del profesor.
 * 
 * @param index 	Indice del profesor a editar.
 * @param newName 	Nuevo nombre del profesor.
 */
void editTeacherName(int index, char* newName,teacher **head){
	teacher *node = getTeacher(index,(*head));
	strcpy(node->name,newName);
}

/**
 * @brief Elimina los nodos de tipo profesor por indice.
 * 
 * @param index Indice a eliminar.
 * @param head  Puntero al inicio de la lista
 */
void deleteTeacher(int index, teacher **head)
{
	teacher *current = (*head);
	teacher *prev;
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
 * @brief Imprime todos los nodos de una lista de tipo profesor
 * 
 * @param head puntero al inicio de la lista.
 */
void printTeachers(teacher *head)
{	
	for (int i = 0; head != NULL; i++, head = head->next)
	{
		printf("[%d] Nombre: %s | cedula: %d\n", i, head->name, head->idCard);
	}
	printf("\n\n");
}
#endif
