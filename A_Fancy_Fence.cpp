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


bool solvefunction(lint angle){
    if(360%(180-angle)==0){
        return true;
    }
    return false;
}

void solution(int test){
    while(test--){
        lint angle;cin >> angle;
        bool ans=solvefunction(angle);
        if(ans==true){print("YES")}else{print("NO")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}