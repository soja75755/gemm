#define A(i, j) a[(i) *lda + (j)]
#define B(i, j) b[(i) *ldb + (j)]
#define abs(x) ((x) < 0.0 ? -(x) : (x))

float compare_matrices(int m, int n, float *a, int lda, float *b, int ldb)
{
    float max_diff = 0.0, diff;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            diff = abs(A(i, j) - B(i, j));
            max_diff = (diff > max_diff ? diff : max_diff);
        }
    }
    return max_diff;
}
