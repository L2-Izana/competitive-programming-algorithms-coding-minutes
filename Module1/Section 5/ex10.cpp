// Decode XORed Array
#include <bits/stdc++.h> // include all standard libraries
#define ll long long int // macro definition
#define F first
#define S second
#define pb push_back
using namespace std;

vector<int> decode(vector<int> &encoded, int first)
{
    vector<int> result(encoded.size() + 1);
    result[0] = first;
    for (int i = 0; i < encoded.size(); i++)
    {
        int e = encoded[i];
        result[i + 1] = result[i] ^ e;
    }
    return result;
}

int main()

{
    vector<int> encoded = {6, 2, 7, 3};
    for (int i : decode(encoded, 4))
    {
        cout << i << " ";
    }
    return 0;
}
