// Astronaut Pairs

#include <bits/stdc++.h>
using namespace std;

// Function to perform the DFS Traversal
// to find the count of connected
// components
void dfs(int v, vector<vector<int>> &adj,
         vector<bool> &visited, int &num)
{
    // Marking vertex visited
    visited[v] = true;
    num++;

    // DFS call to neighbour vertices
    for (int i = 0; i < adj[v].size(); i++)
    {

        // If the current node is not
        // visited, then recursively
        // call DFS
        if (!visited[adj[v][i]])
        {
            dfs(adj[v][i], adj,
                visited, num);
        }
    }
}

void numberOfPairs(
    int N, vector<vector<int>> arr)
{
    // Stores the Adjacency list
    vector<vector<int>> adj(N);

    // Constructing the graph
    for (vector<int> &i : arr)
    {
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }

    // Stores the visited vertices
    vector<bool> visited(N);

    // Stores the size of every connected components
    vector<int> v;

    int num = 0;
    for (int i = 0; i < N; i++)
    {

        if (!visited[i])
        {

            // DFS call to the graph
            dfs(i, adj, visited, num);

            // Store size of every connected component
            v.push_back(num);
            num = 0;
        }
    }

    for (int v_e : v)
    {
        cout << v_e << " ";
    }
    cout << endl;

    // Stores the total number of
    // ways to count the pairs
    int ans = N * (N - 1) / 2;

    // Traverse the array
    for (int i : v)
    {
        ans -= (i * (i - 1) / 2);
    }

    // Print the value of ans
    cout << ans;
}

// Driver Code
int main()
{
    int N = 6;
    vector<vector<int>> arr = {{0, 1}, {0, 2}, {2, 5}};
    numberOfPairs(N, arr);

    return 0;
}
