#include <stdio.h>
#include <stdlib.h>
double page_fault_rate();
void userInput(void);

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
	
	
	printf("select the option \n");
	printf("1.find the rate\n");
	printf("2.Exit");
	scanf("%d",&c);
	switch(c){
		case 1:userInput();break;
		case 2:exit(0);
	}
	printf("\n\n");

}while(c<3);
}

void userInput(){
	
	
	printf("enter the value of a");
	scanf("%lf",&a);
	printf("enter the value of b ");
	scanf("%lf",&b);
	printf("enter memory access time");
	scanf("%lf",&c);
	printf("enter Percentage of time ");
	scanf("%lf",d);
	printf("enter effective time");
	scanf("%lf",&e);

	n = (a*1000000);
	nm= (b*1000000);
	f = (d/100);   
	printf("page fault rate calculated for:\n");
	printf("service page fault=%lf \n",n);
	printf("service page fault modified page %lf \n",nm);
	printf("memory access time %lf\n",c);
	printf("effective access time %lf\n",e);
        p=  page_fault_rate(n,nm,c,f,e);
	printf("maximum acceptable page fault  = %.2e",p);

}

double page_fault_rate(double a,double b,double mem,double t,double e){
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
