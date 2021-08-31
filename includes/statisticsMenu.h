#if !defined(STATISTICSMENU_H)
#define STATISTICSMENU_H

void statisticsMenu()
{
	int loop = 1;

	char option;
	do
	{
		printHeader("Estadisticas");
		printf("1.) Top 3 aulas mas reservadas\n");
		printf("2.) Top 3 profesores con mas reservas\n");
		printf("3.) Cantidad de reservas por anio-mes\n");
		printf("4.) Salir\n");
		option = inputMenu();
		switch (option)
		{
		case '1':
			printStoredProcedure("SP_Statistics('A')");
			break;
		case '2':
			printStoredProcedure("SP_Statistics('B')");
			break;
		case '3':
			printStoredProcedure("SP_Statistics('C')");
			break;
		case '4':
			loop = 0;
			break;
		default:
			break;
		}
	} while (loop);
}

#endif // STATISTICSMENU_H
