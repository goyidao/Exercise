#define NUMBER 0
#define NAME 1

int getop(char s[]);//从输入取操作数或者操作符

void push(double operand);//压栈
double pop();//弹站 
int isempty();
void printtop();
double gettop();
void swaptop();
void clearstack();

int getline(char s[],int lim);
void ungets(char s[]);

void func(char s[]);
