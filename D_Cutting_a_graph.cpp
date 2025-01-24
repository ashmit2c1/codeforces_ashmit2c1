#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";
#define output(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x,y) make_pair(x,y)
bool dfsfunction(lint current, lint target, vector<vector<lint>>& adj, vector<bool>& visited) {
    if(current == target) {
        return true;
    }
    visited[current] = true;
    for (lint neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (dfsfunction(neighbor, target, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}
bool checkfunction(lint start, lint end, vector<vector<lint>>& adj) {
    vector<bool> visited(adj.size(), false);
    return dfsfunction(start, end, adj, visited);
}
vector<bool> solvefunction(vector<vector<lint>>& adj, vector<pair<string, pair<lint, lint>>>& queries, lint n) {
    vector<bool> ans;
    forloop(0, queries.size()) {
        string command = queries[i].first;
        lint u = queries[i].second.first - 1;
        lint v = queries[i].second.second - 1;
        if (command == "ask") {
            bool check = checkfunction(u, v, adj);
            if (check == true) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        } else if (command == "cut") {
            // Removing the edge
            auto it1 = find(adj[u].begin(), adj[u].end(), v);
            auto it2 = find(adj[v].begin(), adj[v].end(), u);
            if (it1 != adj[u].end()) {
                adj[u].erase(it1);
            }
            if (it2 != adj[v].end()) {
                adj[v].erase(it2);
            }
        }
    }
    return ans;
}
void solution() {
    lint n, m, k;
    cin >> n >> m >> k;
    vector<vector<lint>> adj(n);
    
    forloop(0, m) {
        lint u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    vector<pair<string, pair<lint, lint>>> queries;
    forloop(0, k) {
        string s;
        lint a, b;
        cin >> s >> a >> b;
        queries.push_back({s, {a, b}});
    }
    vector<bool> ans = solvefunction(adj, queries, n);
    forloop(0, ans.size()) {
        bool val = ans[i];
        if (val == true) {
            print("YES");
        } else {
            print("NO");
        }
    }
}
int main() {
    solution();
}