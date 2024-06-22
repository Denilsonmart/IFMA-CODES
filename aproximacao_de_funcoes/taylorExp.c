/* * * * * * * * * * * * * * * * * * * ***
**	Serie de Taylor para				**
**	Cálculo da Exponencial				**
**	Disciplina de Metodos Numericos		**
**	Professor: Paulo Aleixo				**
**	Data: 16/04/2022					**
**	* * * * * * * * * * * * * * * * * * **/

#include <stdio.h>
#include <math.h>
# define tol 0.000000001

double y,x,t,s;
int m,n;

int main()
{	
	printf("\nEntre um número x=");
	scanf("%lf",&x);
	
	y=x;
	m=0;
	n=0;
	t=1;
	s=1;
	
// Encontrar o m tal que 2^m > x e reescalonar y=x/(2^m)	
	while (fabs(y) >= 1) 
		{ m++;
		y=y/2;
		};
		
	printf("\n O valor y=%lf depois de dividir o x por dois %d vezes. \n",y,m);
	
//  calcula a soma da serie de taylor para y	
	do {
		n++;
		t=y*t/n;
		s=s+t;
		printf("\n A soma da serie com n=%d foi %lf",n,s);		
		}
	while (fabs(t/s)>tol);
	
// calcula a exponecial para x

	for(n=1; n<=m;n++) s=s*s;
	
// escreve o resultado da exponencial de x

	printf("\n\n A exponencial de x aproximada por Taylor: %lf \n", s);
	
}	