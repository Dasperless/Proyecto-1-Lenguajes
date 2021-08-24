#ifndef COURSE_H
#define COURSE_H
typedef struct Course
{
	char careerId[100];
	char courseId[100];
	char name[100];
} course;

/**
 * @brief Edita el codigo del curso.
 * 
 * @param node		 	Nodo de tipo course a editar.
 * @param newCourseId 	Nuevo codigo del curso.
 */
void editCourseId(char *newCourseId, course *node)
{
	strcpy(node->careerId, newCourseId);
}

/**
 * @brief Edita el codigo de carrera
 *
 * @param newCareerId 	nuevo codigo de carrea.
 * @param node 			Nodo de tipo course a cambiar.
 */
void editCareerId(char *newCareerId, course *node)
{
	strcpy(node->courseId, newCareerId);
}

/**
 * @brief Edita el nombre del curso.
 *
 * @param newName 	Nuevo nombre del curso.
 * @param node 		Nodo course a cambiar.
 */
void editCourseName(char *newName, course *node)
{
	strcpy(node->name, newName);
}

#endif