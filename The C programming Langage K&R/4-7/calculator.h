#define NUMBER 0
#define NAME 1

int getop(char s[]);//������ȡ���������߲�����

void push(double operand);//ѹջ
double pop();//��վ 
int isempty();
void printtop();
double gettop();
void swaptop();
void clearstack();

int getline(char s[],int lim);
void ungets(char s[]);

void func(char s[]);
