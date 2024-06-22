/* * * * * * * * * * * * * * * * * * * ***
**	Serie de Taylor para				**
**	Cálculo do logaritmo natural		**
**	Disciplina de Metodos Numericos		**
**	Professor: Paulo Aleixo				**
**	Data: 16/04/2022					**
**	* * * * * * * * * * * * * * * * * * **/

#include <stdio.h>
#include <math.h>
# define tol 0.0000001

double h,y,x,p,t,s;
int n;

int main()
{	
	printf("\nEntre um número x=");
	scanf("%lf",&x);
	
	if (x>=2) 
		{
			y=1/x;
		}
	else
		{
			y=x;
		}
			
				
	printf("\n Vamos calcular o logaritmo do valor y=%lf  \n",y);

	h=(y-1)/(y+1);
	n=1;
	s=h;
	p=h;
	
	
//  calcula a soma da serie de taylor para y	
	do {
		n=n+2;
		p=h*h*p;
		t=p/n;
		s=s+t;
		printf("\n A soma da serie com n=%d foi %lf",n,2*s);		
		}
	while (fabs(t)>tol);
	
	// escreve o resultado do logaritmo de x

	if (x>=2) printf("\n\n A exponencial de x aproximada por Taylor: %lf \n", -2*s);
	
}	