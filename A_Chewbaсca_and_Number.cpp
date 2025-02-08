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

void recursivefunction(vector<string>& ans, string current, string s, int index) {
    if (index == s.size()) {
        ans.push_back(current);
        return;
    }
    char character = s[index];
    int digit = character - '0';
    recursivefunction(ans, current + character, s, index + 1);
    if((index==0 && digit!=9)){
        int newdigit = 9-digit;
        current+=(newdigit+'0');
        recursivefunction(ans,current,s,index+1);
    }
    if(index!=0){
        int newdigit = 9-digit;
        current+=(newdigit+'0');
        recursivefunction(ans,current,s,index+1);
    }
}

string solvefunction(string s){
    vector<string>ans;
    ans.push_back(s);
    recursivefunction(ans,"",s,0);
    sort(ans.begin(),ans.end());
    return ans[0];
    
}
void solution(){
    string s;cin >> s;
    string ans=solvefunction(s);
    print(ans)

}
int main(){

    solution();
}