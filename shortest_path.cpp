#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include <iomanip> // ✅ Add this for setprecision

using namespace std;

const double INF = numeric_limits<double>::infinity();

int main() {
    string filename;
    int source_id, target_id;
    cout << "Enter input file name: ";
    cin >> filename;
    cout << "Enter source ID: ";
    cin >> source_id;
    cout << "Enter target ID: ";
    cin >> target_id;

    unordered_map<int, int> id_to_index;
    vector<int> index_to_id;
    vector<vector<pair<int, double>>> adj;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    int idx_counter = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string u_str, v_str, w_str;
        getline(ss, u_str, ',');
        getline(ss, v_str, ',');
        getline(ss, w_str, ',');

        int u = stoi(u_str);
        int v = stoi(v_str);
        double w = stod(w_str); // Floating-point weights

        if (id_to_index.find(u) == id_to_index.end()) {
            id_to_index[u] = idx_counter++;
            index_to_id.push_back(u);
            adj.push_back({});
        }
        if (id_to_index.find(v) == id_to_index.end()) {
            id_to_index[v] = idx_counter++;
            index_to_id.push_back(v);
            adj.push_back({});
        }

        int u_idx = id_to_index[u];
        int v_idx = id_to_index[v];

        bool updated = false;
        for (auto& pair : adj[u_idx]) {
            if (pair.first == v_idx) {
                if (w < pair.second) pair.second = w;
                updated = true;
                break;
            }
        }
        if (!updated) {
            adj[u_idx].emplace_back(v_idx, w);
        }
    }

    file.close();

    int src = id_to_index[source_id];
    int tgt = id_to_index[target_id];
    vector<double> dist(adj.size(), INF);
    vector<int> prev(adj.size(), -1);
    dist[src] = 0.0;

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    pq.emplace(0.0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    if (dist[tgt] == INF) {
        cout << "No path exists from " << source_id << " to " << target_id << endl;
    } else {
        stack<int> path;
        for (int at = tgt; at != -1; at = prev[at])
            path.push(index_to_id[at]);

        cout << "A shortest path is: ";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << ", ";
        }
        cout << " with distance " << fixed << setprecision(2) << dist[tgt] << " km" << endl;
    }

    return 0;
}
