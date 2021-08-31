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