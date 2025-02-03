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
lint solvefunction(lint n, lint m, lint a, lint b){
    if (m >= n) {
        lint firstcost = n * a; 
        lint secondcost = b;
        return min(firstcost, secondcost);
    } else {
        lint firstcost = n * a; 
        lint full_m_ride_tickets = (n / m);
        lint remaining_rides = n % m; 
        lint price = full_m_ride_tickets * b;
        lint remprice = remaining_rides * a;
        lint rempricem = b;
        lint cond1 = price + remprice; 
        lint cond2 = price + rempricem;
        return min({firstcost, cond1, cond2});
    }
}
void solution(){
    lint n;lint m;lint a;lint b;
    cin >> n >> m >> a >> b;
    lint ans=solvefunction(n,m,a,b);
    print(ans)

}
int main(){
    solution();
}