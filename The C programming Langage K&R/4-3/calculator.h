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

int getch();//buffer������-1�ʹ�bufferȡ������getchar()
void ungetch(int c);//��buffer��ߴ���

void func(char s[]);
