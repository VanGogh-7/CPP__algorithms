#include <iostream>
#include <queue>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << node << ' ';

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

void bfs(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> nodes;

    visited[start] = true;
    nodes.push(start);

    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        std::cout << node << ' ';

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                nodes.push(neighbor);
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph{
        {1, 2},
        {0, 3, 4},
        {0},
        {1},
        {1}
    };

    std::vector<bool> visited(graph.size(), false);

    std::cout << "DFS: ";
    dfs(graph, 0, visited);

    std::cout << "\nBFS: ";
    bfs(graph, 0);

    std::cout << '\n';
    return 0;
}
