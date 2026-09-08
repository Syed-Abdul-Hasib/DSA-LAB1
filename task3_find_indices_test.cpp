#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(const vector<int>& arr, int key);

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
    check("Multiple occurrences", findAllIndices({5,2,5,7,5,1}, 5), {0,2,4});
    check("Single occurrence", findAllIndices({10,20,30,40}, 30), {2});
    check("Key not present", findAllIndices({1,2,3,4}, 99),{});
    check("Empty array", findAllIndices({}, 1),{});
    check("All match", findAllIndices({7,7,7}, 7), {0,1,2});
    check("Negative key", findAllIndices({-3,4,-3,0}, -3), {0,2});

    cout << "\nSummary: " << pass << "/" << total << " passed."<<endl;
    return 0;
}