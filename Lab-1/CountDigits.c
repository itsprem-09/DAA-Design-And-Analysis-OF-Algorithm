#include<stdio.h>

// Iterative method 

void main(){
    int n;
    int count = 0;

    printf("Enter a number : ");
    scanf("%d", &n);

    while(n != 0){
        count += 1;
        n /= 10;
    }

    printf("\nThe number of digits in the given number is %d\n",count);
        
}

// Recursive Method

int countDigit(int n){
    
    if(n < 0){
        n = -n;
    }
    
    if (n < 10){
        return 1;
    }
    
    return 1 + countDigit(n/10);
    
}

void main(){
    int n;

    printf("Enter a number : ");
    scanf("%d", &n);

    printf("\nThe number of digits in the given number is %d\n",countDigit(n));    
}