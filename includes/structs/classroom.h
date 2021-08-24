#ifndef CLASSROOM_H
#define CLASSROOM_H
typedef struct Classroom
{
	char name[100];
	int capacity;
} classroom;

/**
 * @brief Edita el nombre del aula
 * 
 * @param newName 	Nuevo nombre del profesor.
 * @param node Nodo de tipo classroom.
 */
void editClassroomName(char *newName, classroom *node)
{
	strcpy(node->name, newName);
}

/**
 * @brief Edita la capacidad del aula
 * 
 * @param newCapacity 	Nueva capacidad del aula.
 * @param node 			Nodo de tipo classroom.
 */
void editClassroomCapacity(int newCapacity, classroom *node)
{
	node->capacity = newCapacity;
}

#endif