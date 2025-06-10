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


lint solvefunction(vector<lint>&arr){
    lint neg=0;
    lint pos=0;
    lint sum=0;
    forloop(0,arr.size()){
        lint element = arr[i];
        if(element==1){pos++;}
        if(element==-1){neg++;}
        sum+=arr[i];
    }
    lint movestomakepositive=0;
    while(sum<0){
        neg--;
        sum+=2;
        movestomakepositive++;
    }
    lint movestomake1=0;
    if(neg!=0 && neg%2==1){
        movestomakepositive++;
    }
    return movestomakepositive;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){
            lint x;cin >> x;arr.push_back(x);
        }
        lint ans=solvefunction(arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}