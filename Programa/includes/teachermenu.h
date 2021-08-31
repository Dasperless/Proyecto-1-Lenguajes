#ifndef TEACHERMENU_H
#define TEACHERMENU_H

void delTeacherMenu();
void addTeacherMenu();
void InfoTeacherMenu();

/**
 * 
 * @brief Menu de informacion de profesores
 * 
 */
void InfoTeacherMenu()
{
	int loop = 1;
	do
	{
		printHeader("Informacion de profesores");
		printMaintMenu("profesor", 0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addTeacherMenu();
			break;
		case '2':
			printFormatedTable("teacher");
			break;
		case '3':
			delTeacherMenu();
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
 * @brief Menu para eliminar profesores.
 * 
 */
void delTeacherMenu()
{
	callStoredProcedure("SP_DeleteTeachers", " ");
	printf("Se han borrado todos los profesores\n");
}

/**
 * @brief Menu que agrega un nuevo profesor
 * 
 */
void addTeacherMenu()
{
	teacher newTeacher;

	printf("Ingrese el nombre del profesor\n"); //Obtiene el nombre.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", newTeacher.name);

	printf("Ingrese la cedula del profesor\n"); //Obtiene el profesor.
	printf("\n>>");
	scanf("%d", &newTeacher.idCard);

	char values[512];
	snprintf(values, sizeof(values), "'%s', %d", newTeacher.name, newTeacher.idCard);
	callStoredProcedure("SP_InsertTeacher", values);
}
#endif