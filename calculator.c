#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "stack.h"

#define MAX_LEN 11

int is_number(char *str);
int is_operation(char *str);

void operate(char *str);
STACK_TYPE str2number(char *str); // convert string to STACK_TYPE

void read_word(char *str);

int main(){
	char str[MAX_LEN]; 
	read_word(str);

	while(str[0]!='\0'){
		if(is_operation(str)){
			operate(str); // perform operation in str
		}
		else if(is_number(str)){
			put_stack(str2number(str));
		}
		else{
			fprintf(stderr,
				"E:Calculator Error : Wrong operand \"%s\"\n",
				str);
			exit(1);
		}
		read_word(str);
	}
	printf("%d\n",pop_stack());
	if(!is_stack_empty())
		fprintf(stderr,
		"W:Calculator warning : Stack is not empty. Too many numbers?\n");
	return 0;
}
void read_word(char *str){
	int p=0;
	char ch;

	int b=0; //boolean variable check multiple spaces
	while(scanf("%c",&ch)==1){
		if(b && (ch==' ' || ch=='\n')){
			b=0;
			break;
		}
		if(ch!=' '){
			if(p>=MAX_LEN-1){
				fprintf(stderr,
				    "E:Calculator error : Number is too long\n");
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
	if(str[0]=='+' && str[1]=='\0')
		return 1;
	else if(str[0]=='-' && str[1]=='\0')
		return 1;
	else if(str[0]=='*' && str[1]=='\0')
		return 1;
	else if(str[0]=='/' && str[1]=='\0')
		return 1;
	else if(str[0]=='~' && str[1]=='\0')
		return 1;
	else
		return 0;
}
int is_number(char *str){
	int i;
	for(i=0;str[i]!='\0';i++)
		if(str[i]<'0' || str[i]>'9')
			return 0;
	return 1;
}


// Magic don't touch
// See 'https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html'
int operate_with_overflow(char op,int* res, ...){
	va_list args;
	va_start(args,res);
	int a,b;
	int OF=0;
	switch(op){
	case '+':
		a=va_arg(args,int);
		b=va_arg(args,int);
		if(OF=__builtin_add_overflow(a,b,res))
			fprintf(stderr,
			"W:Calculator warning : Overflow while summation\n");
		break;
	case '-':
		a=va_arg(args,int);
		b=va_arg(args,int);
		if(OF=__builtin_sub_overflow(a,b,res))
			fprintf(stderr,
			"W:Calculator warning : Overflow while subtraction\n");
		break;
	case '*':
		a=va_arg(args,int);
		b=va_arg(args,int);
		if(OF=__builtin_mul_overflow(a,b,res))
			fprintf(stderr,
			"W:Calculator warning : Overflow while multiplication\n");
		break;
	case '~':
		a=va_arg(args,int);
		if(a==-2147483648){
			fprintf(stderr,
			"W:Calculator warning : Overflow while negativation\n");
			OF=1;
		}
		*res=-a;
		break;
	default: // Newer should be happen
		fprintf(stderr,
		"E:INTERNAL ERROR in operate_with_overflow : wrong operation '%c'\n",
		op);
	}
	return OF;
}

void operate(char *str){ // perform operation from str
	int a,b;
	int res;
	if     (str[0]=='+' || str[0]=='-' || str[0]=='*'){
		b=pop_stack();
		a=pop_stack();
		operate_with_overflow(str[0],&res,a,b);
		put_stack(res);
	}
	else if(str[0]=='/'){ // There can't be overflow
		b=pop_stack();
		a=pop_stack();
		put_stack(a/b);
	}
	else if(str[0]=='~'){
		a=pop_stack();
		operate_with_overflow(str[0],&res,a);
		put_stack(res);
	}
}

STACK_TYPE str2number(char *str){
#if STACK_TYPE==int
	int num=atoi(str);
	if(num<0)
		fprintf(stderr,"W:Calculator warning : Overflow while input\n");
	return num;
#elif STACK_TYPE==double
	return atof(str);
#else
#error Error STACK_TYPE not defined, or defined wrong
#endif
}
