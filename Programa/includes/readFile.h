#ifndef READFILE_H
#define READFILE_H

/**
 * @brief Agrega a aula con los datos de una linea del txt
 * 
 * @param line la linea a leer.
 */
void addClassroomFromFile(char *line)
{
	classroom newClassroom;
	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
		case 0: //Obtiene el nombre
			strcpy(newClassroom.name, strtok(line, ","));
			break;

		case 1: //Obtiene la capacidad
			newClassroom.capacity = atoi(strtok(NULL, " "));
			break;
		}
	}
	if (newClassroom.name != NULL && newClassroom.capacity != 0)
	{
		char values[512];
		snprintf(values, sizeof(values), "'%s', %d", newClassroom.name, newClassroom.capacity);
		callStoredProcedure("SP_InsertClassroom", values);
	}
}

/**
 * @brief Lee las lineas del archivo txt.
 * 
 * @param fileName  Ruta del archivo
 * @param head 		Puntero al inicio de la lista.
 */
void readClassroomFromFile(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	char line[256];
	while (fgets(line, sizeof(line), file))
	{
		addClassroomFromFile(line);
	}
	fclose(file);
}

#endif
