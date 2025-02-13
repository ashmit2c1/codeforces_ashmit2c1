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

lint solvefunction4(vector<lint>&arr,lint r){
    lint tot = (arr.size()*(arr.size()-1)/2);
    lint left=0;
    lint right=0;
    lint cnt=0;
    for(lint right=1;right<arr.size();right++){
        while(arr[right]-arr[left]>r){
            left++;
        }
        lint len = (right-left);
        cnt+=len;
    }
    return tot-cnt;
}
lint solvefunction3(vector<lint>&arr,lint r){
    lint left=0;
    lint cnt=0;
    for(lint right=1;right<arr.size();right++){
        while(arr[right]-arr[left]>r){
            lint rem = arr.size()-right;
            cnt+=rem;
            left++;
        }
    }
    return cnt;
}
lint solvefunction2(vector<lint>&arr,lint r){
    lint left=0;
    lint cnt=0;
    for(lint right=1;right<arr.size();right++){
        lint curr = arr[right];
        lint diff=curr-arr[left];
        if(diff>r){
            cnt++;
            lint rem = arr.size()-right;
            cnt+=rem;
            left++;
        }
    }
    return cnt;
}
lint solvefunction1(vector<lint>&arr,lint r){
    lint cnt=0;
    forloop(0,arr.size()){
        lint curr = arr[i];
        secondfor(i+1,arr.size()){
            lint next = arr[j];
            lint diff = abs(next-curr);
            if(diff>r){
                cnt++;
            }
        }
    }
    return cnt;
}
void solution(){
    lint n;cin >> n;
    lint r;cin >> r;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solvefunction4(arr,r);
    print(ans)

}
int main(){

    solution();
}