#include<stdio.h>

#define TABSTOP 8

int main(){
	int c;
	unsigned int blanks,spaces,cols;
	cols=blanks=spaces0;

	while((c = getchar()) != EOF){
		if(c == ' ')
			++blanks;
		else{
			while(blanks > 0 && blanks > TABSTOP - (cols % TABSTOP)){
				spaces = TABSTOP - (cols % TABSTOP);
				blanks -= spaces;
				cols += spaces;
				putchar('\t');
			}
			while(blanks > 0){
				--blanks;
				++cols;
				putchar(' ');
			}
			++cols;
			putchar(c);
			if(c == '\n')
				cols=0;
		}
		
	}
	return 0;
}
