#ifndef CLASSROOM_H
#define CLASSROOM_H
typedef struct Classroom
{
	char *name;
	int capacity;
	struct Classroom *next;
} classroom;

void addClassroom(char *name, int capacity, classroom **head)
{
	classroom* newClassroom = (classroom*) malloc(sizeof(classroom));
	classroom  *last  = *head;


	newClassroom->name = name;
	newClassroom->capacity = capacity;

    if (*head == NULL)
    {
       (*head) = newClassroom;

       return;
    } 

    while (last->next != NULL)
        last = last->next;
  
    last->next = newClassroom;
    return;
}

void printClassrooms(classroom *head){
	for(int i =0;head!= NULL; i++, head = head->next)
	{
		printf("##### %d  #####\n", i);
		printf("%s \n",head->name);
		printf("%d\n",head->capacity);
	}
	printf("\n\n");
}
#endif