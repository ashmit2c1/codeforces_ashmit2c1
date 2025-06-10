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


void solvefunction(lint n,lint k,vector<lint>&arr){
    if(n<k){
        arr.push_back(n);
        return;
    }
    if(n%k==0){
        arr.push_back(n-1);
        arr.push_back(1);
        return;
    }
    if(n%k!=0){
        arr.push_back(n);
        return;
    }
}
void solution(int test){
    while(test--){
        lint n;lint k;
        cin >> n >> k;
        vector<lint>arr;
        solvefunction(n,k,arr);
        print(arr.size());
        forloop(0,arr.size()){
            cout << arr[i] << " ";
        }
        cout << "\n";

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}