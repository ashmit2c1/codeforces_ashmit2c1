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

bool solvefunction(lint n,lint k,lint x,vector<lint>&arr){
    if(x==1 && k==1){
        return false;
    }
    if(x!=1){
        forloop(1,n+1){
            arr.push_back(1);
        }
        return true;
    }
    if(k==2){
        if(x==1){
            if(n%2==0){
                lint times=n/2;
                forloop(1,times+1){
                    arr.push_back(2);
                }
                return true;
            }else{
                return false;
            }
        }
    }
    if(k>=3){
        if(x==1){
            if(n%2==0){
                lint times=n/2;
                forloop(1,times+1){
                    arr.push_back(2);
                }
                return true;
            }else{
                n-=3;
                lint times=n/2;
                forloop(1,times+1){
                    arr.push_back(2);
                }
                arr.push_back(3);
                return true;
            }
        }
    }
}
void solution(int test){
    while(test--){
        lint n;lint k;lint x;
        cin >> n >> k >> x;
        vector<lint>ans;
        bool answer=solvefunction(n,k,x,ans);
        if(answer==false){
            cout << "NO" << "\n";
        }else{
            cout << "YES" << "\n";
            cout << ans.size() << "\n";
            forloop(0,ans.size()){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}