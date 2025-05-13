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
lint solvefunction(vector<lint>&arr1, vector<lint>&arr2, lint n, lint k) {
    bool allElements = false;
    forloop(0, arr2.size()) {
        if(arr2[i] != -1) {
            allElements = true;
        }
    }
    if(allElements == false) {
        lint maxe = *max_element(arr1.begin(), arr1.end());
        lint mine = *min_element(arr1.begin(), arr1.end());
        return max(0LL, k - (maxe - mine) + 1);
    }
    lint sum = -1;
    forloop(0, arr1.size()) {
        if(arr2[i] != -1) {
            sum = arr1[i] + arr2[i];
            break;
        }
    }

    forloop(0, arr1.size()) {
        if(arr2[i] != -1) {
            if(arr1[i] + arr2[i] != sum) {
                return 0;
            }
        }
    }

    forloop(0, arr1.size()) {
        if(arr2[i] == -1) {
            lint bi = sum - arr1[i];
            if(bi < 0 || bi > k) {
                return 0;
            }
        }
    }

    return 1;
}

void solution(int test) {
    while(test--) {
        lint n; lint k;
        cin >> n >> k;
        vector<lint> arr1;
        vector<lint> arr2;
        forloop(0, n) {
            lint x; cin >> x; arr1.push_back(x);
        }
        forloop(0, n) {
            lint x; cin >> x; arr2.push_back(x);
        }
        lint ans = solvefunction(arr1, arr2, n, k);
        print(ans)
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
}
