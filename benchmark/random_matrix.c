#define A(i, j) a[(i) *lda + (j)]

void random_matrix(int m, int n, float *a, int lda)
{
    double drand48();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A(i, j) = (float) 2.0 * drand48() - 1.0;
        }
    }
}
