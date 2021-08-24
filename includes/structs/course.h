#ifndef COURSE_H
#define COURSE_H
typedef struct Course
{
	char careerId[100];
	char courseId[100];
	char name[100];
	struct Course *next;
} course;

/**
 * @brief Funcion para agregar nuevos nodos de tipo curso.
 * 
 * @param careerId 		El nombre del curso.
 * @param courseId 	La capacidad del curso.
 * @param head 		La referencia de la cabeza de la lista.
 */

void addCourse(char *careerId, char *courseId, char *name, course **head)
{
	course *newCourse = (course *)malloc(sizeof(course));
	course *last = *head;

	strcpy(newCourse->careerId,careerId);
	strcpy(newCourse->courseId,courseId);
	strcpy(newCourse->name,name);
	

	if (*head == NULL)
	{
		(*head) = newCourse;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = newCourse;
	return;
}

/**
 * @brief Obtiene objetos Course por indice.
 * 
 * @param index El indice del curso.
 * @param head 	Puntero al inicio de la lista.
 * @return course* 
 */
course* getCourse(int index, course *head){
	for(int i =0; i <= index || head!=NULL; head = head->next, i++){
		if(i == index)
			return head;
	}
}

/**
 * @brief Elimina los nodos de tipo curso por indice.
 * 
 * @param index Indice a eliminar.
 * @param head  La cabeza de la lista.
 */
void deleteCourse(int index, course **head)
{
	course *current = (*head);
	course *prev;
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
 * @brief Edita el codigo del curso.
 * 
 * @param index 	Indice del curso a editar.
 * @param newCourseId 	Nuevo codigo del curso.
 */
void editCourseId(int index, char* newCourseId,course **head){
	course *node = getCourse(index,(*head));
	strcpy(node->careerId,newCourseId);
}

/**
 * @brief Edita el codigo de carrera
 * 
 * @param index 		indice del curso.
 * @param newCareerId 	nuevo codigo de carrea.
 * @param head 			Puntero al inicio de la lista.
 */
void editCareerId(int index, char* newCareerId, course **head){
	course *node = getCourse(index, (*head));
	strcpy(node->courseId, newCareerId) ;

}

/**
 * @brief Edita el nombre del curso.
 * 
 * @param index 	Indice del curso.
 * @param newName 	Nuevo nombre del curso.
 * @param head 		Puntero al inicio de la lista.
 */
void editCourseName(int index, char* newName, course** head){
	course *node = getCourse(index,(*head));
	strcpy(node->name, newName) ;

}

/**
 * @brief Imprime todos los nodos de una lista de tipo curso
 * 
 * @param head la cabeza de la lista.
 */
void printCourses(course *head)
{	
	for (int i = 0; head != NULL; i++, head = head->next){
		printf("[%d] Cod. carrera: %s | Cod. curso: %s | Nombre: %s\n", i, head->careerId, head->courseId,head->name);
	}
	printf("\n\n");
}
#endif