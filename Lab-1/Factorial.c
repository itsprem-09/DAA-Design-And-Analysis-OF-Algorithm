#include<stdio.h>

// Interative Method

// void main(){
//     int n, i, fact = 1;

//     printf("Enter a number : ");
//     scanf("%d", &n);

//     for(i = n; i >= 1; i--){
//         fact *= i;
//     }

//     printf("\nThe factorial of %d is %d", n, fact);
// }

// Recursive Method

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n - 1);  
}

void main(){
    int n;

    printf("Enter a number : ");
    scanf("%d", &n);

    printf("\nThe factorial of %d is %d", n, factorial(n));
}
