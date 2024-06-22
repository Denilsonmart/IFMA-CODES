/* * * * * * * * * * * * * * * * * * */ 
/*   Metodo  Integracao simpson 1/3  */ 
/* * * * * * * * * * * * * * * * * * */ 

#include <stdio.h> 
#include <math.h> 
#include <locale.h>



# define tol 0.000000001

// Funcao que sera integrada
double f(double x) 
{ 
 double y; 
 y = cos(x*x +3); 
 return(y); 
} 

// Regra de simpson 1/3
double Integral_Simpson(double a,double b,int n) 
{ 
 int    i            ; 
 double soma          ; 
 double dx            ; 
 dx   = (b-a)/n; 
 soma = f(a); 
 for(i=1; i < n; i++) { 
  if ((i%2) == 1) 
                soma = soma + 4*f(a + i*dx); 
  else 
      soma = soma + 2*f(a + i*dx); 
 } 
 soma = dx/3 * (soma + f(b)); 
 return(soma); 
} 

int main() 
{ 
 int   n; 
 double a,b; 
 double soma, old; 
 
 
 
  printf("\nEntre o extremo inferior do intervalo: "); 
  scanf("%lf",&a); 
  printf("\nEntre o extremo superior do intervalo: "); 
  scanf("%lf",&b); 
  n=1;
  soma = Integral_Simpson(a,b,n);

 do {  
  
  	old = soma;

  	n=2*n;
  
	soma = Integral_Simpson(a,b,n); 
     
  	printf("\nIntegral de simpson com %d pedaços = %15.9f",n,soma); 
      
    } while( fabs(soma-old) > tol);

   printf("\n");

}