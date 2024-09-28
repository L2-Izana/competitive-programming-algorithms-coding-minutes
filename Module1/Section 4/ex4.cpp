#include <bits/stdc++.h>
using namespace std;

/**
 * Maximum Score From Removing Stones
 *
 * You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively.
 * Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score.
 * The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).
 *
 * Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.
 */

int maximumScore(int a, int b, int c)
{
    // the maximum <= the minimum + the middle
    const int x = (a + b + c) / 2;
    // the maximum > the minimum + the middle
    const int y = a + b + c - max({a, b, c});
    return min(x, y);
}

int main()
{
    cout << maximumScore(6, 4, 8);
    return 0;
}