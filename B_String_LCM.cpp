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

string solvefunction(string s1,string s2){
    string x=s1;
    string y=s2;
    while(x.size()!=y.size()){
        if(x.size()<y.size()){
            x+=s1;
        }else{
            y+=s2;
        }
    }
    if(x==y){
        return x;
    }
    return "-1";
}
void solution(int test){
    while(test--){
        string s;string t;
        cin >> s >> t;
        string ans=solvefunction(s,t);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}