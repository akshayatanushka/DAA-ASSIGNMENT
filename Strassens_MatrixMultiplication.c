#include <stdio.h>

#define MAX 64

void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int n) {
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    int i, j;
    int mid;

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    mid = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];

    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX];
    int M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX];
    int M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    // Divide matrices into four submatrices
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    addMatrix(A11, A22, T1, mid);
    addMatrix(B11, B22, T2, mid);
    strassen(T1, T2, M1, mid);

    // M2 = (A21 + A22)B11
    addMatrix(A21, A22, T1, mid);
    strassen(T1, B11, M2, mid);

    // M3 = A11(B12 - B22)
    subtractMatrix(B12, B22, T2, mid);
    strassen(A11, T2, M3, mid);

    // M4 = A22(B21 - B11)
    subtractMatrix(B21, B11, T2, mid);
    strassen(A22, T2, M4, mid);

    // M5 = (A11 + A12)B22
    addMatrix(A11, A12, T1, mid);
    strassen(T1, B22, M5, mid);

    // M6 = (A21 - A11)(B11 + B12)
    subtractMatrix(A21, A11, T1, mid);
    addMatrix(B11, B12, T2, mid);
    strassen(T1, T2, M6, mid);

    // M7 = (A12 - A22)(B21 + B22)
    subtractMatrix(A12, A22, T1, mid);
    addMatrix(B21, B22, T2, mid);
    strassen(T1, T2, M7, mid);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, T1, mid);
    subtractMatrix(T1, M5, T2, mid);
    addMatrix(T2, M7, T1, mid);

    // C12 = M3 + M5
    addMatrix(M3, M5, T2, mid);

    // C21 = M2 + M4
    addMatrix(M2, M4, T1, mid);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(M1, M2, T2, mid);
    addMatrix(T2, M3, T2, mid);
    addMatrix(T2, M6, T2, mid);

    // Combine the four submatrices
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {

            C[i][j] = T1[i][j];
            C[i][j + mid] = T2[i][j];
            C[i + mid][j] = T1[i][j];
            C[i + mid][j + mid] = T2[i][j];
        }
    }

    // Correct C11, C12, C21, C22
    for (i = 0; i < mid; i++) {
        for (j = 0; j < mid; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + mid] = M3[i][j] + M5[i][j];
            C[i + mid][j] = M2[i][j] + M4[i][j];
            C[i + mid][j + mid] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n, i, j;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("\nResult Matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}