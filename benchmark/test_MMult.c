#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "parameters.h"

void REF_MMult(int, int, int, float *, int, float *, int, float *, int);
void MY_MMult(int, int, int, float *, int, float *, int, float *, int);
void copy_matrix(int, int, float *, int, float *, int);
void random_matrix(int, int, float *, int);
float compare_matrices(int, int, float *, int, float *, int);
double dclock();

int main()
{
    int p, m, n, k, lda, ldb, ldc, rep;

    float diff;

    double dtime, dtime_best, gflops;

    float *a, *b, *c, *cref, *cold;

    printf("MY_MMult = [\n");

    for (p = PFIRST; p <= PLAST; p += PINC) {
        m = (M == -1 ? p : M);
        n = (N == -1 ? p : N);
        k = (K == -1 ? p : K);

        gflops = 2.0 * m * n * k * 1.0e-09;

        lda = (LDA == -1 ? k : LDA);
        ldb = (LDB == -1 ? n : LDB);
        ldc = (LDC == -1 ? n : LDC);

        /* Allocate space for the matrices */
        a = (float *) malloc(lda * m * sizeof(float));
        b = (float *) malloc(ldb * k * sizeof(float));
        c = (float *) malloc(ldc * m * sizeof(float));
        cold = (float *) malloc(ldc * m * sizeof(float));
        cref = (float *) malloc(ldc * m * sizeof(float));

        /* Generate random matrices A, B, Cold */
        random_matrix(m, k, a, lda);
        random_matrix(k, n, b, ldb);
        random_matrix(m, n, cold, ldc);

        copy_matrix(m, n, cold, ldc, cref, ldc);

        /* Run the reference implementation so the answers can be compared */
        REF_MMult(m, n, k, a, lda, b, ldb, cref, ldc);

        dtime_best = DBL_MAX;

        /* Time the "optimized" implementation */
        for (rep = 0; rep < NREPEATS; rep++) {
            copy_matrix(m, n, cold, ldc, c, ldc);

            /* Time your implementation */
            dtime = dclock();

            MY_MMult(m, n, k, a, lda, b, ldb, c, ldc);

            dtime = dclock() - dtime;

            dtime_best = (dtime < dtime_best ? dtime : dtime_best);
        }

        diff = compare_matrices(m, n, c, ldc, cref, ldc);

        printf("%d %le %f \n", p, gflops / dtime_best, diff);
        fflush(stdout);

        free(a);
        free(b);
        free(c);
        free(cold);
        free(cref);
    }

    printf("];\n");

    exit(0);
}
