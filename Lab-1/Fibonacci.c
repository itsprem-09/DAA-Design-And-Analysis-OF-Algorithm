#include<stdio.h>

// Iterative Approach

// void main(){
//     int n;
//     int first = 0;
//     int second = 1;
//     int i;
//     int sum = 0;

//     printf("Enter number of terms : ");
//     scanf("%d", &n);
    
//     int ans[n];

//     ans[0] = first;
//     ans[1] = second;

//     for (i = 2; i <= n; i++)
//     {
//         sum = first + second;
//         ans[i] = sum;
//         first = second;
//         second = sum;
//     }

//     for (i = 0; i < n; i++)
//     {
//         printf("%d, ", ans[i]);
//     }
     
// }  

// Recursive Approach

int fibonacci(int n) {
    if (n <= 1)
        return n; // Base case: fibonacci(0) = 0, fibonacci(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main(){
    int n;

    printf("Enter number of terms : ");
    scanf("%d", &n);

    printf("Fibonacci Series using Recursion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}