#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * @brief Finds the index of the first non-repeating character in a given string.
 *
 * This function iterates through the string to count the occurrences of each character
 * and then finds the first character that appears only once. If no such character exists,
 * it returns -1.
 *
 * @param s The input string to be analyzed.
 * @return int The index of the first non-repeating character, or -1 if none exists.
 */

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
