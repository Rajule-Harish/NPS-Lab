#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int p,g,a,b,x,y,k1,k2;
    
    pritnf("Enter a prime number p\n");
    scanf("%lld",&p);
    
    pritnf("Enter a genrative prime number g\n");
    scanf("%lld",&g);
    
    pritnf("Enter a private key\n");
    scanf("%lld",&a);
    
    pritnf("Enter a public key\n");
    scanf("%lld",&b);
    
    x=(long long int) pow(g,a)%p;
    y=(long long int) pow(g,b)%p;
    
    pritnf("Private keys x and y are : %d and %d\n Key Exchange vai public Channel...",x,y);
    
    k1=(long long int) pow(y,a)%p;
    k2=(long long int) pow(y,b)%p;
    
    pritnf("Shared keys k1 and k2 are : %d and %d\n ",k1,k2);
    
    if(k1==k2)
        pritnf("Key Exchange succesfull\n");
    else
        pritnf("Key Exchange unsuccesfull\n");
    
    return 0;
    
}
