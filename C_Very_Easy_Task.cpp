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


bool checkFunction(lint possibleTime,lint n,lint x,lint y){
    lint timeLeft=possibleTime-min(x,y);
    if(timeLeft<0){
        return false;
    }
    lint copies=(timeLeft/x)+(timeLeft/y);
    if(copies>=n-1){
        return true;
    }
    else{
        return false;
    }
}

lint solveFunction(lint n,lint x,lint y){
    if(n==1){
        return 0;
    }
    lint start=0;
    lint end=n*min(x,y);
    lint ans=-1;
    while(start<=end){
        lint mid = start + (end-start)/2;
        if(checkFunction(mid,n,x,y)==true){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

void solution(){
    lint n;lint x;lint y;
    cin >>n>>x>>y;
    lint ans=solveFunction(n,x,y);
    print(ans)

}
int main(){

    solution();
}