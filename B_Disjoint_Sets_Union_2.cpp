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

lint findparent(lint element, vector<lint> &parent) {
    if (parent[element] == element) {
        return element;
    }
    return parent[element] = findparent(parent[element], parent); // Path Compression
}

void unionfunction(lint u, lint v, vector<lint> &setsize, vector<lint> &parent,vector<lint>&minElement,vector<lint>&maxElement) {
    lint parentu = findparent(u, parent);
    lint parentv = findparent(v, parent);
    if (parentu != parentv) {
        if (setsize[parentv] > setsize[parentu]) {
            swap(parentu, parentv);
        }
        parent[parentv] = parentu;
        setsize[parentu] += setsize[parentv];
        minElement[parentu]=min(minElement[parentu],minElement[parentv]);
        maxElement[parentu]=max(maxElement[parentu],maxElement[parentv]);
    }
}
pair<lint, lint> findset(lint n, lint element, vector<lint> &parent) {
    unordered_map<lint, vector<lint>> parentsets;
    for (lint i = 0; i < n; i++) {
        lint leader = findparent(i, parent);
        parentsets[leader].push_back(i);
    }
    vector<lint> &setElements = parentsets[findparent(element, parent)];
    sort(setElements.begin(), setElements.end());
    
    return {setElements.front() + 1, setElements.back() + 1};
}

pair<lint,pair<lint,lint>>findtuple(lint element,vector<lint>&minElement,vector<lint>&maxElement,vector<lint>&setsize){
    return {minElement[element],{maxElement[element],setsize[element]}};
}
vector<pair<lint, pair<lint, lint>>> solvefunction(lint n, vector<pair<string, pair<lint, lint>>> &queries) {
    vector<pair<lint, pair<lint, lint>>> ans;
    vector<lint> parent(n);
    vector<lint> setsize(n, 1);
    vector<lint>minElement(n);
    vector<lint>maxElement(n);
    forloop(0, n) parent[i] = i;

    forloop(0, queries.size()) {
        string s = queries[i].first;
        if (s == "union") {
            lint u = queries[i].second.first - 1;
            lint v = queries[i].second.second - 1;
            unionfunction(u, v, setsize, parent,minElement,maxElement);
        } else if (s == "get") {
            lint u = queries[i].second.first - 1;
            lint parentU = findparent(u, parent);
            lint sz = setsize[parentU];
            pair<lint,pair<lint,lint>>answer=findtuple(parentU,minElement,maxElement,setsize);
            ans.push_back(answer);
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
        cout << ans[i].second.first << " " << ans[i].first << " " << ans[i].second.second << "\n";
    }
}

int main() {
    solution();
}
