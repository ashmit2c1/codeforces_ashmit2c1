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
bool checkfunction(string a,string b){
    int zeroCount=0;
    int oneCount=0;
    for(int i=0;i<a.size();i++){
        if(i%2==0){
            char character=a[i];
            if(character=='0'){zeroCount++;}else{oneCount++;}
        }
    }
    forloop(0,b.size()){
        if(i%2==1){
            char character=b[i];
            if(character=='0'){zeroCount++;}else{oneCount++;}
        }
    }
    return zeroCount>=oneCount;
}
bool solvefunction(string a,string b){
    if(a.size()==2){
        if((a=="11"&&b=="00")||(a=="10"&&b=="01")||(a=="01"&&b=="10")){
            return true;
        }else{
            return false;
        }
    }
    bool condition1=checkfunction(a,b);
    bool condition2=checkfunction(b,a);
    if(condition1==true && condition2==true){
        return true;
    }else{return false;}
}
void solution(int test){
    while(test--){
        lint n;
        cin >> n;
        string a;string b;
        cin >> a >> b;
        bool ans = solvefunction(a,b);
        if(ans==true){print("YES")}else{print("NO")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}