#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to check if assigning color `c` to `node` is valid
    bool isSafe(int node, int color[], int c, int N, vector<vector<int>> &adj)
    {
        for (int k = 0; k < N; ++k)
        {
            // If there is an edge from node → k and `k` is already colored with `c`
            if (adj[node][k] == 1 && color[k] == c)
                return false; // Not safe to assign
        }
        return true; // Safe to assign color
    }

    // Recursive function to try coloring nodes
    bool solve(int node, int N, int m, vector<vector<int>> &adj, int color[])
    {
        // Base case: all nodes have been assigned a color
        if (node == N)
            return true;

        // Try all colors from 1 to m
        for (int c = 1; c <= m; ++c)
        {
            // Check if assigning color `c` to this node is safe
            if (isSafe(node, color, c, N, adj))
            {
                color[node] = c; // Assign color

                // Recursively color the next node
                if (solve(node + 1, N, m, adj, color))
                    return true;

                // Backtrack: reset color if it didn't lead to a solution
                color[node] = 0;
            }
        }
        return false; // No valid coloring found for this node
    }

public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m)
    {
        // Step 1: Build adjacency matrix from edge list
        vector<vector<int>> adj(v, vector<int>(v, 0));
        for (auto &e : edges)
        {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1; // Undirected graph
        }

        // Step 2: Array to store colors assigned to each vertex
        int color[v] = {0}; // Initially no node is colored

        // Step 3: Start solving from node 0
        return solve(0, v, m, adj, color);
    }
};
