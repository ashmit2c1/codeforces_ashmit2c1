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

lint solvefunction(string s,lint m,lint k){
    lint ans=0;
    lint zero=0;
    lint dupk=k;
    forloop(0,s.size()){
        char character=s[i];
        if(character=='0'){
            zero++;
            if(zero>=m){
                lint index=i;
                while(index<s.size() && k>0){
                    s[index]='1';
                    index++;
                    k--;
                }
                ans++;
                k=dupk;
                zero=0;
            }
        }else{
            zero=0;
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;lint m;lint k;
        cin >> n >> m >> k;
        string s;cin >> s;
        lint ans=solvefunction(s,m,k);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}