/* ********************************
   Programa do metodo de Newton 
   Disciplina de Metodos Numericos
   Professor: Paulo Aleixo
   Data: 29/09/2016
   ************************************ */
   
#include <stdio.h>
#include <math.h>

#define erro 0.000001  /* erro absoluto*/

int i; 

double xo, xi; /* Pontos consecutivos da iteracao */ 

int resp;

double p(double x) /* função que será zerada */
{
       return x*x*x+x*x+1;
}

double dp(double x) /* a derivada da função que será zerada */
{
       return 3*x*x + 2*x;
}

int main()
{
	do
	  {
      printf("\n Entre com a primeira aproximacao da raiz:");
      scanf("%lf",&xi);
      i = 0;
      do
      {
      printf("\n O valor de x(%d) = %lf\n",i, xi);
      i++;
      xo = xi;
      xi = xo - (p(xo)/dp(xo));
      }
      while (fabs(xo-xi) > erro);
      
      printf("\nO valor da raiz eh %lf\n", xi);
      printf("\nCom erro de %lf\n", erro);
      
      printf("\n Quer tentar outra vez?(s/n)");
      scanf("%s",&resp);
      }
      while (resp=='s' || resp=='S');
}
      

