#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* input(){
	int i;
	char c;
	char* input_string=(char*)malloc(sizeof(char)*1);
	
	printf("Enter Something:\n");
	c=getchar();
	
	for (i=1; c!='\n' && c!='\0' && c!=EOF; i++){
	 	input_string = (char*)realloc (input_string,sizeof(char)*i);
		*(input_string + i-1)=c;
		c=getchar();
	}
	i--;  
	
	//i represents size of the string
	//the last cahracter of the string is by default set to '\0'
	
	return input_string;
}


int main(){
	char* input_string;
	input_string = input();

	printf("The value you entered is :\n%s\nSize= %ld\n",
		input_string,strlen(input_string));
	
	return 0;
}
