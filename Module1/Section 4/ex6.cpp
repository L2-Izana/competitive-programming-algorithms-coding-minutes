#include <bits/stdc++.h>
using namespace std;

/**
 * Distinct Candies
 * Alice has n candies, where the ith candy is of type candyType[i].
 * Alice noticed that she started to gain weight, so she visited a doctor.
 *
 * The doctor advised Alice to only eat n / 2 of the candies she has (n is always even).
 * Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.
 *
 * Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.
 */

// My solution: intuitive idea of use set (unduplicate values)
int distributeCandies(vector<int> candies)
{
    int l = candies.size();
    set<int> mySet(candies.begin(), candies.end());
    return std::min(l / 2, static_cast<int>(mySet.size()));
}

// Best solution: a smart way of counting number of unique values
int distributeCandies2(vector<int> candies)
{
    sort(candies.begin(), candies.end());
    int types = 1;
    for (int i = 0; i < candies.size() - 1; i++)
    {
        if (candies[i] != candies[i + 1])
            types++;
    }
    int allowed = (candies.size()) / 2;
    return min(allowed, types);
}

int main()
{
    vector<int> candies = {1, 1, 2, 2, 3, 3};
    cout << distributeCandies2(candies);
}