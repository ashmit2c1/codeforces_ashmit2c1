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


lint solve(lint a,lint b,lint c,lint d){
    if(d<b){
        return -1;
    }
    lint moves=d-b;
    lint check = c-moves;
    if(check<=a){
        moves+=(a-check);
        return moves;
    }else{
        return -1;
    }

}
void solution(int test){
    while(test--){
        lint a,b,c,d;
        cin >> a >> b >> c >> d;
        lint ans=solve(a,b,c,d);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}