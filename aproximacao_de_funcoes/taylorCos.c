/* * * * * * * * * * * * * * * * * * * ***
**	Serie de Taylor para				**
**	Cálculo do cosseno					**
**	Disciplina de Metodos Numericos		**
**	Professor: Paulo Aleixo				**
**	Data: 21/04/2022					**
**	* * * * * * * * * * * * * * * * * * **/

#include <stdio.h>
#include <math.h>
# define tol 0.000000000000001
# define pi 3.1415926535897932
long double h,xo,y,x,t,s;
int m,n;

int main()
{

printf("\nEntre um angulo em radianos x=");
	scanf("%Lf",&x);
	
//   CALCULO PARA OBTER O ANGULO Y QUE EH CONGRUENTE AO ANGULO X NO INTERVALO [0,2pi)

	y=x-2*pi*floorl(x/(2*pi));			
	
// ENCONTRA O MÚLTIPLO DE pi/2 MAIS PROXIMO DE Y

n= lroundl(2*y/pi);	
xo = n*pi/2;
h=y-xo;


// MOSTRA A SERIE QUE SERA USADA

printf("\n A Serie de taylor do cosseno sera calculada em torno do ponto Xo = %d Pi/2.\n",n);
printf("Usaremos o angulo y = %Lf que esta no intervalo [0,2pi) e é congruente ao seu angulo original x.\n",y);

// DEFINE O PRIMEIRO TERMO DA SERIE DE TAYLOR DO COSSENO EM Xo


if (n%2 == 0) 
	{
		t=1;
		m=0;
		if (lroundl(ceill(n/2))%2 ==1 ) t=-t;		
		s=t;
	}
else
	{
	t=h;
	m=1;
	if (lroundf(ceill(n/2))%2 == 1) t=-t;
	s=t;
	}


// CALCULA A SÉRIE 		

h=h*h;
			
do
	{
	m=m+2;
	t=-t*h/(m*m-m);
	s=s+t;
	}
	
while (fabs(t) > tol);

// APRESENTA O RESULTADO

printf("\n o valor aproximado do cosseno deu %.16Lf.",s);
	
}	