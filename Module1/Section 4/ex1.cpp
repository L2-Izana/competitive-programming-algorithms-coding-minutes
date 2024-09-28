// #include <bits/stdc++.h>
// using namespace std;

// int firstUniqChar(string s)
// {
//     map<char, int> mp;
//     for (int i = 0; i < s.size(); i++)
//     {
//         char c = s[i];
//         if (mp.find(c) != mp.end())
//         {
//             mp.erase(c);
//         }
//         else
//         {
//             mp[c] = i;
//         }
//     }
//     if (!mp.empty())
//     {
//         return mp.begin()->second;
//     }
//     return -1;
// }

// int main()
// {
//     cout << firstUniqChar("hello");
//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s)
{
    int charArr[26] = {0};
    int stringlen = (s.length());
    int i, index;

    for (i = 0; i < stringlen; ++i)
    {
        charArr[s[i] - 'a']++;
    }

    for (i = 0; i < stringlen; ++i)
    {
        if (charArr[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    cout << firstUniqChar("hello");
    return 0;
}
