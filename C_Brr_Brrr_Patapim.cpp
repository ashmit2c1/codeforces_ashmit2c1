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

void solvefunction(vector<vector<lint>>&arr){
    lint n=arr.size();
    lint act = 2*n*(2*n+1)/2;
    unordered_map<int,int>mp;
    vector<lint>temp;
    lint sum=0;
    forloop(0,arr.size()){
        secondfor(0,arr.size()){
            lint element = arr[i][j];
            if(mp.find(element)==mp.end()){
                mp[element]++;
                temp.push_back(element);
                sum+=element;
            }
        }
    }
    lint diff = act-sum;
    cout << diff  << " ";
    forloop(0,temp.size()){cout << temp[i] << " ";}
    cout << "\n";
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<vector<lint>>arr;
        forloop(0,n){
            vector<lint>temp;
            forloop(0,n){
                lint x;cin >> x;temp.push_back(x);
            }
            arr.push_back(temp);
        }
        solvefunction(arr);
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}