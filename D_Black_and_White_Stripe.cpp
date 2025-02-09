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
lint solvefunction(string s,lint k){
    lint cnt=0;
    lint right=0;
    lint left=0;
    while(right<k){
        char character = s[right];
        if(character=='W'){
            cnt++;
        }
        right++;
    }
    lint mincnt=cnt;
    while(right<s.size()){
        if(s[right]=='W'){cnt++;}
        if(s[left]=='W'){cnt--;}
        mincnt=min(mincnt,cnt);
        left++;
        right++;
    }
    return mincnt;

}
lint solvefunction2(string s,lint k){
    lint mincnt=INT_MAX;
    lint cnt=0;
    for(int i=0;i<=s.size()-k;i++){
        string temp = s.substr(i,k);
        for(int j=0;j<temp.size();j++){
            char character = temp[j];
            if(character=='W'){
                cnt++;
            }
        }
        mincnt=min(mincnt,cnt);
        cnt=0;
    }
    return mincnt;
}
void solution(int test){
    while(test--){
        lint n;lint k;
        cin >> n >> k;
        string s;cin >> s;
        lint ans=solvefunction2(s,k);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}