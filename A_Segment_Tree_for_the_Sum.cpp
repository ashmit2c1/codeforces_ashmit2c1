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
        // building sum tree
        void buildSumTree(lint node,lint start,lint end){
            if(start==end){
                sumtree[node]=arr[start];
            }else{
                lint mid = start + (end-start)/2;
                lint leftchild = 2*node+1;
                lint rightchild = 2*node+2;
                buildSumTree(leftchild,start,mid);
                buildSumTree(rightchild,mid+1,end);
                sumtree[node]=sumtree[leftchild]+sumtree[rightchild];
            }
        }
        void update(lint node,lint start,lint end,lint index,lint value){
            if(start==end){
                sumtree[node]=value;
            }else{
                lint mid = start + (end-start)/2;
                lint leftchild = 2*node+1;
                lint rightchild = 2*node+2;
                if(index<=mid){
                    update(leftchild,start,mid,index,value);
                }else{
                    update(rightchild,mid+1,end,index,value);
                }
                sumtree[node]=sumtree[leftchild]+sumtree[rightchild];
            }
        }
        int querySum(lint node,lint start,lint end,lint L,lint R){
            if(R<start || L>end){
                return 0;
            }
            if(L<=start && R>=end){
                return sumtree[node];
            }
            lint mid = start + (end-start)/2;
            lint leftchild = 2*node+1;
            lint rightchild = 2*node+2;
            return querySum(leftchild,start,mid,L,R) + querySum(rightchild,mid+1,end,L,R);
        }
        public:
            SegmentTree(vector<lint>&inputarr){
                n=inputarr.size();
                arr=inputarr;
                sumtree.resize(4*n);
                buildSumTree(0,0,n-1);
            }
            lint rangeSum(lint L,lint R){
                return querySum(0,0,n-1,L,R);
            }
            void updateValue(lint index,lint value){
                update(0,0,n-1,index,value);
            }
};

vector<lint>solvefunction(vector<lint>&arr,vector<pair<lint,pair<lint,lint>>>&queries){
    vector<lint>ans;
    SegmentTree segTree(arr);
    forloop(0,queries.size()){
        lint type = queries[i].first;
        lint first = queries[i].second.first;
        lint second = queries[i].second.second;
        if(type==1){
            segTree.updateValue(first,second);
        }else{
            lint answer=segTree.rangeSum(first,second-1);
            ans.push_back(answer);
        }
    }
    return ans;
}
void solution(){
    lint n;cin >>n;
    lint q;cin >> q;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    vector<pair<lint,pair<lint,lint>>>queries;
    forloop(0,q){
        lint type;lint index;lint value;
        cin >> type >> index >> value;
        queries.push_back({type,{index,value}});
    }
    vector<lint>ans=solvefunction(arr,queries);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }

}
int main(){

    solution();
}