/* ********************************
   Programa da bisseccao 
   Disciplina de Metodos Numericos
   Professor: Paulo Aleixo
   Data: 14/09/2016
   ************************************ */
   
#include <stdio.h>
#include <math.h>

#define erro 0.000001

int i=0;
double a,b,c;

// Abaixo está a definição da função
double p(double x)
{
       return sin(x);
}

int main()
{
      printf("\nEntre o intervalo [a,b] no qual existe uma raiz:");
      scanf("%lf %lf",&a, &b);
      printf("\n");
      
      while (b-a > erro) 
      {
            i++;
            c = 0.5*(b+a);
            if (p(b)*p(c) < 0.0 ) a=c;
            else b=c;
            printf("Na iteracao %d o valor de C eh %lf\n",i,c);
      }
      
      printf("\nO valor estimado da raiz eh %lf\n", c);
      printf("Com erro de %lf\n", erro);
}      