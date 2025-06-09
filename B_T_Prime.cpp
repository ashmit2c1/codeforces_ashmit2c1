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

bool checkfunction(lint num,lint sq){
    if(num*num==sq){return true;}else{return false;}
}
bool checkforprime(lint n){
    forloop(2,n){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
vector<bool>solvefunction(vector<lint>&arr){
    vector<bool>answer;
    forloop(0,arr.size()){
        lint element = arr[i];
        lint ans = sqrt(element);
        bool check = checkfunction(ans,arr[i]);
        if(check==true){
            if(checkforprime(ans)==true){
                answer.push_back(true);
            }
        }else{
            answer.push_back(false);
        }
    }
    return answer;
}
void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    vector<bool>ans=solvefunction(arr);
    forloop(0,ans.size()){
        if(ans[i]==false){cout << "NO" << "\n";}
        else{cout << "YES" << "\n";}
    }

}
int main(){

    solution();
}