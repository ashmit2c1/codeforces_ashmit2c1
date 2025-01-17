#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x, y) for (int i = x; i < y; i++)
#define secondfor(x, y) for (int j = x; j < y; j++)
#define print(x) cout << x << "\n";
#define output(arr) for (int i = 0; i < arr.size(); i++) { cout << arr[i] << " "; }
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x, y) make_pair(x, y)

bool hamPath(lint node, lint nodes, vector<lint> adj[], vector<lint>& ans, vector<bool>& visited, lint count) {
    visited[node] = true;
    count++;
    ans.push_back(node);
    if (count == nodes) {
        return true;
    }
    lint n = adj[node].size();
    forloop(0, n) {
        lint neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (hamPath(neighbor, nodes, adj, ans, visited, count)) {
                return true;
            }
        }
    }
    visited[node] = false;
    ans.pop_back();
    return false;
}

bool checkfunction(lint nodes, vector<lint> adj[], vector<lint>& ans) {
    vector<bool> visited(nodes, false);
    forloop(0, nodes) {
        if (hamPath(i, nodes, adj, ans, visited, 0)) {
            return true;
        }
    }
    return false;
}

vector<lint> solvefunction(lint nodes, vector<lint>& arr) {
    vector<lint> adj[nodes+1]; 
    forloop(0, nodes - 1) {
        adj[i].push_back(i + 1);
    }
    forloop(0, arr.size()) {
        lint ref = arr[i];
        if (ref == 1) {
            adj[nodes].push_back(i);
        } else {
            adj[i].push_back(nodes);
        }
    }
    vector<lint> ans;
    bool check = checkfunction(nodes + 1, adj, ans);
    if (check) {
        return ans;
    } else {
        return { -1 };
    }
}

void solution(int test) {
    while (test--) {
        lint nodes;
        cin >> nodes;
        vector<lint> arr;
        forloop(0, nodes) {
            lint x;
            cin >> x;
            arr.push_back(x);
        }
        vector<lint> ans = solvefunction(nodes, arr);
        if (ans[0] == -1) {
            cout << -1 << "\n";
        } else {
            forloop(0, ans.size()) {
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
}