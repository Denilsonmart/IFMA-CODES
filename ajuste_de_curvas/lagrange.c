/* INTERPOLACAO DE LAGRANGE
 * 
 * Prof.: Paulo Aleixo
 * Data: 23/04/2014
 * Disciplina de Cálculo Numérico
 * Descrição:
   Para usar o programa em tabelas com mais de 10
   pontos, deve-se alterar a constante M diretamente
   no código fonte abaixo 
   * 
   * 
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 10 /* Quantidade máxima de dados da tabela */
double somatorio, produtorio, aux,x[M],y[M];
int i,j,n;
char resp;


int main()
{	
 	/* Leitura da tabela de dados */
 	do {
		printf("\n Digite a quantidade de pontos da tabela:");
		scanf("%d", &n);
		} while (n>10);
	
 	for(i=0;i<n;i++)
		{
		printf("\n Digite a abscissa e a ordenada do ponto número %d da tabela:",i);
		scanf("%lf %lf", &x[i],&y[i]);
		}	

    
      /* Avaliacao do polinomio no ponto x dado */
     do {
		printf("\n Entre um valor para x: ");
		scanf("%lf",&aux);
		
		somatorio = 0;
		for (i=0; i<n; i++)
        {
		produtorio=1;
		for (j=0; j<n; j++)
		{ 
			if (i !=j) produtorio = produtorio*(aux-x[j])/(x[i]-x[j]);
		}
			
        somatorio = somatorio+produtorio*y[i];
        }
     
     
     printf("\n P(%lf) = %lf\n",aux,somatorio);
     
     printf("\n Quer avaliar o polinomio novamente?(s/n)");
     scanf("%s",&resp);
     printf("\n");
     }
     while (resp=='s' || resp=='S');
     
     return 0;
     
}	
