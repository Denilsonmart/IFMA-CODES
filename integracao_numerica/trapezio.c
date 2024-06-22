/* * * * * * * * * * * * * * * * * * */ 
/*   Metodo de Integracao trapézio  */ 
/* * * * * * * * * * * * * * * * * * */ 
#include <stdio.h> 
#include <math.h> 
#include <locale.h>



# define tol 0.00000001

double f(double x) 
{ 
 double y; 
 y = cos(x*x +3); 
 return(y); 
} 

double Integral_Trapezio(double a,double b,int n) 
{ 
 int    i            ; 
 double soma          ; 
 double dx            ; 
 dx   = (b-a)/n; 
 soma = f(a); 
 for(i=1; i < n; i++) { 
          soma = soma + 2*f(a + i*dx);  
  //   printf("\nSoma parcial = %f ",soma); 
} 
 soma = dx/2 * (soma + f(b)); 
 return(soma); 
}  
 
int main() 
{ 
 int   n; 
 double a,b ; 
 double soma, old;
 
 printf("\nEntre o extremo inferior do intervalo: "); 
          scanf("%lf",&a); 
 printf("\nEntre o extremo superior do intervalo: "); 
       scanf("%lf",&b); 
       
    n=2;
	soma = Integral_Trapezio(a,b,n);
	printf("\nIntegral de trapezios com %d pedaços = %15.9f",n,soma); 
	
 do {  
  
  old = soma;

  n=2*n;
       
  soma = Integral_Trapezio(a,b,n); 
 
  printf("\nIntegral de trapezios com %d pedaços = %15.9f",n,soma); 
  
  } while ( fabs(soma-old) > tol);
  
  printf("\n");

return 0;
}