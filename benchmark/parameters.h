/*
 * In the test driver, there is a loop "for ( p=PFRIST; p<=PLAST; p+=PINC )"
 * The below parameters set this range of values that p takes on
 */
#define PFIRST 40
#define PLAST 800
#define PINC 40

/*
 * In the test driver, the m, n, and k dimensions are set to the below
 * values. If the values equals "-1" then that dimension is bound to the
 * index p, given above
 */
#define M -1
#define N -1
#define K -1

/*
 * In the test driver, each experiment is repeated NREPEATS times and
 * the best time from these repeats is used to compute the performance
 */
#define NREPEATS 2

/*
 * Matrix A, B, and C are stored in two dimensional arrays with
 * row dimensions that are greater than or equal to the column dimension
 * of the matrix. This column dimension of array is known as the
 * "leading dimension" and determines the stride (the number of
 * float point numbers) when one goes from one element in a column
 * to the next. Having this number larger than the column dimension of
 * the matrix tends to adversely affect performance. LDX equals the
 * leading dimesion of the array that stores matrix X. If LDX=-1
 * then the leading dimesion is set to the column dimension of matrix X.
 */
#define LDA 1000
#define LDB 1000
#define LDC 1000
