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
	
	
	printf("Select the required option \n");
	printf("1.Find the PageFault Rate\n");
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
	
	
	printf("\nEnter service Page Fault [Empty|Page is not Modified][in milliseconds]");
	scanf("%lf",&a);
	printf("Enter Service Page Fault [Modified Page][in milliseconds]");
	scanf("%lf",&b);
	printf("Enter Memory Access Time[in nanoseconds]");
	scanf("%lf",&c);
	printf("Enter Percentage of time the page to be replaced is modified[0-100]");
	scanf("%lf",d);
	printf("Enter Effective Access time[in nanoseconds]");
	scanf("%lf",&e);

	n = (a*1000000);
	nm= (b*1000000);
	f = (d/100);   
	printf("\nPage Fault rate calculated For:\n");
	printf("Service Page Fault[Empty|Page Not Modified]=%lf \n",n);
	printf("Service Page Fault [Modified Page][in nanoseconds] %lf \n",nm);
	printf("Memory Access Time[in nanoseconds]%lf\n",c);
	printf("Effective Access Time %lf\n",e);
        p=  page_fault_rate(n,nm,c,f,e);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",p);

}

double page_fault_rate(double a,double b,double memAccess,double timesPages,double effAccess){
double assume,serve;
	double nu,de;
	double pageFault;
	 assume = (1- timesPages)*a;
	 serve = timesPages*b;
	 nu = effAccess - memAccess;
     de = (assume+serve);

	pageFault = nu/de;
	return pageFault;
}
