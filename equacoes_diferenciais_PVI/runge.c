#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double x,y,z,h,k1,k2,k3,k4;

double f(double a, double b	)
{
	return 1.05*(b-a);
}

int main(){


printf("\nEntre o valor de x0 e y0 separados por espaço:");
      scanf("%lf %lf",&x, &y);
      printf("\n");

printf("\nEntre o valor do passo h:");
	scanf("%lf",&h);
	printf("\n");

printf("\nEntre o valor máximo de x:");
	scanf("%lf",&z);
	printf("\n");

printf("X       y\n");
printf("%lf %lf\n",x,y);

while (x<z)
{ 
	k1=f(x,y);
	k2=f(x+h*.5,y+h*k1*.5); 
	k3=f(x+h*.5,y+h*k2*.5);
	k4=f(x+h,y+h*k3); 
	y=y+h*(k1+2*k2+2*k3+k4)/6.0;
	x=x+h;

	printf("%lf %lf\n",x,y);
}	
printf("\n Método de runge com h=%lf\n",h);
return 0;
}
