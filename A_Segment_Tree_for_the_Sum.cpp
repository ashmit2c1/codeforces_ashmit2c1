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

class SegmentTree{
    private:
        vector<lint>sumtree;
        vector<lint>arr;
        lint n;
        // build max
        void buildsum(lint node,lint start,lint end){
            if(start==end){
                sumtree[node]=arr[start];
            }else{
                lint mid = start + (end-start)/2;
                lint left=2*node+1;
                lint right=2*node+2;
                buildsum(left,start,mid);
                buildsum(right,mid+1,end);
                sumtree[node]=sumtree[left]+sumtree[right];
            }
        }
        // query max 
        lint querysum(lint node,lint start,lint end,lint L,lint R){
            if(R<start || L>end){
                return 0;
            }
            if(L<=start && R>=end){
                return sumtree[node];
            }
            lint mid = start + (end-start)/2;
            lint left = 2*node+1;
            lint right = 2*node+2;
            return querysum(left,start,mid,L,R) + querysum(right,mid+1,end,L,R);
        }
        // update sum 
        void updatesum(lint node,lint start,lint end,lint index,lint value){
            if(start==end){
                sumtree[node]=value;
            }else{
                lint mid = start + (end-start)/2;
                lint left = 2*node+1;
                lint right = 2*node+2;
                if(index<=mid){
                    updatesum(left,start,mid,index,value);
                }else{
                    updatesum(right,mid+1,end,index,value);
                }
                sumtree[node]=sumtree[left]+sumtree[right];
            }
        }


    public:
        SegmentTree(vector<lint>&inputarr){
            n=inputarr.size();
            arr=inputarr;
            sumtree.resize(4*n,0);
            buildsum(0,0,n-1);
        }
        lint rangesum(lint L,lint R){
            return querysum(0,0,n-1,L,R);
        }
        void updatevalue(lint index,lint value){
            updatesum(0,0,n-1,index,value);
        }
};


vector<lint>solvefunction(vector<lint>&arr,vector<pair<lint,pair<lint,lint>>>&queries){
    vector<lint>ans;
    SegmentTree segtree(arr);
    forloop(0,queries.size()){
        lint type = queries[i].first;
        if(type==1){
            lint index = queries[i].second.first;
            lint value = queries[i].second.second;
            segtree.updatevalue(index,value);
        }else{
            lint left = queries[i].second.first;
            lint right = queries[i].second.second;
            lint answer = segtree.rangesum(left,right-1);
            ans.push_back(answer);
        }
    }
    return ans;
}
void solution(){
    lint n;cin >> n;
    lint q;cin >> q;
    vector<lint>arr;
    forloop(0,n){lint x; cin >> x;arr.push_back(x);}
    vector<pair<lint,pair<lint,lint>>>queries;
    forloop(0,q){
        lint a;lint b;lint c;
        cin >> a >> b >> c;
        queries.push_back({a,{b,c}});
    }
    vector<lint>ans=solvefunction(arr,queries);
    forloop(0,ans.size()){
        cout << ans[i] << "\n";
    }

}
int main(){

    solution();
}