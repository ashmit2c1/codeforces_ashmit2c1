#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x, y) for(int i = x; i < y; i++)
#define secondfor(x, y) for(int j = x; j < y; j++)
#define print(x) cout << x << "\n";
#define output(arr) for(int i = 0; i < arr.size(); i++){cout << arr[i] << " ";}
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x, y) make_pair(x, y)

class SegmentTree {
    private:
        vector<lint> mintree;
        vector<lint> arr;
        lint n;

        void buildmin(lint node, lint start, lint end) {
            if (start == end) {
                mintree[node] = arr[start];
            } else {
                lint mid = start + (end - start) / 2;
                lint left = 2 * node + 1;
                lint right = 2 * node + 2;
                buildmin(left, start, mid);
                buildmin(right, mid + 1, end);
                mintree[node] = min(mintree[left], mintree[right]);
            }
        }

        lint querymin(lint node, lint start, lint end, lint L, lint R) {
            if (R < start || L > end) {
                return lintmax;
            }
            if (L <= start && R >= end) {
                return mintree[node];
            }
            lint mid = start + (end - start) / 2;
            lint left = 2 * node + 1;
            lint right = 2 * node + 2;
            return min(querymin(left, start, mid, L, R), querymin(right, mid + 1, end, L, R));
        }
        lint cntmin(lint min,lint left,lint right){
            lint cnt=0;
            forloop(left,right+1){
                if(arr[i]==min){cnt++;}
            }
            return cnt;
        }

        void updatemin(lint node, lint start, lint end, lint index, lint value) {
            if (start == end) {
                arr[start]=value;
                mintree[node] = value;
            } else {
                lint mid = start + (end - start) / 2;
                lint left = 2 * node + 1;
                lint right = 2 * node + 2;
                if (index <= mid) {
                    updatemin(left, start, mid, index, value);
                } else {
                    updatemin(right, mid + 1, end, index, value);
                }
                mintree[node] = min(mintree[left], mintree[right]);
            }
        }

    public:
        SegmentTree(vector<lint>& inputarr) {
            n = inputarr.size();
            arr = inputarr;
            mintree.resize(4 * n);
            buildmin(0, 0, n - 1);
        }

        lint rangemin(lint L, lint R) {
            return querymin(0, 0, n - 1, L, R);
        }

        void update(lint index, lint value) {
            updatemin(0, 0, n - 1, index, value);
        }
        lint countmin(lint answer,lint left,lint right){
            return cntmin(answer,left,right);
        }
};

vector<pair<lint,lint>> solvefunction(vector<lint>& arr, vector<pair<lint, pair<lint, lint>>>& queries) {
    vector<pair<lint,lint>> ans;
    SegmentTree segtree(arr);
    forloop(0, queries.size()) {
        lint type = queries[i].first;
        if (type == 1) {
            lint index = queries[i].second.first ;
            lint value = queries[i].second.second;
            segtree.update(index, value);
        } else {
            lint left = queries[i].second.first;
            lint right = queries[i].second.second - 1;
            lint answer = segtree.rangemin(left, right);
            lint mincnt = segtree.countmin(answer,left,right);
            ans.push_back({answer,mincnt});
        }
    }
    return ans;
}

void solution() {
    lint n;
    cin >> n;
    lint q;
    cin >> q;
    vector<lint> arr;
    forloop(0, n) {
        lint x;
        cin >> x;
        arr.push_back(x);
    }
    vector<pair<lint, pair<lint, lint>>> queries;
    forloop(0, q) {
        lint a, b, c;
        cin >> a >> b >> c;
        queries.push_back({a, {b, c}});
    }
    vector<pair<lint,lint>> ans = solvefunction(arr, queries);
    forloop(0, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    solution();
}