#ifndef OPERATIVEMENU_H
#define OPERATIVEMENU_H
/**
 * @brief Menu de opciones operativas
 * 
 */
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
			InfoTeacherMenu();
			break;
		case '3':
			InfoCourseMenu();
			break;
		case '4':
			InfoPeriodMenu();
			break;
		case '5':
			ReserveClassroomMenu();
			break;
		case '6':
			cancelReservationMenu();
			break;
		case '7':
			statisticsMenu();
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
#endif