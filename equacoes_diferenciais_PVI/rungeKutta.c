#include <stdio.h>
#include <math.h>
#include <stdlib.h>

# define n 10 // quantidade de intervalos iniciais


double x0,xf,t,x,y,h,k1,k2,k3,k4;



double f(double a, double b	)
{
	return a*a+b*b*b;
}

int main(){


printf("\nEntre o valor de x0 e y0 separados por espaço:");
      scanf("%lf %lf",&x0, &t);
      printf("\n");


printf("\nEntre o valor máximo de x:");
	scanf("%lf",&xf);
	printf("\n");
	
h = (xf-x0)/n;
	
do {	
	
x=x0;
y=t;	

printf("X       y\n");

while (x<xf)
{ 
	k1=f(x,y);
	k2=f(x+h*.5,y+h*k1*.5); 
	k3=f(x+h*.5,y+h*k2*.5);
	k4=f(x+h,y+h*k3); 
	y=y+h*(k1+2*k2+2*k3+k4)/6.0;
	x=x+h;

	printf("%lf %lf\n",x,y);
}	
printf("\n Método de runge-kutta de quarta ordem com h=%lf\n",h);

printf("\n Tente outro valor de passo h: ");
	scanf("%lf",&h);
	printf("\n");
	
} while (0<h);

return 0;
}
