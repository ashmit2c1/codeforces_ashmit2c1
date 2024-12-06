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


bool canFit(lint w,lint h,lint n,lint sz){
    lint rows=sz/w;lint cols=sz/h;
    if(cols * rows >=n){
        return true;
    }
    else{
        return false;
    }
}
lint solveFunction(lint w,lint h,lint n){
    lint start=max(w,h);
    lint end=max(w,h)*n;
    lint ans=end;
    while(start<end){
        lint mid = start + (end-start)/2;
        if(canFit(w,h,n,mid)==true){
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
    lint w;lint h;lint n;
    cin >> w >> h >> n;
    lint ans=solveFunction(w,h,n);
    print(ans)

}
int main(){

    solution();
}