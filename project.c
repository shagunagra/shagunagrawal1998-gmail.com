#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
int a=0;
long f[500];
int i;
void *fun(void *b)
{
if(a<=0)
pthread_exit(0);
f[0]=0;
if(a>1)
{
f[1]=1;
for(i=2;i<a;i++)
f[i]=f[i-1]+f[i-2];
}
pthread_exit(0);
}

int main(int c, char *cf[])
{
pthread_t id;
pthread_attr_t attr;
pthread_attr_init(&attr);
printf("Enter the number of Fibonacci series: ");
scanf("%d",&a);
if(a>500)
{
printf("Printing upto 500 only");
a=500;
}
pthread_create(&id, &attr, fun, cf[1]);
pthread_join(id,NULL);
if(a>0)
printf("%ld",f[0]);
for(i=1;i<a;i++)
printf(",%ld",f[i]);
printf("\n");
return 0;
}
