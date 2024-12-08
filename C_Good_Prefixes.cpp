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

lint evenBetterSolution(vector<lint>&arr){
    lint cnt=0;lint prefixSum=0;
    set<lint>st;
    forloop(0,arr.size()){
        st.insert(arr[i]);
        prefixSum+=arr[i];
        if(prefixSum%2==0 && st.find(prefixSum/2)!=st.end()){cnt++;}
    }
    return cnt;
}

lint betterSolveFunction(vector<lint>&arr){
    lint cnt=0;lint prefixSum=0;
    forloop(0,arr.size()){
        prefixSum+=arr[i];
        secondfor(0,i+1){
            lint val = 2*arr[j];
            if(val==prefixSum){cnt++;break;}
        }
    }
    return cnt;
}
lint solveFunction(vector<lint>&arr){
    lint cnt = 0; 
    forloop(0, arr.size()) {
        vector<lint> temp; 
        lint sum = 0; 
        secondfor(0, i+1) { 
            temp.push_back(arr[j]); 
        } 
        sort(temp.begin(), temp.end()); 
        secondfor(0, temp.size() - 1) {
            sum += temp[j];
        }
        if(sum == temp[temp.size() - 1]) { 
            cnt++; 
        }
    }
    return cnt; 
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=evenBetterSolution(arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}