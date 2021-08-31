#ifndef PXCMENU_H
#define PXCMENU_H

void delPeriodMenu();
void addPeriodMenu();
void InfoPeriodMenu();

/**
 * @brief Menu de informacion de cursos
 * 
 */
void InfoPeriodMenu(){
	int loop = 1;
	do
	{
		printHeader("Informacion de curso por periodo");
		printMaintMenu("curso por periodo",0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addPeriodMenu();
			break;
		case '2':
			printFormatedTable("periodxcourse");
			break;	
		case '3':
			delPeriodMenu();
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
void delPeriodMenu(){
	printFormatedTable("periodxcourse");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[16];
	snprintf(values, sizeof(values), "%d",id);
	
	if(callStoredProcedureOutput("SP_DeleteCourseByPeriod",values) < 0)
		printf("No existe el id del curso en este periodo");
	
}

/**
 * @brief Menu para agregar cursos
 * 
 */
void addPeriodMenu(){
	//Falta agregar a la base de datos
	char courseCode[100] = {0};
	char year[100];
	int period;
	char group[100] = {0};
	char teacher[100];
	int numStudents;

	printFormatedTable("course");
	printf("Ingrese el codigo del curso\n");	//Obtiene el codigo del curso
	printf("\n>>");
	scanf("%s", courseCode);
	
	printf("Ingrese el anio\n"); 		//Ingresa el anio
	printf("\n>>");
	scanf("%s", year);

	printf("Ingrese el periodo\n"); 		//Ingresa el periodo
	printf("\n>>");
	scanf("%d", &period);

	printf("Ingrese el group\n"); 		//Ingresa el grupo.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", group);

	printFormatedTable("teacher");	
	printf("Ingrese el nombre del profesor\n");	
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", group);

	printf("Ingrese el numero de estudiantes\n");	
	printf("\n>>");
	scanf("%d", &numStudents);	

	char values[512];
	snprintf(values, sizeof(values), "'%s', '%s', %d, '%s', '%s', %d",courseCode,year,period,group,teacher,numStudents);
	int result = callStoredProcedureOutput("SP_InsertCourseByPeriod",values);
	if(result == -1){ 
		printf("ya existe un curso con el mismo anio o grupo en este periodo");
	}else if (result == -2)
	{
		printf("existe un curso con el mismo codigo de curso.");
		
	}else{
		printf("Se inserto con exito");
	}
	
}

#endif