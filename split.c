#include <stdio.h>

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


int main(){
    char inputString[100];
    char* initialPoint;
    char* finalPoint;
    int i,count=0;
    
      
    printf ("Enter a string with space seperated elements:\n");
    scanf ("%[^\n]%*c",inputString);
    
        
    for (i=0;inputString[i]==' ';i++);                                          //used to get the starting poit of the first element
    
    initialPoint = &inputString[i];
    finalPoint = &inputString[i];
    
    for (; inputString[i]!='\0' ; i++){                                         //gets the number of elements in the input string
        if (inputString[i]==' '){
            if (inputString[i+1]!=' '&& inputString[i+1]!='\0'){
             count++;
            }
        }
    }   
    count++;
    
    i=0;
    char elements[count][10];
    
    while (*initialPoint!='\0' && *finalPoint!='\0'){                           //iterates over the input string to get the elements
        finalPoint=getfinal(initialPoint);
        getelement(elements[i],initialPoint, finalPoint);
        initialPoint=getinitial(finalPoint);
        i++;           
    }

    for (i=0;i<count;i++){                                                      
        printf("%s\n",elements[i]);
    }

    return 0;
}
