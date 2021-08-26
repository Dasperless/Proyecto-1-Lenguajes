#ifndef PERIOD_H
#define PERIOD_H
typedef struct Period
{
	char courseId[100];
	int year;
	int perid;
	char group[100];
	int profesorId;
	int numStudents;
}period;

/**
 * @brief Edita el codigo del curso.
 * 
 * @param newCourseId 	Nuevo codigo de curso.
 * @param node 			Nodo de tipo period.
 */
void editPeriodCourseId(char* newCourseId, period *node){
	strcpy(node->courseId, newCourseId);
}
 
/**
 * @brief Edita el anio del periodo.
 * 
 * @param newYear	Nuevo anio.
 * @param node 		Nodo de tipo period
 */
void editYear(int newYear, period *node){
	node->year = newYear;
}

/**
 * @brief Edita el periodo
 * 
 * @param newPeriod	Nuevo numero de periodo.
 * @param node 		Nodo de tipo period
 */
void editPeriod(int newPeriod, period *node){
	node->perid = newPeriod;
}

/**
 * @brief Edita el grupo de un periodo
 * 
 * @param newGroup 	Nuevo grupo.
 * @param node 		Nodo de tipo period
 */
void editGroup(char *newGroup, period *node){
	strcpy(node->group,newGroup);
}

/**
 * @brief Edita el id del profesor
 * 
 * @param newProfesorId Nuevo id del profesor.
 * @param node 			Nodo de tipo period.
 */
void editProfesorId(int newProfesorId, period *node){
	node->profesorId = newProfesorId;
}

/**
 * @brief Edita la cantidad de estudiantes.
 * 
 * @param newNum	Nueva cantidad de estudiantes.
 * @param node 		Nodo de tipo period.
 */
void editNumStudents(int newNum, period *node){
	node->numStudents = newNum;
}

#endif