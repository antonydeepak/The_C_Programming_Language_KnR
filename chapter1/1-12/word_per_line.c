#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
	int c;
	int PRINT = FALSE;
	while((c = getchar()) != EOF){
		if(c == '\n' || c == '\t' || c == ' '){
			if(PRINT == TRUE)
				printf("\n");
			PRINT = FALSE;
		}
		else{
			PRINT = TRUE;
			printf("%c",c);
		}
	}
	return 0
}
