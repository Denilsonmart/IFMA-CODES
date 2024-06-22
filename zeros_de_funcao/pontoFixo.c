/* ************************************
   Programa do metodo de Ponto fixo 
   Prof: Paulo Aleixo
   Data: 25/07/2016
   ************************************ */
   
#include <stdio.h>
#include <math.h>

#define tol 0.000001 /* tolerancia ou erro relativo */
#define max 100 /* Numero maximo de iteracoes */

int i;
double xo, xi; /* Pontos consecutivos da iteracao */ 
int resp;



double p(double x) /* funcao que tem um ponto fixo */
{
       return -pow(1+x*x,0.333333);
}

int main()
{
      
      do
      {
      printf("\n Entre com a primeira aproximacao do ponto fixo: ");
      scanf("%lf",&xi);
      i=0;
         do
         {
         printf("\n O valor de x(%d) = %lf\n",i, xi);
         i++;
         xo = xi;
         xi = p(xo);
         }
         while (fabs(xo-xi) > fabs(tol*xo) && i<max);
      
      if (i==max) 
           {
           printf("\n O metodo nao convergiu!\n");
           
           }
      else {
           printf("\n O metodo convergiu!\n");
           printf("\nO valor do ponto fixo eh %lf\n", xi);
           printf("\nCom erro relativo de %lf\n", tol);
           }   
      printf("\n Quer tentar outra vez?(s/n)");
      scanf("%s",&resp);
      
      }
      while (resp=='s' || resp=='S');
}
      