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

bool solveFunction2(vector<lint>& arr) {
    lint sum = 0;

    // Calculate the sum of the array elements
    forloop(0, arr.size()) {
        sum += arr[i];
    }

    // Check if the sum is divisible by the array size
    if (sum % arr.size() != 0) {
        return false;
    }

    // Handle edge cases for small arrays
    if (arr.size() < 3) {
        return true; // With less than 3 elements, parity checks don't apply
    }

    // Check parity conditions for the first and last elements
    if ((arr[0] % 2 == arr[1] % 2) || (arr[arr.size() - 2] % 2 == arr[arr.size() - 1] % 2)) {
        return false;
    }

    // Check parity conditions for the middle elements
    forloop(1, arr.size() - 1) {
        if ((arr[i - 1] % 2 == 0 && arr[i + 1] % 2 == 0) || 
            (arr[i - 1] % 2 == 1 && arr[i + 1] % 2 == 1)) {
            return false;
        }
    }

    // If all conditions are satisfied, return true
    return true;
}
bool solveFunction(vector<lint>&arr){
    lint sum=0;lint evenSum=0;lint oddSum=0;lint oddCnt=0;lint evenCnt=0;
    forloop(0,arr.size()){
        sum+=arr[i];
        if(i%2==0){evenSum+=arr[i];evenCnt++;}
        else{oddSum+=arr[i];oddCnt++;}
    }
    if(sum%arr.size()!=0){return false;}
    lint val=sum/arr.size();
    if(evenCnt*val==evenSum && oddCnt*val==oddSum){return true;}
    else{return false;}


}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){
            lint x;cin >> x;arr.push_back(x);
        }
        bool ans=solveFunction2(arr);
        if(ans==true){print("YES")}
        else{print("NO")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}