#ifndef LIST_H
#define LIST_H
typedef struct List
{
    void  *data;
    struct List *next;
}list;
  
void push(list** head_ref, void *new_data, size_t data_size)
{
    list *new_node = (list*)malloc(sizeof(struct List));
  
    new_node->data  = malloc(data_size);
    new_node->next = (*head_ref);

    int i;
    for (i=0; i<data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
  
    (*head_ref)    = new_node;
}
  

void printList(list *node, void (*fptr)(void *))
{
    for(int i=0; node!=NULL;i++, node =node->next)
    {
		printf("[%d] ",i);
        (*fptr)(node->data);

    }
	printf("\n\n");

}

void printCoursesFn(void *c)
{	
	course *node =(struct Course *)c;
	printf("Cod. carrera: %s | Cod. curso: %s | Nombre: %s\n", node->careerId, node->courseId,node->name);
}

void printInt(void *n)
{
   printf(" %d", *(int *)n);
}
  
void printFloat(void *f)
{
   printf(" %f", *(float *)f);
}
  

#endif
