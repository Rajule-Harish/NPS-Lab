#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[4];
    
    printf("Enter the 4 bit data.\n");
    for (int i = 3; i >= 0; i--)
        scanf("%d", &data[i]);
    
    int r0 = (data[0] + data[1] + data[3]) % 2; // 0, 1, 3
    int r1 = (data[0] + data[2] + data[3]) % 2; // 0, 2, 3
    int r2 = (data[1] + data[2] + data[3]) % 2; // 1, 2, 3
    
    printf("\nCode word is: ");
    for (int i = 3; i >= 0; i--)
        printf("%d", data[i]);
    printf("%d", r2);
    printf("%d", r1);
    printf("%d", r0);
    printf("\n\n");
    
    int codeword[7];
    printf("\nEnter received code word\n");
    for (int i = 6; i >= 0; i--)
        scanf("%d", &codeword[i]);
    
    data[3] = codeword[6];
    data[2] = codeword[5];
    data[1] = codeword[4];
    data[0] = codeword[3];
    
    
    int s0 = (data[0] + data[1] + data[3] + r0) % 2;
    int s1 = (data[0] + data[2] + data[3] + r1) % 2;
    int s2 = (data[1] + data[2] + data[3] + r2) % 2;
    
    int errorBit = (s0 * 1) + (s1 * 2) + (s2 * 4);
    
    if (errorBit == 0)
        printf("\nNo error.\n");
    else
        printf("\nError in bit %d\n", errorBit);
        
    return 0;
}
