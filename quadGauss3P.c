/* * * * * * * * * * * * * * * * * * * * */ 
/*   Quadratura Gaussiana com 3 pontos   */ 
/* * * * * * * * * * * * * * * * * * * * */ 

#include <stdio.h> 
#include <math.h> 

# define tol 0.00000001
# define p 0.774596669
#include <locale.h>



// Funcao que sera integrada
double f(double x) 
{ 
 double y; 
 y = cos(x*x + 3); 
 return(y); 
} 

// Quadratura gaussiana simples com 3 pontos
double Quad_Gauss(double a,double b) 
{ 
 double soma          ; 
 double c,d           ; 
 
 c= (b-a)/2;
 
 d = (b+a)/2;
 
 soma = c*(5*f(-p*c+d)+8*f(d)+5*f(p*c+d))/9;
 
 return (soma);
}
 



int main() 
{    
 int   n,i; 
 double a,b, dx; 
 double soma, old; 
 
 
 
  printf("\nEntre o extremo inferior do intervalo: "); 
  scanf("%lf",&a); 
  printf("\nEntre o extremo superior do intervalo: "); 
  scanf("%lf",&b); 
  n=1;
  soma = Quad_Gauss(a,b);
  printf("\nIntegral de Gauss com %d pedaços = %15.9f",n,soma); 

 do {  
  
  	old = soma;

  	n=2*n;
  	dx= (b-a)/n;
    soma = 0;  
	for(i=0; i < n; i++) soma += Quad_Gauss(a+i*dx,a+(i+1)*dx);
     
  	printf("\nIntegral de Gauss com %d pedaços = %15.9f",n,soma); 
      
    } while( fabs(soma-old) > tol);

   printf("\n");

}