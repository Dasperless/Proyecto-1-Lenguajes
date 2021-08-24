#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/structs/classroom.h"
#include "includes/structs/teacher.h"
#include "includes/structs/course.h"
#include "includes/list.h"
#include "includes/readFile.h"
int main(){
	list *head = NULL;
	// teacher *headTeacher = NULL;
	// // addClassroom("A1",1,&head);
	// // addClassroom("A2",2,&head);
	// // addClassroom("A3",3,&head);
	// // addClassroom("A4",4,&head);

	// addTeacher("Dario Vargas",11753055,&headTeacher);
	// addTeacher("Dario Vargas",11753055,&headTeacher);
	// addTeacher("Dario Vargas",11753055,&headTeacher);
	// addTeacher("Dario Vargas",11753055,&headTeacher);
	// printTeachers(headTeacher);
	// editTeacherIdCard(1,1848462,&headTeacher);
	// deleteTeacher(0,&headTeacher);
	// printTeachers(headTeacher);


	readClassroomFromFile("/home/ubuntu/Desktop/Proyecto-1-Lenguajes/test.txt",&head);
	printList(head,printClassrooms);
	
	classroom *c = (classroom*)getNode(0,head);
	editClassroomName("cambio",c);

	printList(head,printClassrooms);


	// printf("%p\n",c);


}

// int main(){
// 	course *head = NULL;
// 	addCourse("adas", "dasdas","Bases I",&head);
// 	addCourse("dasdas", "adas","Bases II",&head);
// 	deleteCourse(0,&head);
// 	editCareerId(0,"991",&head);
// 	printCourses(head);

// }

// int main(){
// 	course *head = NULL;
// 	addCourse("adas", "dasdas","Bases I",&head);
// 	addCourse("dasdas", "adas","Bases II",&head);
// 	deleteCourse(0,&head);
// 	editCareerId(0,"991",&head);
// 	printCourses(head);

// }

// int main()
// {
//     struct List *start = NULL;
// 	struct Teacher *t = (teacher*) malloc(sizeof(teacher));
//     unsigned int_size = sizeof(teacher);
// 	strcpy(t->name,"Dario");
// 	t->idCard =10;
	
//     for (int i=4; i>=0; i--)
//        push(&start, t, int_size);
// 	deleteNode(0,&start);
//     printf("Created integer linked list is \n");
//     printList(start, printTeachers);

  
//     return 0;
// }