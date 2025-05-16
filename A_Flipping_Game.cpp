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
// 
lint solvefunction(vector<lint>&arr){
    lint start=0;
    lint end=arr.size()-1;
    lint ones=0;
    // finding the position for the first zero
    forloop(0,arr.size()){
        lint element = arr[i];
        if(element==0){
            start=i;
            break;
        }else{
            ones++;
        }
    }
    if(ones==arr.size()){return ones-1;}
    // finding the position for the second zero
    for(int i=arr.size()-1;i>=0;i--){
        lint element = arr[i];
        if(element==0){
            end=i;
            break;
        }else{
            ones++;
        }
    }
    vector<pair<lint,lint>>temp;
    lint zeroes=0;
    lint onecnt=0;
    forloop(start,end+1){
        lint element = arr[i];
        if(element==0){
            zeroes++;
            temp.push_back({zeroes,onecnt});
        }else{
            onecnt++;
            temp.push_back({zeroes,onecnt});
        }
    }
    lint maxdiff=INT_MIN;
    forloop(0,temp.size()){
        lint f = temp[i].first;
        lint s = temp[i].second;
        lint diff = f-s;
        maxdiff=max(maxdiff,diff);
    }
    vector<lint>z;
    forloop(0,temp.size()){
        lint f=temp[i].first;
        z.push_back(f);
    }
    if(z.size()==0){
        return ones+onecnt;
    }
    sort(z.begin(),z.end());
    lint c = z[z.size()-1];
    return c+ones;
}

void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solvefunction(arr);
    print(ans)

}
int main(){

    solution();
}