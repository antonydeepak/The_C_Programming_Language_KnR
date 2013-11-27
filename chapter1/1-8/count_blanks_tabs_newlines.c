//Book: The C Programming language
//Exercise 1-8
//Problem: Write a program to count blanks,tabs and newlines.

#include <stdio.h>
int main(){
	int nb,nt,nr;
	int c;
	while( (c=getchar()) != EOF){
		if(c=='\n'){
			++nr;
		}
		else if(c=='\t'){
			++nt;
		}
		else if(c==' '){
			++nb;
		}
	}
	printf("blanks:%dtabs:%dreturns:%d",nb,nt,nr);
	return 0;
}
