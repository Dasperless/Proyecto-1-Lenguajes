#ifndef MENU_H
#define MENU_H

const int CLASSROOM_SIZE = sizeof(classroom);
const int TEACHER_SIZE = sizeof(teacher);
const int PERIOD_SIZE = sizeof(period);
const int COURSE_SIZE = sizeof(course);

list *classroomList = NULL;
list *periodList = NULL;
list *teacherList = NULL;
list *courseList = NULL;

char *inputString();
char inputMenu();
int inputInt();

void printMaintMenu(char* functTitle, int startNum);
void printHeader(char *title);

void ReserveClassroomMenu();

//Menu de periodos
void delPeriodMenu();
void addPeriodMenu();
void InfoPeriodMenu();

//Menu de cursos
void delCourseMenu();
void addCourseMenu();
void InfoCourseMenu();

//Menu de profesores
void delTeacherMenu();
void addTeacherMenu();
void InfoTeacherMenu();

//Menu de aulas
void delClassroomMenu();
void addClassroomMenu();
void InfoClassroomMenu();

void OptOpeMenu();

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


/**
 * @brief Menu de informacion de cursos
 * 
 */
void InfoPeriodMenu(){
	int loop = 1;
	do
	{
		printHeader("Informacion de curso por periodo");
		printMaintMenu("periodo",0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addPeriodMenu();
			break;
		case '2':
			printFormatedTable("periodx");
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
	//Falta eliminar a la base de datos
	printList(periodList,printCourses);
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

	printf("Ingrese el codigo del curso\n");	//Obtiene el codigo del curso
	printf("\n>>");
	scanf("%s", courseCode);
	
	printf("Ingrese el anio\n"); 		//Ingresa el anio
	printf("\n>>");
	scanf("%d", year);

	printf("Ingrese el periodo\n"); 		//Ingresa el periodo
	printf("\n>>");
	scanf("%d", &period);

	printf("Ingrese el group\n"); 		//Ingresa el grupo.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", group);

	printf("Ingrese el nombre del profesor\n");	
	printf("\n>>");
	scanf("%s", teacher);	

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


/**
 * @brief Menu de informacion de cursos
 * 
 */
void InfoCourseMenu(){
	int loop = 1;
	do
	{
		printHeader("Informacion de cursos");
		printMaintMenu("cursos",0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addCourseMenu();
			break;
		case '2':
			printTable("cursos");
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
void delCourseMenu(){
	printFormatedTable("SP_DeleteCourseById");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[128];
	snprintf(values, sizeof(values), "'%d'",id);
	callStoredProcedure("SP_InsertCourse",values);	
}

/**
 * @brief Menu para agregar cursos
 * 
 */
void addCourseMenu(){
	char careerId[100] = {0};
	char courseId[100] = {0};
	char name[100] = {0};

	printf("Ingrese el codigo de la carrera\n");	//Obtiene el codigo de la carrera.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", careerId);

	printf("Ingrese el codigo de curso\n"); 		//Obtiene el codigo de curso.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", courseId);

	printf("Ingrese el nombre del curso\n"); 		//Obtiene el nombre del curso
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	char values[512];
	snprintf(values, sizeof(values), "'%s', '%s', '%s'",careerId,courseId,name);
	callStoredProcedure("SP_InsertCourse",values);
}

/**
 * @brief Menu de informacion de profesores
 * 
 */
void InfoTeacherMenu(){
	int loop = 1;
	do
	{
		printHeader("Informacion de profesores");
		printMaintMenu("profesor",0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addTeacherMenu();
			break;
		case '2':
			printTable("profesores");
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
void delTeacherMenu(){
	callStoredProcedure("SP_DeleteTeachers"," ");
	printf("Se han borrado todos los profesores\n");
}

/**
 * @brief Menu que agrega un nuevo profesor
 * 
 */
void addTeacherMenu(){
	char name[100] = {0};
	int id;
	
	printf("Ingrese el nombre del profesor\n");	//Obtiene el nombre.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	printf("Ingrese la cedula del profesor\n"); //Obtiene el profesor.
	printf("\n>>");
	scanf("%d", &id);

	char values[512];
	snprintf(values, sizeof(values), "'%s', %d",name,id);
	callStoredProcedure("SP_InsertTeacher",values);
}

/**
 * @brief Menu de informacion de aulas
 * 
 */
void InfoClassroomMenu()
{
	char path[1024] = {0};
	int loop = 1;
	do
	{
		printHeader("Informacion de aulas");
		printf("1.) Incluir en lote\n");
		printMaintMenu("aula",1);

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
			addClassroomMenu();
			break;	
		case '3':
			printFormatedTable("classroom");
			break;	
		case '4':
			delClassroomMenu();
			break;	
		case '5':
			loop = 0;
			break;
		default:
			printf("La opcion ingresada no existe\n");
			break;
		}

	} while (loop);
}

/**
 * @brief Menu para eliminar aulas.
 * 
 */
void delClassroomMenu(){
	//Falta eliminar a la base de datos
	printTable("teacher");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[120];
	snprintf(values, sizeof(values), "%d",id);
	if(callStoredProcedureOutput("SP_DeleteClassroomById",values)<0) 
		printf("No existe el id ");

	printFormatedTable("classroom");
	
}

/**
 * @brief Menu para agregar aulas.
 * 
 */
void addClassroomMenu(){
	char name[100] ={0};
	int capacity;

	printf("\nIngrese el nombre del aula");
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	printf("\nIngrese la capacidad");
	printf("\n>>");
	scanf("%d", &capacity);

	char values[120];
	snprintf(values, sizeof(values), "'%s', %d",name,capacity);
	callStoredProcedure("SP_InsertTeacher",values);	
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
 * @brief Obtine un inpunt entero
 * 
 * @return int 
 */
int inputInt(){
	int option;
	printf("\n>>");
	scanf(" %i", &option);
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

/**
 * @brief Imprime el menu de mantenimiento
 * 
 * @param functTitle 	El nombre de la opcion operativa
 * @param startNum 		El numero con el que inicia el menu
 */
void printMaintMenu(char* functTitle, int startNum){
	printf("%d.) Incluir %s\n",startNum+1,functTitle);
	printf("%d.) Listar %s\n",startNum+2,functTitle);
	printf("%d.) Eliminar %s\n",startNum+3,functTitle);
	printf("%d.) Volver\n",startNum+4);
}
#endif