#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_LEN 13

int is_number(char *str);
int is_operation(char *str);

void read_word(char *str);

int main(){
	char str[MAX_LEN]; 
	read_word(str);
	while(str[0]!='\0'){
		if(is_operation(str)){
			// ...
		}

	}
	return 0;
}
void read_word(char *str){
	int p=0;
	char ch;

	int b=0; //boolean variable check multiple spaces
	while(scanf("%c",&ch)==1){
		if(b && ch==' '){
			b=0;
			break;
		}
		if(ch!=' '){
			if(p>=MAX_LEN-1){
				fprintf(stderr,
				    "Calculator error : Number is too long");
				exit(1);
			}
			b=1;
			str[p]=ch;
			p++;
		}
	}
	str[p]='\0'; // end of line
}

int is_operation(char *str){
	// ...
}
