#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
extern void saxpy_asm(int n, float a, float *x, float *y, float *z);

void saxpy_c(int n, float a, float *x, float *y, float *z) {
    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + y[i];
    }
}
int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

float average_time(int n, double* times) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += times[i];
    }
    printf("Average time: %lf seconds", sum / n);
    return sum / n;
}

void doProblem()
{
    // Your code here
    int vector_size[3] = { 20, 24, 29 };
    int loop = 30;
    int error = 0;
    int iter = 0;
    long double avg_asm[3] = { 0.0f, 0.0f, 0.0f };
    long double avg_c[3] = { 0.0f, 0.0f, 0.0f };
    clock_t start = -1;
    clock_t stop = -1;

    int n = 0;
    float a = 0.0f;


    int i = 0;
    for (iter = 0; iter < 3; iter++) {
        volatile float* x;
        volatile float* y;
        volatile float* z_asm;
        volatile float* z_c;
        volatile long double* times_asm;
        volatile long double* times_c;
        printf("Iteration: %d\n", iter);
        n = ipow(2, vector_size[iter]);
        printf("Vector size: 2^%d(%d)\n", vector_size[iter], n);

        a = (float)rand() / (float)(RAND_MAX);
        printf("A: %f\n", a);

        x = (float*)malloc(n * sizeof(float));
        y = (float*)malloc(n * sizeof(float));
        z_asm = (float*)malloc(n * sizeof(float));
        z_c = (float*)malloc(n * sizeof(float));

        for (i = 0; i < n; i++) {
            x[i] = (float)rand() / (float)(RAND_MAX)*a;
            y[i] = (float)rand() / (float)(RAND_MAX)*a;
        }

        times_asm = (long double*)malloc(loop * sizeof(long double));
        times_c = (long double*)malloc(loop * sizeof(long double));

        printf("C Running Times\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        for (i = 0; i < loop; i++) {
            start = clock();
            saxpy_c(n, a, x, y, z_c);
            stop = clock();
            printf("| Trial %02d | Start Time: %05ld | Stop Time: %05ld |\n", i + 1, start, stop);
            times_c[i] = ((long double)(stop - start)) / CLOCKS_PER_SEC;
            if (i != loop - 1) {
                free(z_c);
                z_c = (float*)malloc(n * sizeof(float));
            }
        }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        avg_c[iter] = average_time(loop, times_c);
        printf("\n");
        printf("ASM Running Times\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        for (i = 0; i < loop; i++) {
            start = clock();
            saxpy_asm(n, a, x, y, z_asm);
            stop = clock();
            printf("| Trial %02d | Start Time: %05ld | Stop Time: %05ld |\n", i + 1, start, stop);
            times_asm[i] = ((long double)(stop - start)) / CLOCKS_PER_SEC;
            if (i != loop - 1) {
                free(z_asm);
                z_asm = (float*)malloc(n * sizeof(float));
            }
        }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        avg_asm[iter] = average_time(loop, times_asm);
        printf("\n");

        //Sanity check for the values
        for (i = 0; i < n; i++) {
            if (z_asm[i] != z_c[i]) {
                printf("Error, one of the functions is wrong.\n");
                error = 1;
                break;
            }
        }

        if (error == 1) {
            break;
        }
        else {
            printf("All values have been validated.\n");
        }

        free(x);
        free(y);
        free(z_asm);
        free(z_c);
        free(times_asm);
        free(times_c);

        printf("Values have been freed.\n\n");

    }
    printf("Performance Summary: \n");
    for (i = 0; i < 3; i++) {
        printf("Vector size 2^%d\n", vector_size[i]);
        printf("ASM: %lf\n", avg_asm[i]);
        printf("C: %lf\n", avg_c[i]);
        if (avg_asm[i] < avg_c[i]) {
            printf("ASM is faster than C by %lf seconds\n", avg_c[i] - avg_asm[i]);
        }
        else {
            printf("C is faster than ASM by %lf seconds\n", avg_asm[i] - avg_c[i]);
        }

        printf("Sanity check: ");
        if (error == 1) {
            printf("Failed\n");
        }
        else {
            printf("Passed\n");
        }
        printf("\n");
    }
}


int main() {
    srand(time(NULL));

    doProblem();
    return 0;
}
