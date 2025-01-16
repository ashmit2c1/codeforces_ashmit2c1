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

lint solvefunction(char currentCharacter,string lights){
    if(currentCharacter=='g'){
        return 0;
    }
    lights+=lights;
    lint maxCount=0;
    lint count=0;
    forloop(0,lights.size()){
        char character = lights[i];
        if(character==currentCharacter){
            count=0;
            while(lights[i]!='g' && i < lights.size()){
                count++;
                i++;
            }
            maxCount = max(maxCount,count);
        }
    }
    return maxCount;
}

void solution(int test){
    while(test--){
        lint n;char ch;
        cin >> n >> ch ;
        string s;cin >> s;
        lint ans=solvefunction(ch,s);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}