#if !defined(GENOPTMENU_H)
#define GENOPTMENU_H

void queryByDay();
void queryByClassroom();
void queryByCourse();

/**
 * @brief Menu de opciones generales.
 * 
 */
void genOptMenu()
{
	int loop = 1;
	char option;
	do
	{
		printHeader("Opciones generales");
		printf("1.) Consulta por dia\n");
		printf("2.) Consulta por aula\n");
		printf("3.) Consulta por curso\n");
		printf("4.) Volver\n");

		option = inputMenu();
		switch (option)
		{
		case '1':
			queryByDay();
			break;
		case '2':
			queryByClassroom();
			break;
		case '3':
			queryByCourse();
			break;
		case '4':
			loop = 0;
			break;
		default:
			printf("No existe la opcion ingresada\n");
			break;
		}
	} while (loop);
}

/**
 * @brief Obtiene la fecha y realiza la consulta
 * 
 */
void queryByDay()
{
	char dateBuff[120] = {0};
	int day, month, year;

	__fpurge(stdin);
	printf("\nIngrese la fecha \"dd/mm/aaaa\": ");
	fgets(dateBuff, 119, stdin);
	sscanf(dateBuff, "%d/%d/%d", &day, &month, &year);

	char query[250];
	snprintf(query, sizeof(query), "SP_QueryByDay('%s')", dateBuff);

	printStoredProcedure(query);
}

/**
 * @brief Obtien el nombre del aula y realiza la consulta
 * 
 */
void queryByClassroom()
{
	char classroomName[100];
	printf("\nIngrese el aula: ");
	scanf(" %99[^\n]%*[^\n]", classroomName);

	char values[120];
	snprintf(values, sizeof(values), "'%s'", classroomName);

	if (printStoredProcedureOutput("SP_QueryByClassroom", values) < 0)
		printf("No existe el aula");
}

/**
 * @brief Obtiene el nombre del curso y hace la consulta 
 * 
 */
void queryByCourse()
{
	period queryCourse;
	printf("\nIngrese el anio: ");
	scanf(" %99[^\n]%*[^\n]", queryCourse.year);

	printf("\nIngrese el periodo: ");
	scanf("%d", &queryCourse.perid);

	printf("\nIngrese el curso: ");
	scanf(" %99[^\n]%*[^\n]", queryCourse.courseCode);

	printf("\nIngrese el grupo: ");
	scanf(" %99[^\n]%*[^\n]", queryCourse.group);

	char values[512];
	snprintf(values, sizeof(values), "'%s', %d, '%s','%s'", queryCourse.year, queryCourse.perid, queryCourse.courseCode, queryCourse.group);

	if (printStoredProcedureOutput("SP_QueryByCourse", values) < 0)
		printf("No existe el aula");
}

#endif // GENOPTMENU_H
