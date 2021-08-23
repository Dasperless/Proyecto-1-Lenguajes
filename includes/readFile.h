#ifndef READFILE_H
#define READFILE_H


/**
 * @brief Agrega a aula con los datos de una linea del txt
 * 
 * @param line la linea a leer.
 * @param head Puntero al inicio de la lista.
 */
void addClassroomFromFile(char* line, classroom **head){
	char* name = NULL;
	int capacity = 0;
	for(int i =0; i<2;i++){
		switch (i)
		{
		case 0://Obtiene el nombre
			name = strtok(line, ",");
			// printf("%s",name);
			break;
		
		case 1://Obtiene la capacidad
			capacity = atoi(strtok(NULL, " "));
			break;
		}
	}
	if(name != NULL && capacity != 0)
		addClassroom(name,capacity,head);
}

/**
 * @brief Lee las lineas del archivo txt.
 * 
 * @param fileName  Ruta del archivo
 * @param head 		Puntero al inicio de la lista.
 */
void readClassroomFromFile(char* fileName, classroom **head){
	FILE *file= fopen(fileName, "r");
	char line[256];
	while (fgets(line,sizeof(line),file))
	{
		// printf("%s\n",line);
		addClassroomFromFile(line,head);
	}
	fclose(file);
}

#endif
