#include <iostream>
#include <vector>
using namespace std;

vector<int> findModes(const vector<int>& arr);

int pass = 0, total = 0;

void check(const string& name, vector<int> actual, vector<int> expected)
{
    total++;
    bool ok = (actual == expected);
    if (ok) pass++;
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

int main()
{
    check("Unique mode", findModes({1,3,3,2,3,1}), {3});
    check("Multiple modes", findModes({1,1,2,2,3}), {1,2});
    check("Empty array", findModes({}), {});

    cout << "\nSummary: " << pass << "/" << total << " passed.\n";
    return 0;
}