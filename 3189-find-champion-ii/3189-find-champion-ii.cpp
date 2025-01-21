class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // Step 1: Initialize a vector to count incoming edges for each team
        vector<int> in_degree(n, 0);
        
        // Step 2: Process the edges and update the in_degree array
        for (const auto& edge : edges) {
            int u = edge[0];  // team u is stronger than team v
            int v = edge[1];  // team v is weaker than team u
            in_degree[v]++;   // team v gets one more incoming edge
        }
        
        // Step 3: Identify teams with zero incoming edges (potential champions)
        vector<int> champions;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {  // If in_degree of team i is 0, it's a potential champion
                champions.push_back(i);
            }
        }
        
        // Step 4: If there is exactly one team with zero incoming edges, return that team
        if (champions.size() == 1) {
            return champions[0];
        }
        
        // Step 5: Otherwise, return -1 (no unique champion)
        return -1;
    }
};
