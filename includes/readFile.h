#ifndef READFILE_H
#define READFILE_H

void getClassroomFromFile(char* fileName, classroom **list){
	FILE *file= fopen(fileName, "r");
	char line[256];
	while (fgets(line,sizeof(line),file))
	{
		printf("%s",line);
	}
	fclose(file);
}

#endif
