#ifndef LIST_H
#define LIST_H
typedef struct List
{
    // Cualquier tipo de dato puede ser guardado aqui.
    void *data;
    struct List *next;
} list;

/**
 * @brief Agrega un nuevo nodo a la lista.
 * 
 * @param head_ref  Referencia al inicio de la lista
 * @param new_data  Nuevo nodo
 * @param data_size Tamanio del tipo de nodo
 */
void push(struct List **head_ref, void *new_data, size_t data_size)
{
    // Asigna una direccion de memoria para el nodo
    struct List *new_node = (struct List *)malloc(sizeof(struct List));

    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);

    // Copia el contenido de new_data a la nueva direccion de memoria
    int i;
    for (i = 0; i < data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    // Cambia la cabeza y apunta al nuevo nodo agregando al inicio
    (*head_ref) = new_node;
}

/**
 * @brief Imprime los nodos de una lista dada.
 * 
 * @param node Lista de nodos
 * @param fptr Funcion que imprime los nodos
 */
void printList(struct List *node, void (*fptr)(void *))
{
    for (int i = 0; node != NULL; i++, node = node->next)
    {
        printf("[%d] ", i);
        (*fptr)(node->data);
    }
    printf("\n");
}

/**
 * @brief Imprime los nodos de tipo teacher
 * 
 * @param teacherList Lista de nodos teacer.
 */
void printTeachers(void *teacherList)
{
    teacher *t = (teacher *)teacherList;
    printf("Nombre: %s | cedula: %d\n", t->name, t->idCard);
}

/**
 * @brief Imprime los nodos de tipo period
 * 
 * @param periodList Lista de nodos period.
 */
void printPeriod(void *periodList)
{
    period *p = (period *)periodList;
    printf("Cod Curso: %s | anio: %d | periodo: %d\n | grupo %s | prefosor: %d | Num. Estudiantes: %d", p->courseId, p->year, p->perid, p->group, p->profesorId, p->numStudents);
}

/**
 * @brief Imprime nodos de tipo curso.
 * 
 * @param courseList la cabeza de la lista.
 */
void printCourses(void *courseList)
{
    course *c = (course *)courseList;
    printf("Cod. carrera: %s | Cod. curso: %s | Nombre: %s\n", c->careerId, c->courseId, c->name);
}

/**
 * @brief Imprime nodos de tipo aula.
 * 
 * @param classroomList la cabeza de la lista.
 */
void printClassrooms(void *classroomList)
{
    classroom *cl = (classroom *)classroomList;
    printf("Aula: %s | Capacidad: %d\n", cl->name, cl->capacity);
}

/**
 * @brief Elimina los nodos de la lista
 * 
 * @param index Indice a eliminar.
 * @param head  Puntero al inicio de la lista
 */
void deleteNode(int index, list **head)
{
    list *current = (*head);
    list *prev;
    for (int i = 0; i <= index || current != NULL; i++, prev = current, current = current->next)
    {
        if (i == index)
        {
            if (index == 0)
            {
                (*head) = current->next;
            }
            else
            {
                prev->next = current->next;
                current->next = NULL;
            }
        }
    }
}

/**
 * @brief Obtiene un nodo por indice.
 * 
 * @param index El indice del aula.
 * @param head 	La cabeza de la lista de aulas.
 * @return list* 
 */
void *getNode(int index, list *head)
{
    for (int i = 0; i <= index || head != NULL; head = head->next, i++)
    {
        if (i == index)
            return head->data;
    }
    return NULL;
}

#endif
