#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Returns modes of the array
vector<int> findModes(const vector<int>& arr)
{
    vector<int> modes;
    if (arr.empty()) return modes;

    map<int,int> freq;
    for (int x : arr) freq[x]++;

    // Finds max frequency
    int maxF = 0;
    for (auto& p : freq)
        if (p.second > maxF) maxF = p.second;

    // Collects all elements with max frequency
    for (auto& p : freq)
        if (p.second == maxF) modes.push_back(p.first);

    return modes;
}