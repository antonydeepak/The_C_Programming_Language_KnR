#include<stdio.h>

#define MAXSYMBOLS 100
#define TRUE 1
#define FALSE 0
#define QUOTED 2
#define COMMENTED 3
#define NORMAL 4

int push(int symbol);
int pop();
int peek();

int symbol_stack[MAXSYMBOLS];
short int p_top_symbol_stack = -1;

int main(){
	int totalLines = 0;
	int charInLine = 0;
	int program_state = NORMAL;

	int c;

	while((c = getchar()) != EOF){
		if(program_state == NORMAL){
			if((c == '{'  || c == '[' || c == '(')){
				if(push(c) == FALSE)
					return -1;
			}
			else if(c == '}'){
				if(peek() == '{'){
					pop();
				}
				else{
					printf("Improper } at line:%d and position:%d\n",totalLines,charInLine);
				}
			}
			else if(c == ']'){
				if(peek() == '['){
					pop();
				}
				else{
					printf("Improper ] at line:%d and position:%d\n",totalLines,charInLine);
				}
			}
			else if(c == ')'){
				if(peek() == '('){
					pop();
				}
				else{
					printf("Improper ) at line:%d and position:%d\n",totalLines,charInLine);
				}
			}
			else if(c == '"' || c ==39){
				program_state = QUOTED;
			}
			else if(c == '*' && prevc == '\\'){
				program_state = COMMENTED;
			}
		}
		else if(program_state == QUOTED){//can't work . this has to move up.
			int a = peek();
			if(c == a){
				pop();

			else
		}
		else if(program_state == COMMENTED){
		}
		charInLine++;
		if(c == '\n'){
			totalLines++;
			charInLine=1;
		}
	}
	if(p_top_symbol_stack != -1){
		printf("%s","There are unclosed braces in the program\n");
		return -1;
	}
	printf("No syntax errors found\n");
	return 0;
}

int push(int symbol){
	if(p_top_symbol_stack + 1>= MAXSYMBOLS){
		printf("operations stack is full\n");
		return FALSE;
	}
	symbol_stack[++p_top_symbol_stack] = symbol;
	return TRUE;
}

int pop(){
	int c = peek();
	if(c == -1)
		return c;
	p_top_symbol_stack--;
	return c;
}

int peek(){
	if(p_top_symbol_stack == -1)
		return -1;
	return symbol_stack[p_top_symbol_stack];
}
