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

void changeoperation(lint lefttemp, lint righttemp, vector<lint>&temp){
    temp[lefttemp]+=1;
    if(righttemp+1 < temp.size()){
        temp[righttemp+1]-=1;
    }
}
vector<lint>solvefunction(vector<pair<lint,lint>>&rec,lint k,vector<pair<lint,lint>>&questions){
    vector<lint>temp(200001,0);
    forloop(0,rec.size()){
        lint lefttemp = rec[i].first;
        lint righttemp = rec[i].second;
        changeoperation(lefttemp,righttemp,temp);
    }
    forloop(1,temp.size()){
        temp[i]+=temp[i-1];
    }
    vector<lint>shouldtake(temp.size(),0);
    forloop(0,temp.size()){
        if(temp[i]>=k){shouldtake[i]=1;}else{shouldtake[i]=0;}
    }
    forloop(1,shouldtake.size()){
        shouldtake[i]+=shouldtake[i-1];
    }
    vector<lint>ans;
    forloop(0,questions.size()){
        lint lefttemp = questions[i].first;
        lint righttemp = questions[i].second;
        lint cnt = shouldtake[righttemp]-shouldtake[lefttemp-1];
        ans.push_back(cnt);
    }
    return ans;
}
vector<lint>solvefunction2(vector<pair<lint,lint>>&rec,lint k,vector<pair<lint,lint>>&questions){
    unordered_map<lint,lint>mp;
    forloop(0,rec.size()){
        lint lefttemp = rec[i].first;
        lint righttemp = rec[i].second;
        secondfor(lefttemp,righttemp+1){
            mp[j]++;
        }
    }
    vector<lint>ans;
    forloop(0,questions.size()){
        lint leftemp = questions[i].first;
        lint righttemp = questions[i].second;
        lint cnt=0;
        secondfor(leftemp,righttemp+1){
            lint temp = j;
            if(mp.find(temp)!=mp.end()){
                lint val = mp[temp];
                if(val >=k){
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}

void solution(){
    lint n;cin >> n;
    lint k;cin >> k;
    lint q;cin >> q;
    vector<pair<lint,lint>>rec;
    forloop(0,n){
        lint a;lint b;
        cin >> a >> b;
        rec.push_back({a,b});
    }
    vector<pair<lint,lint>>questions;
    forloop(0,q){
        lint a;lint b;
        cin >> a >> b;
        questions.push_back({a,b});
    }
    vector<lint>ans=solvefunction(rec,k,questions);
    forloop(0,ans.size()){print(ans[i])}

}
int main(){
    solution();
}