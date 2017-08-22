#define MAXLINES 1000
#define MAXLEN 100
#define AVAIL 5000
int readlines(char *lineptr[],char *linestor,int maxline);
void writelines(char *lineptr[],int linenum);
void lineqsort(char *lineptr[],int low,int high);
char * alloc(int n);
void afree(char * p);
int getline(char *line,int lim);
