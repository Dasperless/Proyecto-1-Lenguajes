#ifndef COURSEMENU_H
#define COURSEMENU_H

void delCourseMenu();
void addCourseMenu();
void InfoCourseMenu();

/**
 * @brief Menu de informacion de cursos
 * 
 */
void InfoCourseMenu()
{
	int loop = 1;
	do
	{
		printHeader("Informacion de cursos");
		printMaintMenu("cursos", 0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addCourseMenu();
			break;
		case '2':
			printFormatedTable("course");
			break;
		case '3':
			delCourseMenu();
			break;
		case '4':
			loop = 0;
			break;
		default:
			printf("La opcion ingresada no existe\n");
			break;
		}

	} while (loop);
}

/**
 * @brief Menu para eliminar cursos.
 * 
 */
void delCourseMenu()
{
	printFormatedTable("course");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[128];
	snprintf(values, sizeof(values), "%d", id);
	if (callStoredProcedureOutput("SP_DeleteCourseById", values) < 0)
		printf("No existe el indice ingresado");
}

/**
 * @brief Menu para agregar cursos
 * 
 */
void addCourseMenu()
{
	course newCourse;

	printf("Ingrese el codigo de la carrera\n"); //Obtiene el codigo de la carrera.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", newCourse.careerId);

	printf("Ingrese el codigo de curso\n"); //Obtiene el codigo de curso.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", newCourse.courseId);

	printf("Ingrese el nombre del curso\n"); //Obtiene el nombre del curso
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", newCourse.name);

	char values[512];
	snprintf(values, sizeof(values), "'%s', '%s', '%s'", newCourse.careerId, newCourse.courseId, newCourse.name);
	callStoredProcedure("SP_InsertCourse", values);
}
#endif