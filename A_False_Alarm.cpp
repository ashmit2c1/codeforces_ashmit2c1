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

bool solvefunction(vector<lint>&arr,lint d){
    lint index=0;
    forloop(0,arr.size()){
        lint element = arr[i];
        if(element==1){
            index=i;
            break;
        }
    }
    if(index+d>=arr.size()){
        return true;
    }
    forloop(index+d,arr.size()){
        lint element = arr[i];
        if(element==1){
            return false;
        }
    }
    return true;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint d;cin >> d;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        bool ans=solvefunction(arr,d);
        if(ans==true){print("YES")}else{print("NO")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}