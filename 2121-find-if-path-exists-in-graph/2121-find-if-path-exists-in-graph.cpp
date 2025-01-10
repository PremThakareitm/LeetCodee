class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }

        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        std::queue<int> q;
        std::unordered_set<int> visited;
        q.push(source);
        visited.insert(source);


        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    if (neighbor == destination) {
                        return true; 
                    }
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};