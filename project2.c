#include <stdio.h>
#include <stdlib.h>
double pfr();
void ui(void);

double a;
double b;
double c;
double d;
double e;
double p;
double n;
double nm;
double f;

void main(){
int c;
	
	do{
	
	
	printf("select \n");
	printf("1.rate\n");
	printf("2.Exit");
	scanf("%d",&c);
	switch(c){
		case 1:ui();break;
		case 2:exit(0);
	}
	printf("\n\n");

}while(c<3);
}

void ui(){
	
	//at=acess time et=execution time
	printf("enter a");
	scanf("%lf",&a);
	printf("enter b ");
	scanf("%lf",&b);
	printf("enter c");
	scanf("%lf",&c);
	printf("enter time");
	scanf("%lf",&d);
	printf("enter e");
	scanf("%lf",&e);

	n = (a*1000000);
	nm= (b*1000000);
	f = (d/100);   
	printf(" fault cal for:\n");
	printf("spf=%lf \n",n);
	printf("spf %lf \n",nm);
	printf("mat %lf\n",c);
	printf("eat %lf\n",e);
    p=  pfr(n,nm,c,f,e);
	printf("max apf  = %.2e",p);

}

double pfr(double a,double b,double mem,double t,double e){
double assume,serve;
	double nu,de;
	double pageFault;
	 assume = (1- t)*a;
	 serve = t*b;
	 nu = e - mem;
     de = (assume+serve);

	pageFault = nu/de;
	return pageFault;
}
