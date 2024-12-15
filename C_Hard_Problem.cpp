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


lint solveFunction(lint m,lint a,lint b,lint c){
    lint seatsInFirstRow=m;
    lint seatsOccFirstRow=min(seatsInFirstRow,a);
    lint seatsLeftInFirstRow=seatsInFirstRow-seatsOccFirstRow;
    lint seatsInSecondRow=m;
    lint seatsOccSecondRow = min(seatsInSecondRow,b);
    lint seatsLeftsInSecondRow=seatsInSecondRow-seatsOccSecondRow;
    lint remainingSeats=seatsLeftInFirstRow+seatsLeftsInSecondRow;
    lint seatsRemainingOcc=min(c,remainingSeats);
    lint ans=seatsOccFirstRow+seatsOccSecondRow+seatsRemainingOcc;
    return ans; 
}

void solution(int test){
    while(test--){
        lint m;lint a;lint b;lint c;
        cin >> m >> a >> b >> c;
        lint ans=solveFunction(m,a,b,c);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}