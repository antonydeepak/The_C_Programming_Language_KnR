#include<stdio.h>

#define QUOTED_SINGLE 0
#define QUOTED_DOUBLE 1
#define COMMENTED 2
#define NORMAL 4

int main(){
	int c,prevc;
	int paranthesis_count = 0;
	int program_state = NORMAL;

	while((c = getchar()) != EOF){
		
		if(program_state == NORMAL){
			if(c == '[' || c == '{' || c == '('){
				paranthesis_count++;
			}	
			else if(c == ']' || c == '}' || c == ')'){
				paranthesis_count--;
			}
			else if(c == 39){
				program_state = QUOTED_SINGLE;
			}
			else if(c == '"'){
				program_state = QUOTED_DOUBLE;
			}
			else if(prevc == '/' && c == '*'){
				program_state = COMMENTED;
			}
		}
		else if(program_state == QUOTED_SINGLE){
			if(c == 92){ /* \ */
				int nextc = getchar();
				if(nextc == EOF)
					break;
				else
					continue;
			}
			if( c== 39){
				program_state = NORMAL;
			}
		}
		else if(program_state == QUOTED_DOUBLE){
			if(c == 92){ /* \ */
				int nextc = getchar();
				if(nextc == EOF)
					break;
				else
					continue;
			}
			if( c== '"'){
				program_state = NORMAL;
			}
		}
		else if(program_state == COMMENTED){
			if(prevc == '*' && c == '/')
				program_state == NORMAL;
		}
		
		prevc = c;
	}

	if(paranthesis_count != 0)
		printf("one of the braces mismatch");

	if(program_state == QUOTED_DOUBLE){
		printf("double quotes not closed");
	}
	else if(program_state == QUOTED_SINGLE){
		printf("single quotes not closed");
	}
	else if(program_state == COMMENTED){
		printf("open comment");
	}
	else{
		printf("No syntax errors");
	}
}
