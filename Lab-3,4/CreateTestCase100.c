#include<stdio.h>
#include<stdlib.h>

void main(){
    FILE *file;

    file = fopen("./Testcases/best_100000.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    file = fopen("./Testcases/worst_100000.txt", "w");
    for (int i = 100000; i > 0; i--)
    {
        fprintf(file, "%d ", i);
    }
    fclose(file);

    file = fopen("./Testcases/avg_100000.txt", "w");
    for (int i = 0; i < 100000; i++)
    {
        fprintf(file, "%d ", rand() % 100000);
    }
    fclose(file);
}