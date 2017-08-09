#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int get_integer_value(){
    int i=0;
    while(1>0){
        scanf("%d",&i);
        if(getchar()=='\n'){
            break;
        }
        else{
            printf("Wrong Input! Try again!\n");
            while(getchar()!='\n');
        }
    
    }
    return i;

}

int getcount(char* inputString){
    int i,count=0;
    for (i=0;inputString[i]==' ';i++); 
    if (inputString[i]=='\0'){
        return 0;
    }
    for (; inputString[i]!='\0' ; i++){                                         //gets the number of elements in the input string
        if (inputString[i]==' '){
            if (inputString[i+1]!=' '&& inputString[i+1]!='\0'){
             count++;
            }
        }
    }   
    count++;
    //if(i==0){
      //  return 0;
    //}

    return count;

}


char* input(){
	int i;
	char c;
	char* input_string=(char*)malloc(sizeof(char)*1);;
	
	//printf("Enter Something:\n");
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


char* getfinal(char* initialPoint){                                             //returns starting point of the element
    while (*initialPoint!=' '){
        if (*initialPoint=='\0'){
            break;
        }
        initialPoint++;
    }

    return initialPoint;
}


char* getinitial(char* finalPoint){                                             //returns end point of the element
    while (*finalPoint==' '){
        if (*finalPoint=='\0'){
            break;
        }
        finalPoint++;
    }
    
    return finalPoint;
}


void getelement(char* element, char* initial , char* final){                    //stores the element in the "elements" array 
    char* x;
    int i=0;
    for (x=initial;x<final;x++){
        element[i]=*x;
        i++;
    }
    
    element[i]='\0';
}


void getallelements(char elements[][10],char* inputString){
    char* initialPoint;
    char* finalPoint;
    int i;
    for (i=0;inputString[i]==' ';i++); 
    
    
    initialPoint = &inputString[i];
    finalPoint = &inputString[i];
    
    i=0;
    while (*initialPoint!='\0' && *finalPoint!='\0'){                           //iterates over the input string to get the elements
        finalPoint=getfinal(initialPoint);
        getelement(elements[i],initialPoint, finalPoint);
        initialPoint=getinitial(finalPoint);
        i++;           
    }
    
    
}

void filling(int n,int matrix[][n],int* arrayelements,int order,int filler){
    if(order<1){
        return;
    }
    
    else if(order==1){
        int i;
        i=(n-order)/2;
        matrix[i][i]=arrayelements[filler] ;
        return ;
    }
    
    else{
        int first,last,i;
        
        first=(n-order)/2;
        //printf("\nFirst: %d\n",first);
        last=(n+order)/2 -1;
        //printf("\nLast: %d\n",last);
        for (i=first;i<=last-1;i++){
           // printf("\nFilling the element%d in A%d%d\n",arrayelements[filler],first,i);
            matrix[first][i]=arrayelements[filler];
            
            filler++;
        }
        
        for (i=first;i<=last-1;i++){
            matrix[i][last]=arrayelements[filler];
            filler++;
        }
        
        for (i=last;i>first;i--){
            matrix[last][i]=arrayelements[filler];
            filler++;
        }
        
        for (i=last;i>first;i--){
            matrix[i][first]=arrayelements[filler];
            filler++;
        }
        
        filling(n,matrix,arrayelements, order-2,filler);
        
        return;
    }

}


int main(){
    char* inputString;
    char* initialPoint;
    char* finalPoint;
    int i,count=0,order,n,j;
   
    while(1){  
        printf ("Enter a string with space seperated elements:\n");
        inputString = input();
        count = getcount(inputString);
        order = sqrt(count);
        if(order*order!=count){
          printf("\nThe number of elements you entered is %d.Its not a perfect square. Try again!\n\n",count); 
        }
        else{
            break;
        }
    }
    
    
    n=order;
    int matrix[n][n];
    
    int arrayelements[count];
    char elements[count][10];                                                   //resolve
    printf("Number of elements is :%d   \n",count);   
    getallelements(elements,inputString);
   
    printf("The elements you entered are:\n");
    for (i=0;i<count;i++){
        if(atoi(elements[i])==0 && elements[i][0]!='0'){
            printf("\nThe element %s is not a integer or its value is too large for int.\nPlease enter an appropriate value:\n",elements[i]);
            arrayelements[i]=get_integer_value();
           
        }                                                      
        else{
            arrayelements[i]=atoi(elements[i]);
            printf("%d ",arrayelements[i]);
        }
    }
    
    filling(n,matrix,arrayelements,n,0);
    
    printf("\nThe elements in spiral order are:\n");
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");    
    
    }
    
    return 0;
}




