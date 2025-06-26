#include<stdio.h>

// Iterative Approach

void main(){
    int base;
    int power;
    int ans = 1;
    int i;

    printf("Enter a Base Number : ");
    scanf("%d", &base);
    printf("Enter a Power Number : ");
    scanf("%d", &power);

    for (i = 1; i <= power; i++)
    {
        ans *= base;
    }

    printf("Ans = %d", ans);
    
}

// Recurive Approach

int powerOfNumber(int base, int power){
    if(power == 0){
        return 1;
    }
    return base * powerOfNumber(base, power - 1);
}

void main(){
    int base;
    int power;

    printf("Enter a Base Number : ");
    scanf("%d", &base);
    printf("Enter a Power Number : ");
    scanf("%d", &power);

    printf("Ans = %d", powerOfNumber(base, power));
}