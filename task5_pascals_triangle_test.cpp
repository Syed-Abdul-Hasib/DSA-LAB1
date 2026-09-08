#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalsTriangle(int n);
void printTriangle(const vector<vector<int>>& t);

int pass = 0, total = 0;

void checkRow(const string& name, vector<int> actual, vector<int> expected)
{
    total++;
    bool ok = (actual == expected);
    if (ok) pass++;
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

void checkInt(const string& name, int actual, int expected)
{
    total++;
    bool ok = (actual == expected);
    if (ok) pass++;
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

int main()
{
    // n = 0
    checkInt("n=0 empty triangle", generatePascalsTriangle(0).size(), 0);

    // n = 1
    checkRow("n=1 row0", generatePascalsTriangle(1)[0], {1});

    // n = 5
    auto t5 = generatePascalsTriangle(5);
    checkInt("n=5 has 5 rows",        t5.size(),  5);
    checkRow("n=5 row4 = {1,4,6,4,1}", t5[4],    {1,4,6,4,1});

    cout << "\nPascal's Triangle for n=5:\n";
    printTriangle(t5);

    cout << "\nSummary: " << pass << "/" << total << " passed.\n";
    return 0;
}