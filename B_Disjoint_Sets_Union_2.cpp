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

lint findparent(lint element, vector<lint>& parent) {
    if (parent[element] == element) {
        return element;
    } else {
        lint leader_element = findparent(parent[element], parent);
        parent[element] = leader_element;
        return leader_element;
    }
}

void unionfunction(lint u, lint v, vector<lint>& setsize, vector<lint>& parent) {
    lint parentu = findparent(u, parent);
    lint parentv = findparent(v, parent);
    if (parentu != parentv) {
        if (setsize[parentv] < setsize[parentu]) {
            swap(parentu, parentv);
        }
        parent[parentv] = parentu;
        setsize[parentu] += setsize[parentv];
    }
}

pair<lint,lint> findset(lint n, lint element, vector<lint>& parent) {
    vector<vector<lint>> parentsets(n); 
    forloop(0, n) {
        lint parenti = findparent(i, parent); 
        parentsets[parenti].push_back(i); 
    }
    sort(parentsets[element].begin(), parentsets[element].end());
    lint szz = parentsets[element].size() - 1;
    return {parentsets[element][0] + 1, parentsets[element][szz] + 1};
}

vector<pair<lint, pair<lint, lint>>> solvefunction(lint n, vector<pair<string, pair<lint, lint>>>& queries) {
    vector<pair<lint, pair<lint, lint>>> ans;
    vector<lint> parent(n);
    vector<lint> setsize(n);
    forloop(0, n) {
        parent[i] = i;
        setsize[i] = 1;
    }

    forloop(0, queries.size()) {
        string s = queries[i].first;
        if (s == "union") {
            lint u = queries[i].second.first - 1;
            lint v = queries[i].second.second - 1;
            unionfunction(u, v, setsize, parent);
        } else if (s == "get") {
            lint u = queries[i].second.first - 1;
            lint parentU = findparent(u, parent);
            lint sz = setsize[parentU];
            pair<lint, lint> answer = findset(n, parentU, parent); 
            ans.push_back({answer.second, {answer.first, sz}});
        }
    }
    return ans;
}

void solution() {
    lint n, q;
    cin >> n >> q;
    vector<pair<string, pair<lint, lint>>> queries;

    forloop(0, q) {
        string s;
        lint a, b;
        cin >> s >> a;  
        if (s == "union") {
            cin >> b; 
            queries.push_back({s, {a, b}});
        }
        if (s == "get") {
            queries.push_back({s, {a, 0}});
        }
    }

    vector<pair<lint, pair<lint, lint>>> ans = solvefunction(n, queries);
    forloop(0, ans.size()) {
        cout << ans[i].second.first << " " << ans[i].first << " " << ans[i].second.second << "\n";;
    }
    
}

int main() {
    solution();
}
