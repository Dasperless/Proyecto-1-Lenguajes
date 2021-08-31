#include <mysql.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "includes/connection.h"
#include "includes/structs/classroom.h"
#include "includes/structs/teacher.h"
#include "includes/structs/course.h"
#include "includes/structs/period.h"
#include "includes/readFile.h"
#include "includes/menu.h"
#include "includes/classmenu.h"
#include "includes/pxcmenu.h"
#include "includes/coursemenu.h"
#include "includes/teachermenu.h"
#include "includes/reservation.h"
#include "includes/statisticsMenu.h"
#include "includes/operativemenu.h"
#include "includes/genoptmenu.h"

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
			genOptMenu();
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
