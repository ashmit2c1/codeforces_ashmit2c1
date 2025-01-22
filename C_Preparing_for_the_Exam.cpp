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

string solve(unordered_set<lint>&st,vector<lint>&papers,unordered_set<lint>&know){
    if(know.size()==st.size()){
        string ans="";
        forloop(0,papers.size()){
            ans+="1";
        }
        return ans;
    }
    if(know.size()==st.size()-2){
        string ans="";
        forloop(0,papers.size()){
            ans+="0";
        }
        return ans;
    }
    string ans="";
    forloop(0,papers.size()){
        lint paperToRemove = papers[i];
        if(know.find(paperToRemove)==know.end()){
            ans+="1";
        }else{
            ans+="0";
        }
    }
    return ans;
}
string solvefunction(unordered_set<lint>&st,vector<lint>&papers,unordered_set<lint>&know){
    return solve(st,papers,know);
}
void solution(int test){
    while(test--){
        lint questions;lint paper;lint answers;
        cin >> questions >> paper >> answers;
        unordered_set<lint>st;
        forloop(1,questions+1){st.insert(i);}
        vector<lint>papers;
        forloop(0,paper){lint x;cin >> x;papers.push_back(x);}
        unordered_set<lint>know;
        forloop(0,answers){lint x;cin >> x;know.insert(x);}
        string ans=solvefunction(st,papers,know);
        cout << ans << "\n";
    }
}
int main(){

    int test;
    cin >> test;
    solution(test);
}
