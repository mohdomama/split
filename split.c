#include<stdio.h>

char* get_string(char* a, char* b, char* c){
	int i=0;
	char *temp;
	for (temp =a; temp < b; temp++){
	
	c[i]= *temp;
	i++;
	}

	//return string;

}

int main()
{
    char* input = "Hello Word of C";
    char *output, *temp;
    char * field;
    char sep = ' ';
    int cnt = 1,i;
    field = input;
    
    for (temp=field; *temp; ++temp){
    
    	if (*temp==sep){
    		cnt++;
    	}
    
    
    }
    cnt ++;
    char array_words[cnt][10];  //resolve
    cnt=1;
    
    for(temp = field; *temp; ++temp){ 
       if (*temp == sep){
          printf("%d.) %.*s\n", cnt, (int)(temp-field), field);
          get_string(field,temp,array_words[cnt-1]);
          cnt++;
          field = temp+1;
       }
    }
    
    printf("%d.) %.*s\n", cnt, (int)(temp-field), field);
    get_string(field,temp,array_words[cnt-1]);
    cnt++;
   

	for (i=0;i<cnt;i++){
	printf("%s\n",array_words[i]);
	}
	
	 return 0;

}







