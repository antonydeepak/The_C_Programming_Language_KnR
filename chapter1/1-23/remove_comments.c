#include<stdio.h>

#define NORMAL 0
#define QUOTED 1
#define COMMENT_1 2
#define COMMENT_2 3
#define POSSIBLE_COMMENT 4
#define POSSIBLE_UNCOMMENT 5

int main(){
	int program_state = NORMAL;
	int c;

	while((c=getchar()) != EOF){
		if(program_state == NORMAL){
			if(c == '/'){
				program_state = POSSIBLE_COMMENT;
			}
			else{
				if(c == '"' || c == 39)
					program_state = QUOTED;
				printf("%c",c);
			}
		}
		else if(program_state == QUOTED){
			if(c == '"' || c == 39)
				program_state = NORMAL;
			printf("%c",c);
		}
		else if(program_state == POSSIBLE_COMMENT){
			if(c == '*'){
				program_state = COMMENT_1;
			}
			else if(c == '/'){
				program_state = COMMENT_2;
			}
			else{
				program_state = NORMAL;
				printf("%c%c",'/',c);
			}
		}
		else if(program_state == COMMENT_1){
			if(c == '*'){
				program_state = POSSIBLE_UNCOMMENT;
			}
		}
		else if(program_state == COMMENT_2){
			if(c == '\n'){
				program_state = NORMAL;
			}
		}
		else if(program_state == POSSIBLE_UNCOMMENT){
			if(c == '/'){
				program_state = NORMAL;
			}
			else{
				program_state = COMMENT_1;
			}
		}
	}
	return 0;
}
