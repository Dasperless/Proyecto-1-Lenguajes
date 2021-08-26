#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/structs/classroom.h"
#include "includes/structs/teacher.h"
#include "includes/structs/course.h"
#include "includes/structs/period.h"
#include "includes/list.h"
#include "includes/readFile.h"

list *classroomList = NULL;
list *courseList = NULL;

void printHeader(char *title);
char inputMenu();
char *inputString();
void InfoClassroomMenu();
void OptOpeMenu();

int main()
{
	int loop = 1;
	do
	{
		printHeader("Menu");
		printf("1.) Opciones operativas\n");
		printf("2.) Opciones generales\n");
		printf("3.) Salir\n");

		char option = inputMenu();
		switch (option)
		{
		case '1':
			OptOpeMenu();
			break;

		case '2':
			printf("opcion 2\n");
			break;
		case '3':
			loop = 0;
			break;
		default:
			printf("La opcion ingresada no existe\n");
			break;
		}

	} while (loop);
}

void OptOpeMenu()
{
	int loop = 1;
	do
	{
		printHeader("Opciones operativas");
		printf("1.) Información Aulas\n");
		printf("2.) Información de Profesores\n");
		printf("3.) Información de Cursos\n");
		printf("4.) Cursos por Período\n");
		printf("5.) Reservación de aula\n");
		printf("6.) Cancelar reservación\n");
		printf("7.) Estadísticas\n");
		printf("8.) Volver\n");

		char option = inputMenu();
		switch (option)
		{
		case '1':
			InfoClassroomMenu();
			break;
		case '2':
			/* code */
			break;
		case '3':
			/* code */
			break;
		case '4':
			/* code */
			break;
		case '5':
			/* code */
			break;
		case '6':
			/* code */
			break;
		case '7':
			/* code */
			break;
		case '8':
			loop = 0;
			break;
		default:
			printf("La opcion ingresada no existe\n");
			break;
		}
	} while (loop);
}

void InfoClassroomMenu()
{
	char path[1024] = {0};
	int loop = 1;
	do
	{
		printHeader("Informacion de aulas");
		printf("1.) Incluir en lote\n");
		printf("2.) Volver\n");

		char option = inputMenu();
		switch (option)
		{
		case '1':
			printf("Ingrese el la ruta del archivo .txt\n");
			printf("\n>>");
			scanf(" %1023[^\n]%*[^\n]", path);
			readClassroomFromFile(path,&classroomList);
			printList(classroomList,printClassrooms);
			break;
		case '2':
			loop = 0;
			break;
		default:
			printf("La opcion ingresada no existe\n");
			break;
		}

	} while (loop);
}

/**
 * @brief Obtiene el input para los menus
 * 
 * @return char 
 */
char inputMenu()
{
	char option;
	printf("\n>>");
	scanf(" %c", &option);
	return option;
}


/**
 * @brief Imprime un una caja con un encabezado
 * 
 * @param title El titulo del encabezado.
 */
void printHeader(char *title)
{
	int size = strlen(title) + 24;
	printf("\n+");
	for (int i = 0; i < size; i++)
		printf("-");
	printf("+\n");

	printf("|            %s            |\n+", title);
	for (int i = 0; i < size; i++)
		printf("-");
	printf("+\n");
}