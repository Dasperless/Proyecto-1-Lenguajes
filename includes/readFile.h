#ifndef READFILE_H
#define READFILE_H

/**
 * @brief Agrega a aula con los datos de una linea del txt
 * 
 * @param line la linea a leer.
 */
void addClassroomFromFile(char *line)
{
	char *name = NULL;
	int capacity = 0;
	classroom *newClassroom = (classroom *)malloc(sizeof(classroom));
	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
		case 0: //Obtiene el nombre
			name = strtok(line, ",");
			strcpy(newClassroom->name, name);
			break;

		case 1: //Obtiene la capacidad
			capacity = atoi(strtok(NULL, " "));
			newClassroom->capacity = capacity;
			break;
		}
	}
	if (name != NULL && capacity != 0)
	{
		char values[512];
		snprintf(values, sizeof(values), "'%s', %d", name, capacity);
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
