#include<stdio.h>

#define TABSTOP 8

int main(){
	unsigned int i;
	unsigned int col,spaces;
	int c;

	while((c = getchar()) != EOF){
		if(c == '\t'){
			spaces = TABSTOP - (col%TABSTOP);
			for(i=0;i<spaces;i++)
				putchar(' ');
			col += spaces;
		}
		else if(c == '\n'){
			col=0;
		}
		else{
			putchar(c);
			++col;
		}
	}

	return 0;
}
