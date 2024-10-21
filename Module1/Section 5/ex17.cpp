// 392. Is Subsequence
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0; // Pointer for string s
    int j = 0; // Pointer for string t

    // Traverse through t
    while (j < t.length())
    {
        // If characters match, move pointer for s
        if (s[i] == t[j])
        {
            i++;
        }
        // Move pointer for t
        j++;

        // If we've matched all characters in s
        if (i == s.length())
        {
            return true;
        }
    }

    // If we finished t and haven't matched all characters in s
    return i == s.length();
}

int main()
{
    string c = "ccc";
    cout << (c.length());
    return 0;
}
