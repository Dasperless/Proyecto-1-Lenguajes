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

/**
 * @brief Menu de informacion de cursos
 * 
 */
void InfoPeriodMenu(){
	int loop = 1;
	do
	{
		printHeader("Informacion de periodo");
		printMaintMenu("periodo",0);

		char option = inputMenu();
		switch (option)
		{
		case '1':
			addPeriodMenu();
			break;
		case '2':
			printList(periodList,printPeriod);
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
	int index = inputInt();
	period *node = getNode(index,courseList);

	if(node == NULL){
		printf("No existe el indice seleccionado");
		return;
	}
	deleteNode(index,&courseList);
}

/**
 * @brief Menu para agregar cursos
 * 
 */
void addPeriodMenu(){
	//Falta agregar a la base de datos
	char courseId[100] = {0};
	int year;
	int perid;
	char group[100] = {0};
	int profesorId;
	int numStudents;
	int index;

	period *newPeriod = (period*)malloc(PERIOD_SIZE);
	course *courseSelected;

	printList(courseList,printCourses);
	printf("Ingrese el indice del codigo del curso\n");	//Obtiene el codigo del curso
	printf("\n>>");
	scanf("%d", &index);
	courseSelected = (course*) getNode(index,courseList);
	
	printf("Ingrese el anio\n"); 		//Ingresa el anio
	printf("\n>>");
	scanf("%d", &year);

	printf("Ingrese el periodo\n"); 		//Ingresa el periodo
	printf("\n>>");
	scanf("%d", &perid);

	printf("Ingrese el group\n"); 		//Ingresa el grupo.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", group);

	printList(teacherList,printTeachers);
	printf("Ingrese el indice del profesor\n");	
	printf("\n>>");
	scanf("%d", &profesorId);	

	printf("Ingrese el numero de estudiantes\n");	
	printf("\n>>");
	scanf("%d", &numStudents);	

	strcpy(newPeriod->courseId,courseSelected->name);
	newPeriod->year=year;
	newPeriod->perid=perid;
	strcpy(newPeriod->group,group);
	newPeriod->profesorId = profesorId;
	newPeriod->numStudents = numStudents;

	push(&courseList,newPeriod,PERIOD_SIZE);	
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
			printList(courseList,printCourses);
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
	//Falta eliminar a la base de datos
	printList(courseList,printCourses);
	printf("\nIngrese el indice a borrar");
	int index = inputInt();
	course *node = getNode(index,courseList);

	if(node ==NULL){
		printf("No existe el indice seleccionado");
		return;
	}
	deleteNode(index,&courseList);
}

/**
 * @brief Menu para agregar cursos
 * 
 */
void addCourseMenu(){
	//Falta agregar a la base de datos
	char careerId[100] = {0};
	char courseId[100] = {0};
	char name[100] = {0};
	course *newCourse = (course*)malloc(COURSE_SIZE);

	printf("Ingrese el codigo de la carrera\n");	//Obtiene el codigo de la carrera.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", careerId);

	printf("Ingrese el codigo de curso\n"); 		//Obtiene el codigo de curso.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", courseId);

	printf("Ingrese el codigo de curso\n"); 		//Obtiene el nombre del curso
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	strcpy(newCourse->careerId, careerId);
	strcpy(newCourse->courseId, courseId);
	strcpy(newCourse->name, name);

	push(&teacherList,newCourse,TEACHER_SIZE);	
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
			printList(teacherList,printTeachers);
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
	//Falta eliminar a la base de datos
	printList(teacherList,printTeachers);
	printf("\nIngrese el indice a borrar");
	int index = inputInt();
	teacher *node = getNode(index,teacherList);

	if(node ==NULL){
		printf("No existe el indice seleccionado");
		return;
	}
	deleteNode(index,&classroomList);
}

/**
 * @brief Menu que agrega un nuevo profesor
 * 
 */
void addTeacherMenu(){
	//Falta agregar a la base de datos
	char name[100] = {0};
	int id;
	teacher *newTeacher = (teacher*)malloc(TEACHER_SIZE);

	printf("Ingrese el nombre del profesor\n");	//Obtiene el nombre.
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	printf("Ingrese la cedula del profesor\n"); //Obtiene el profesor.
	printf("\n>>");
	scanf("%d", &id);

	strcpy(newTeacher->name, name);
	newTeacher->idCard = id;

	push(&teacherList,newTeacher,TEACHER_SIZE);
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
		printf("opcion: %d",option);
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
			printList(classroomList,printClassrooms);
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
	printList(classroomList,printClassrooms);
	printf("\nIngrese el indice a borrar");
	int index = inputInt();
	classroom *node = getNode(index,classroomList);

	if(node ==NULL){
		printf("No existe el indice seleccionado");
		return;
	}
	deleteNode(index,&classroomList);
	
}

/**
 * @brief Menu para agregar aulas.
 * 
 */
void addClassroomMenu(){
	//Falta agregar a la base de datos
	classroom *newClassroom = (classroom*)malloc(CLASSROOM_SIZE);
	char name[100] ={0};
	int capacity;

	printf("\nIngrese el nombre del aula");
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", name);

	printf("\nIngrese la capacidad");
	printf("\n>>");
	scanf("%d", &capacity);

	strcpy(newClassroom->name,name);
	newClassroom->capacity = capacity;
	push(&classroomList,newClassroom,CLASSROOM_SIZE);
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