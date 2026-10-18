class Solution {
public:
    bool solve(int node, vector<int>& col, vector<vector<int>>& adj, int m, int n) {
        if (node == n) return true;

        for (int c = 1; c <= m; c++) {
            bool ok = true;
            for (int v : adj[node])
                if (col[v] == c) ok = false;

            if (ok) {
                col[node] = c;
                if (solve(node + 1, col, adj, m, n)) return true;
                col[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int n) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> col(n, 0);
        return solve(0, col, adj, m, n);
    }
};
