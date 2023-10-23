#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/
	int n = (strlen(str1)+strlen(str2)); // finds sizes of both stings
	int k =0 ;
	int i;

	 z = calloc (n, sizeof(char)); // creating space for the strings combined
	 for( i=0; str1[i]!='\0'; i++){ //adding first string to empty space z
		 z[k] = str1[i];
		 k++;

	 }
	 for (i=0;i<=strlen(str2); i++){ // adding second string to empty space z
		z[k] = str2[i];
		k++;

	 }

	return z; // returning the variable with both string 1 and string 2
	
}
