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
bool solvefunction(lint n,lint a,lint b){
    if(n==a && a==b){
        return true;
    }
    lint diff = n-(a+b);
    if(diff>=2){
        return true;
    }else{
        return false;
    }

}
void solution(int test){
    while(test--){
        lint n;lint a;lint b;
        cin >> n >> a >> b;
        bool ans=solvefunction(n,a,b);
        if(ans==true){
            print("Yes")
        }else{
            print("No")
        }

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}