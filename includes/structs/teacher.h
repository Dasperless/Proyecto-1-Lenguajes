#ifndef TEACHERS_H
#define TEACHERS_H
typedef struct Teacher
{
	char name[100];
	int idCard;
}teacher;

/**
 * @brief Edita la cedula del profesor.
 * 
 * @param idCard 	nueva cedula del profesor.
 * @param nodo 		Nodo de tipo teacher
 */
void editTeacherIdCard(int idCard, teacher *node){
	node->idCard = idCard;
}

/**
 * @brief Edita el nombre del profesor.
 * 
 * @param node 		Nodo de tipo teacher.
 * @param newName 	Nuevo nombre del profesor.
 */
void editTeacherName(char* newName,teacher *node){
	strcpy(node->name,newName);
}
#endif
