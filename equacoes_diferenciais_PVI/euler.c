#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double x,y,z,h;

// DEFINIÇÃO DA FORMULA F(X,Y) QUE APARECE NA EDO Y'=F(X,Y)
double f(double a, double b	)
{
	return a*b+b;
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
	y=y+h*f(x,y);
	x=x+h;

	printf("%lf %lf\n",x,y);
}	
printf("Método de Euler com h=%lf\n",h);
return 0;
}
