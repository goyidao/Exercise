#define MAXOP 100
#define MAXWORD 20
#include"stack.h"
#define NUMBER 1
#define OPERATOR 2
int to_rpn(int op[],int lim);
int getop(char s[]);
int getch();
void ungetch(int c);
