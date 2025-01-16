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

string solve(lint limit,string s){
    string temp = s;
    dsort(s);
    lint cost=0;
    forloop(0,s.size()){
        char character = s[i];
        lint characterCost = s[i]-'a'+1;
        cost+=characterCost;
    }
    if(cost<=limit){
        return temp;
    }
    unordered_map<char,lint>mp;
    forloop(0,s.size()){
        char character = s[i];
        lint characterCost = s[i]-'a'+1;
        if(cost>limit){
            mp[character]++;
            cost-=characterCost;
        }
    }
    string ans="";
    forloop(0,temp.size()){
        char character = temp[i];
        if(mp.find(character)!=mp.end()){
            mp[character]--;
            if(mp[character]==0){
                mp.erase(character);
            }
        }
        else{
            ans+=character;
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        string s;cin >> s;
        lint n;cin >> n;
        string ans=solve(n,s);
        print(ans)
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}