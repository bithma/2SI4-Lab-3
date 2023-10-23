#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	int i;

	FILE *file = fopen(filename, "r"); //initalizes file for reading
	fscanf(file, "%d", sizePtr);
	class_list = calloc(*sizePtr, sizeof(student*)); // allocating memory in pointer

	for (i=0; i<*sizePtr; i++){ //runs through each line on file
	student *list = calloc(1, sizeof(student)); //initalizing size of each pointer and setting variables to 0
	fscanf(file, "%d %s %s", &list-> student_id, list->first_name, list-> last_name); // adding values to each variable in structure
	class_list[i]= list;
	}


	fclose(file);

/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	int i = 0 ; //initializes variable


	for(i=0; i<size; i++){ //iterates through all students

		if ((list[i]-> student_id )== idNo){
			return i; } // returning position of student

		}


	/*write your implementation here and update the return accordingly*/
return -1;

}

void input_grades(char *filename, student **list, int size)

{

	/*write your implementation here*/
	int i =0;
	FILE *file = fopen(filename, "r");


	for (i=0; i<size; i++){
		int std_id;
		fscanf(file, "%d", &std_id); // reading student id's from grade file

		int index = find(std_id, list, size); // stating what index the student is in based on their std_id in classlist


		fscanf(file, "%d %d", &list[index] -> project1_grade, &list[index] -> project2_grade); // adds grades to classlist based on student id


	}
	fclose(file);

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	int i =0;

	for (i=0; i<size; i++){
	double avg = ( (list[i] -> project1_grade) + list[i] -> project2_grade) / 2.0; // calculates value of avg for each student

	list[i]->final_grade = avg; //puts avg value into each student classlist

}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write yo  ur implementation here*/
	FILE *file = fopen(filename, "w"); //Initializes file for writing
	int i = 0;
	fprintf(file, "%d", size);
	for (i=0; i<size; i++){
		fprintf(file, "\n%d %lf", list[i]-> student_id, list[i]-> final_grade);
	}
fclose(file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int i;

	int index = find(idNo, list,* sizePtr ); // finds student

	if (index != -1){
		free(list[index]); //removing student from memory
		for (i=index ; i < *sizePtr; i++){
					     list[i] = list[i + 1];
					    }
	}
	else {
		printf("The student with ID %d is not in the list", idNo);
	}
}



void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	free (list); //takes out everything from list with all information

		*sizePtr = 0; //resetting the number of students back to 0

}


int manage_students(char *grades_test, char *students_test, char *output_test ){
	int size;
	student **list = create_class_list(students_test,&size); // creates class structure


	find(3782, list, size); // finds student with 3782 iD

	input_grades(grades_test, list, size);

	compute_final_course_grades(list, size);
	int listsize = size;

	output_final_course_grades(output_test, list, size); //output grade function

	withdraw(8800, list, &size);//student found in list
	size --;
	withdraw(3888, list, &size); //student found in list
	size --;

	withdraw(5060, list, &size); // student not found in list

	destroy_list(list,&size);

return listsize;
}
