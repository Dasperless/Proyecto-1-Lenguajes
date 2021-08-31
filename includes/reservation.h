#if !defined(RESERVATION_H)
#define RESERVATION_H

/**
 * @brief Valida el la hora ingresada
 * 
 * @param hh las horas
 * @param mm los minutos
 * @return int 1 si falla, 0 si esta correcto el tiempo.
 */
int ValidateTime(int hh, int mm)
{
	int ret = 0;

	if (hh > 24 || hh < 0)
		ret = 1;
	if (mm > 60 || mm < 0)
		ret = 1;

	return ret;
}

/**
 * @brief Menu para verificar si realiza una nueva reservacion
 * 
 */
int askNewReservation()
{
	printf("1.) Ingresar una nueva reservación\n");
	printf("2.) volver\n");
	int option;
	int incorrect = 0;
	do
	{
		incorrect = 0;
		option = inputInt();
		switch (option)
		{
		case 1:
			option = 1;
			break;
		case 2:
			option = 0;
		default:
			incorrect = 1;
			break;
		}
	} while (incorrect);
	return option;
}

/**
 * @brief Menu de reservacion de aulas
 * 
 */
void ReserveClassroomMenu()
{
	char startTimeBuff[100] = {0};
	char endTimeBuff[100] = {0};
	char dateBuff[100] = {0};
	char classroomName[100] = {0};
	char yearChar[10] = {0};
	char period[3] = {0};
	char courseCode[100] = {0};
	char group[100] = {0};

	int ret, hour, min;
	int day, month, year;

	int loop = 1;

	do
	{
		__fpurge(stdin);
		printf("\nIngrese la fecha \"dd/mm/aaaa\": ");
		fgets(dateBuff, 100, stdin);
		sscanf(dateBuff, "%d/%d/%d", &day, &month, &year);

		do
		{
			printf("\nIngrese la hora de inicio \"hh:mm\": ");
			fgets(startTimeBuff, 99, stdin);
			sscanf(startTimeBuff, "%d:%d", &hour, &min);
			ret = ValidateTime(hour, min);
			if (ret)
			{
				printf("\nFormato del tiempo inválido.\n");
			}
		} while (ret);

		do
		{
			printf("\nIngrese la hora fin \"hh:mm\": ");
			fgets(endTimeBuff, 99, stdin);
			sscanf(endTimeBuff, "%d:%d", &hour, &min);
			ret = ValidateTime(hour, min);
			if (ret)
			{
				printf("\nFormato del tiempo inválido.\n");
			}
		} while (ret);

		__fpurge(stdin);
		printFormatedTable("classroom");
		printf("\nIngrese el nombre del aula: ");
		scanf(" %99[^\n]%*[^\n]", classroomName);
		// fgets(classroomName, 100, stdin);

		__fpurge(stdin);
		printf("\nIngrese el anio: ");
		// fgets(yearChar, 10, stdin);
		scanf(" %99[^\n]%*[^\n]", yearChar);


		__fpurge(stdin);
		printf("\nIngrese el periodo: ");
		// fgets(period, 3, stdin);
		scanf(" %2[^\n]%*[^\n]", period);
		

		printFormatedTable("course");
		printf("\nIngrese el codigo del curso: ");
		// fgets(courseCode, 100, stdin);
		scanf(" %99[^\n]%*[^\n]", courseCode);


		printf("\nIngrese el grupo: ");
		// fgets(group, 100, stdin);
		scanf(" %99[^\n]%*[^\n]", group);


		char values[1024];
		snprintf(values, sizeof(values), "'%s', '%s', '%s', '%s', %s, '%s', '%s', '%s'", dateBuff, startTimeBuff, endTimeBuff, classroomName, yearChar, period, courseCode, group);
		int output = callStoredProcedureOutput("SP_NewReservation", values);
		switch (output)
		{
		case -1:
			printf("No existe al aula.\n");

			break;
		case -2:
			printf("No existe el curso en el periodo.\n");

			break;
		case -3:
			printf("No hay suficiente espacio.\n");

			break;
		case -4:
			printf("Ya existe una reservacion.\n");

			break;
		default:
			printf("Su numero de reservacion es: %d\n", output);

			break;
		}
		loop = askNewReservation();
	} while (loop);
}

/**
 * @brief Menu para cancelar la reservacion
 * 
 */
void cancelReservationMenu(){
	printFormatedTable("reservation");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[120];
	snprintf(values, sizeof(values), "%d",id);
	if(callStoredProcedureOutput("SP_DeleteReservationById",values)<0) 
		printf("No existe el id\n");
	else 
		printf("Se elimino con exito\n");

}


#endif // RESERVATION_H


