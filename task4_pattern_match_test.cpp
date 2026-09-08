#include <iostream>
#include <string>
using namespace std;

int naiveSearch(const string& text, const string& pattern);

int pass = 0, total = 0;

void check(const string& name, int actual, int expected)
{
    total++;
    bool ok = (actual == expected);
    if (ok) pass++;
    cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
}

int main()
{
    check("Pattern at beginning", naiveSearch("abracadabra", "abr"),   0);
    check("Pattern at end",       naiveSearch("abracadabra", "dabra"), 6);
    check("Pattern not present",  naiveSearch("abracadabra", "xyz"),  -1);
    check("Empty pattern",        naiveSearch("abracadabra", ""),      0);

    cout << "\nSummary: " << pass << "/" << total << " passed.\n";
    return 0;
}