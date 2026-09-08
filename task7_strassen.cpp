#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix createMatrix(int n)
{
    return Matrix(n, vector<int>(n, 0));
}

Matrix addMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtractMatrix(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Standard naive multiplication (used for verification)
Matrix naiveMultiply(const Matrix& A, const Matrix& B)
{
    int n = A.size();
    Matrix C = createMatrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

// Get a quadrant of a matrix
Matrix getQuadrant(const Matrix& M, int row, int col, int size)
{
    Matrix Q = createMatrix(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            Q[i][j] = M[row+i][col+j];
    return Q;
}

// Set a quadrant of a matrix
void setQuadrant(Matrix& M, const Matrix& Q, int row, int col)
{
    int size = Q.size();
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            M[row+i][col+j] = Q[i][j];
}

// Strassen's algorithm for 2^n x 2^n matrices
Matrix strassenMultiply(const Matrix& A, const Matrix& B)
{
    int n = A.size();

    // Base case
    if (n == 1)
    {
        Matrix C = createMatrix(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int h = n / 2;

    // Split into quadrants
    Matrix A11 = getQuadrant(A, 0, 0, h);
    Matrix A12 = getQuadrant(A, 0, h, h);
    Matrix A21 = getQuadrant(A, h, 0, h);
    Matrix A22 = getQuadrant(A, h, h, h);

    Matrix B11 = getQuadrant(B, 0, 0, h);
    Matrix B12 = getQuadrant(B, 0, h, h);
    Matrix B21 = getQuadrant(B, h, 0, h);
    Matrix B22 = getQuadrant(B, h, h, h);

    // 7 Strassen products
    Matrix M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix M2 = strassenMultiply(addMatrix(A21, A22), B11);
    Matrix M3 = strassenMultiply(A11, subtractMatrix(B12, B22));
    Matrix M4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    Matrix M5 = strassenMultiply(addMatrix(A11, A12), B22);
    Matrix M6 = strassenMultiply(subtractMatrix(A21, A11), addMatrix(B11, B12));
    Matrix M7 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));

    // Combine results
    Matrix C = createMatrix(n);
    setQuadrant(C, addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7), 0, 0);
    setQuadrant(C, addMatrix(M3, M5), 0, h);
    setQuadrant(C, addMatrix(M2, M4), h, 0);
    setQuadrant(C, addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6), h, h);

    return C;
}

void printMatrix(const Matrix& M)
{
    for (auto& row : M) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}