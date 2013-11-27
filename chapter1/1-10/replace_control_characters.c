#include <stdio.h>

//Write a program to copy input to its output, replacing tab, backspace and backslash by \t, \b, and \\ respectively
//NOTE: In modern terminals, you may not be able to see the \b because of the line buffering done by the terminal. This means that a backspace and its  impacted character is already removed from the buffer before reaching your program.
//
int main(){
	int c;
	while((c=getchar()) != EOF){
		if(c == '\t')
			printf("%s","\\t");
		else if(c == '\b'){
			printf("%s","\\b");
		}
		else if(c == '\\')
			printf("%s","\\\\");
		else
			putchar(c);
	}
	return 0;
}
