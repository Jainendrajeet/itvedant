#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#define MAX 100

using namespace std;

vector<int> adj[MAX];     // Adjacency list for the undirected graph(after removing the graph with no reverse edge)
int match[MAX];           // Match array to store pairs that matches
int parent[MAX];          // Parent array for Breadth first Search
int base[MAX];            // Base of the current blossom
bool visited[MAX];        // Visited array for BFS
int n;                    // Number of vertices in the graph

// lowest common ancestor
int findLCA(int u, int v) {
    vector<bool> inPath(MAX, false);
    while (true) {
        u = base[u];
        inPath[u] = true;
        if (match[u] == -1) break;
        u = parent[match[u]];
    }
    while (true) {
        v = base[v];
        if (inPath[v]) return v;
        v = parent[match[v]];
    }
}

//  contract a blossom
void contract(int u, int v, int lca, queue<int> &q) {
    while (base[u] != lca) {
        parent[u] = v;
        v = match[u];
        if (!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
        base[u] = base[v] = lca;
        u = parent[v];
    }
}

// BFS for an augmenting path
bool bfs(int root) {
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < n; i++) base[i] = i;

    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (base[u] == base[v] || match[u] == v) continue;

            if (v == root || (match[v] != -1 && parent[match[v]] != -1)) {
                int lca = findLCA(u, v);
                contract(u, v, lca, q);
                contract(v, u, lca, q);
            } else if (parent[v] == -1) {
                parent[v] = u;
                if (match[v] == -1) {
                    // Augment the path
                    while (v != -1) {
                        int prev = parent[v];
                        int next = match[prev];
                        match[v] = prev;
                        match[prev] = v;
                        v = next;
                    }
                    return true;
                }
                visited[match[v]] = true;
                q.push(match[v]);
            }
        }
    }

    return false;
}

// Edmonds blossom algorithm
int edmondsMatching() {
    memset(match, -1, sizeof(match));
    int matching = 0;

    for (int i = 0; i < n; i++) {
        if (match[i] == -1 && bfs(i)) {
            matching++;
        }
    }

    return matching;
}

//  main
int main() {
    int edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> edges;

    // Given graph 
    set<pair<int, int>> directedEdges;
    cout << "Enter directed edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        directedEdges.insert({u, v});
    }

    // Filter bidirectional edges and create an undirected graph (removing the single direction )
    for (auto &edge : directedEdges) {
        int u = edge.first, v = edge.second;
        if (directedEdges.count({v, u})) {
            adj[u].push_back(v);
            adj[v].push_back(u);  // Treat as an undirected edge
        }
    }

    int maxMatching = edmondsMatching();
    cout << "Maximum matching: " << maxMatching << endl;

    cout << "Matched pairs:" << endl;
    for (int i = 0; i < n; i++) {
        if (match[i] != -1 && i < match[i]) {
            cout << i << " -- " << match[i] << endl;
        }
    }

    return 0;
}
