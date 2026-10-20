
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int next : adj[node]) {
        if (!visited[next]) {
            DFS(next, adj, visited);
        }
    }
}

void BFS(int start, vector<int> adj[], int n) {
    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of buildings and roads: ";
    cin >> n >> e;

    vector<int> adj[100];

    cout << "Enter roads (two connected buildings):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting building: ";
    cin >> start;

    bool visited[100] = {false};

    cout << "DFS Traversal: ";
    DFS(start, adj, visited);

    cout << "\nBFS Traversal: ";
    BFS(start, adj, n);

    return 0;
}
