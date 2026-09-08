#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;
Matrix strassenMultiply(const Matrix& A, const Matrix& B);
Matrix naiveMultiply(const Matrix& A, const Matrix& B);
void printMatrix(const Matrix& M);

int pass = 0, total = 0;

void check(const string& name, bool ok)
{
    total++;
    if (ok) pass++;
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

int main()
{
    // 2x2 known answer
    Matrix A2 = {{1,2},{3,4}};
    Matrix B2 = {{5,6},{7,8}};
    Matrix exp2 = {{19,22},{43,50}};
    check("2x2 known answer", strassenMultiply(A2,B2) == exp2);
    check("2x2 vs naive",     strassenMultiply(A2,B2) == naiveMultiply(A2,B2));

    // 4x4
    Matrix A4 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix B4 = {{17,18,19,20},{21,22,23,24},{25,26,27,28},{29,30,31,32}};
    check("4x4 vs naive", strassenMultiply(A4,B4) == naiveMultiply(A4,B4));

    // Printing results
    cout << "\nStrassen 2x2 result:\n";
    printMatrix(strassenMultiply(A2, B2));
    cout << "\nNaive 2x2 result:\n";
    printMatrix(naiveMultiply(A2, B2));

    cout << "\nSummary: " << pass << "/" << total << " passed.\n";
    return 0;
}