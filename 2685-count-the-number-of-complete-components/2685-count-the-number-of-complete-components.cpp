#include <vector>
#include <queue>

class Solution {
public:
    int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
        // Build the adjacency list
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        std::vector<bool> visited(n, false);
        int complete_components = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int vertex_count = 0;
                int edge_count = 0;
                
                // BFS queue
                std::queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    vertex_count++;
                    edge_count += adj[curr].size();
                    
                    for (int neighbor : adj[curr]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                
                // For an undirected graph, every edge in the component is counted twice.
                // A complete graph has V * (V - 1) / 2 unique edges, meaning 
                // total degree count (edge_count) must equal V * (V - 1).
                if (edge_count == vertex_count * (vertex_count - 1)) {
                    complete_components++;
                }
            }
        }
        
        return complete_components;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna