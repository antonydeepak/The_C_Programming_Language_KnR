#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 7 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
	int len;            /* current line length */
	int overflow_len;            /* total line length */
	int max;            /* maximum length seen so far */
	char line[MAXLINE];     /* current input line */
	char longest[MAXLINE];  /* longest line saved here */

	max = overflow_len = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
		if (len == MAXLINE-1 && line[MAXLINE-1] == '\0') /*line still continues*/
			overflow_len += len;
		else if(overflow_len > 0){
			if(overflow_len + len > max)
				max = overflow_len + len;
			overflow_len = 0;
		}	
	}
	if (max > 0) {   /* there was a line */
		printf("%s\n", longest);
		printf("%d\n",max);
	}
	return EXIT_SUCCESS;
}

/* get_line:  read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
