#include <stdio.h>
#include <stdlib.h>

unsigned short fields[9];

unsigned short checksum()
{
    int sum = 0;

    printf("Enter the fields.\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%x", &fields[i]);
        sum = sum + (unsigned short)fields[i];
        
        while (sum >> 16)  //add carry bit
            sum = (sum & 0xFFFF) + (sum >> 16);
    }
    
    sum = ~sum;
    
    return (unsigned short)sum;
}

int main()
{
    unsigned short result1, result2;
    
    result1 = checksum();
    printf("Result1 = %x\n", result1);
    
    result2 = checksum();
    printf("\nResult2 = %x\n\n", result2);
    
    if (result1 == result2)
        printf("No error.\n");
    else
        printf("Error.\n");
        
    return 0;
}
