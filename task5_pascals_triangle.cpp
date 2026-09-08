#include <iostream>
#include <vector>
using namespace std;

// Pascal's triangle
vector<vector<int>> generatePascalsTriangle(int n)
{
    vector<vector<int>> triangle;
    if (n <= 0) return triangle;

    for (int row = 0; row < n; row++)
    {
        vector<int> currentRow(row + 1, 1);
        for (int col = 1; col < row; col++)
            currentRow[col] = triangle[row-1][col-1] + triangle[row-1][col];
        triangle.push_back(currentRow);
    }
    return triangle;
}

void printTriangle(const vector<vector<int>>& t)
{
    for (auto& row : t) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }
}