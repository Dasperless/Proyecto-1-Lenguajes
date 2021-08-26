#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/structs/classroom.h"
#include "includes/structs/teacher.h"
#include "includes/structs/course.h"
#include "includes/structs/period.h"
#include "includes/list.h"
#include "includes/readFile.h"
#include "includes/menu.h"

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
