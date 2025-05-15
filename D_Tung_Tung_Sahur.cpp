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
bool solvefunction(string sequence, string sound){
    if(sequence==sound){
        return true;
    }
    if(sequence[0]!=sound[0]){
        return false;
    }
    lint i=1;
    lint j=1;
    while(i<sound.size() && j<sequence.size()){
        if(sound[i]==sequence[j]){
            i++;j++;
        }else{
            if(sound[i]==sound[i-1]){
                i++;
                if(sound[i]!=sequence[j]){
                    return false;
                }else{
                    i++;j++;
                }
            }else{
                return false;
            }
        }
    }
    if(j==sequence.size() && i==sound.size()){
        return true;
    } else if (j == sequence.size()) {
        while (i < sound.size()) {
            if (i > 0 && sound[i] == sound[i - 1]) {
                i++;
            } else {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
void solution(int test){
    while(test--){
        string sequence;
        string sound;
        cin >> sequence >> sound;
        bool ans=solvefunction(sequence,sound);
        if(ans==true){print("YES")}else{print("NO")}


    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}