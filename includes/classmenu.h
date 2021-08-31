#ifndef CLASSMENU_H
#define CLASSMENU_H

void addClassroomMenu();
void delClassroomMenu();
void InfoClassroomMenu();

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
			readClassroomFromFile(path);
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
	printFormatedTable("classroom");
	printf("\nIngrese el indice a borrar");
	int id = inputInt();

	char values[120];
	snprintf(values, sizeof(values), "%d",id);
	if(callStoredProcedureOutput("SP_DeleteClassroomById",values)<0) 
		printf("No existe el id ");	
}

/**
 * @brief Menu para agregar aulas.
 * 
 */
void addClassroomMenu(){
	classroom newClassroom;

	printf("\nIngrese el nombre del aula");
	printf("\n>>");
	scanf(" %99[^\n]%*[^\n]", newClassroom.name);

	printf("\nIngrese la capacidad");
	printf("\n>>");
	scanf("%d", &newClassroom.capacity);

	char values[120];
	snprintf(values, sizeof(values), "'%s', %d",newClassroom.name,newClassroom.capacity);
	callStoredProcedure("SP_InsertClassroom",values);	
}

#endif 