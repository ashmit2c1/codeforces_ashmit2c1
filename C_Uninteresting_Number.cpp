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

bool solveFunction(string s){
    lint sum=0;
    lint digit2=0;
    lint digit3=0;
    forloop(0,s.size()){
        int num=s[i]-'0';
        sum+=num;
        if(s[i]=='2'){digit2++;}
        if(s[i]=='3'){digit3++;}
    }
    if(sum%9==0){
        return true;
    }
    lint def=9-sum%9;
    lint rem=def%9;
    bool possible = false;
    forloop(0,digit3+1){
        lint temp=(rem-6*i)%9;
        if(temp<0){temp+=9;}
        lint temp2=(temp*5)%9;
        if(temp2<=digit2){
            possible=true;
            break;
        }
    }
    return possible;
}

void solution(int test){
    while(test--){
        string s;cin >> s;
        bool ans=solveFunction(s);
        if(ans==true){print("YES")}
        else{print("NO")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}