/* INTERPOLACAO DE LAGRANGE
   Sera calculado o polinomio interpolador
   E o mesmo sera usado para interpolar
   
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define m 10 /* Quantidade de dados da tabela */
double ac,aux,p,x[m],y[m],s[m],a[m+1],q[m];
int k,i,n;
char resp;

int main()
{	
/* Leitura da tabela de dados */
 	do {
		printf("\n Digite a quantidade de pontos da tabela:");
		scanf("%d", &n);
		} while (n>m);
	
 	for(i=0;i<n;i++)
		{
		printf("\n Digite a abscissa e a ordenada do ponto número %d da tabela:",i);
		scanf("%lf %lf", &x[i],&y[i]);
		}	
    
    
    a[0]=1;
 	for(i=1;i<=n;i++) a[i]=0.0;
 	
	for(i=0;i < n;i++)
	{
	 	for(k=i+1;k > 0;k--)
 		{
		 a[k]=a[k-1]-a[k]*x[i];
		}
		a[0] = -x[i]*a[0];
	}
	
	for (k=0; k<n; k++) s[k] = 0;
	
	for (i=0; i<n; i++)
	{   
        q[n-1]= a[n];
        if (i != n-1) p=(x[i]-x[n-1]);
        else p = 1;
        
        for(k = n-2; k >= 0; k--)
        {
              if (i != k) p = p*(x[i]-x[k]);
              q[k]= x[i]*q[k+1]+ a[k+1];
        }

	    for (k=0; k<n; k++) s[k] = s[k]+y[i]*q[k]/p;
     }
     
    /* Imprimindo o polinomio interpolador p(x) no tela */

     printf("\n O polinomio de grau %d que mais se ajusta aos dados da tabela eh :\n",n-1);
     printf("\n P(x) = %lf + (%lf)*x",s[0],s[1]);
     for(k=2;k<n;k++) printf("+(%lf)*x^%d",s[k],k);
     printf("\n");
     
     
     do
     {
     printf("\n Entre um valor para x: ");
     scanf("%lf",&aux);
     
     /* Avaliacao do polinomio no ponto x dado */
     ac = s[0]; p=1;
     for (i=1; i<n; i++)
        {
        p = p*aux;
        ac = ac+p*s[i];
        }
     
     printf("\n P(%lf) = %lf\n",aux,ac);
     printf("\n Quer avaliar o polinomio novamente?(s/n)");
     scanf("%s",&resp);
     printf("\n");
     }
     while (resp=='s' || resp=='S');
     return 0;
}	
