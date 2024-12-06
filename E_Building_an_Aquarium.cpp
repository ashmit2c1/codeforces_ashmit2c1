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

bool checkFunction(vector<lint>&arr,lint remainingWater,lint possibleHeight){
    forloop(0,arr.size()){
        lint coralHeight=arr[i];
        if(possibleHeight>coralHeight){
            lint waterFilled=possibleHeight-coralHeight;
            remainingWater-=waterFilled;
            if(remainingWater<0){
                
                return false;
            }
        }
    }
    return true; 
}
lint solveFunction(vector<lint>&arr,lint x){
    lint start=1;
    lint end=1e10;
    lint ans=-1;
    while(start<=end){
        lint mid=start+(end-start)/2;
        if(checkFunction(arr,x,mid)==true){
            ans=mid;start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

void solution(int test){
    while(test--){
        lint n;lint x;
        cin >> n >> x;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=solveFunction(arr,x);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}