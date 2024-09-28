#include <bits/stdc++.h>
using namespace std;

/**
 * Bulls and Cows
 *
 * You are playing the Bulls and Cows game with your friend.
 *
 * You write down a secret number and ask your friend to guess what the number is.
 * When your friend makes a guess, you provide a hint with the following info:
 *
 * The number of "bulls", which are digits in the guess that are in the correct position.
 * The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
 *
 * Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
 */

string getHint(string secret, string guess)
{
    int nb = 0, nc = 0;                   // nb for bulls, nc for cows
    unordered_map<char, int> secretCount; // To count occurrences of characters in secret
    unordered_map<char, int> guessCount;  // To count occurrences of characters in guess

    // First pass to count bulls and fill the maps
    for (int i = 0; i < secret.size(); i++)
    {
        if (secret[i] == guess[i])
        {
            nb++; // Count bulls
        }
        else
        {
            secretCount[secret[i]]++; // Count chars in secret
            guessCount[guess[i]]++;   // Count chars in guess
        }
    }

    // Calculate cows
    for (const auto &pair : guessCount)
    {
        char ch = pair.first;
        nc += min(secretCount[ch], pair.second); // Add the minimum occurrences of each character
    }

    return to_string(nb) + "A" + to_string(nc) + "B"; // Return result in the format "xAyB"
}

int main()
{
    string secret = "1123";
    string guess = "0111";
    cout << getHint(secret, guess);

    return 0;
}