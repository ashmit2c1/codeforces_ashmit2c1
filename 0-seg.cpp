#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    private:
        vector<int>arr;
        vector<int>mintree;
        vector<int>maxtree;
        vector<int>sumtree;
        int n;
        // build sum 
        void buildsum(int node,int start,int end){
            if(start==end){
                sumtree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                buildsum(left,start,mid);
                buildsum(right,mid+1,end);
                sumtree[node]=sumtree[left]+sumtree[right];
            }
        }
        // buil min 
        void buildmin(int node,int start,int end){
            if(start==end){
                mintree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                buildmin(left,start,mid);
                buildmin(right,mid+1,end);
                mintree[node]=min(mintree[left],mintree[right]);
            }
        }
        // build max
        void buildmax(int node,int start,int end){
            if(start==end){
                maxtree[node]=arr[start];
            }else{
                int mid = start + (end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                buildmax(left,start,mid);
                buildmax(right,mid+1,end);
                maxtree[node]=max(maxtree[left],maxtree[right]);
            }
        }
        // query sum 
        int querysum(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return 0;
            }
            if(L<=start && R>=end){
                return sumtree[node];
            }
            int mid = start + (end-start)/2;
            int left=2*node+1;
            int right=2*node+2;
            return querysum(left,start,mid,L,R)+querysum(right,mid+1,end,L,R);
        }
        // query min 
        int querymin(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return INT_MAX;
            }
            if(L<=start && R>=end){
                return mintree[node];
            }
            int mid = start + (end-start)/2;
            int left = 2*node+1;
            int right = 2*node+2;
            return min(querymin(left,start,mid,L,R),querymin(right,mid+1,end,L,R));
        }
        // query max
        int querymax(int node,int start,int end,int L,int R){
            if(R<start || L>end){
                return INT_MIN;
            }
            if(L<=start && R>=end){
                return maxtree[node];
            }
            int mid = start + (end-start)/2;
            int left = 2*node+1;
            int right = 2*node+2;
            return max(querymax(left,start,mid,L,R),querymax(right,mid+1,end,L,R));
        }
        // update sum 
        void updatesum(int node,int start,int end,int index,int value){
            if(start==end){
                sumtree[node]=value;
            }else{
                int mid = start + (end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                if(index<=mid){
                    updatesum(left,start,mid,index,value);
                }else{
                    updatesum(right,mid+1,end,index,value);
                }
                sumtree[node]=sumtree[left]+sumtree[right];
            }
        }
        // update min 
        void updatemin(int node,int start,int end,int index,int value){
            if(start==end){
                mintree[node]=value;
            }else{
                int mid = start + (end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                if(index<=mid){
                    updatemin(left,start,mid,index,value);
                }else{
                    updatemin(right,mid+1,end,index,value);
                }
                mintree[node]=min(mintree[left],mintree[right]);
            }
        }
        // update max 
        void updatemax(int node,int start,int end,int index,int value){
            if(start==end){
                maxtree[node]=value;
            }else{
                int mid = start+(end-start)/2;
                int left=2*node+1;
                int right=2*node+2;
                if(index<=mid){
                    updatemax(left,start,mid,index,value);
                }else{
                    updatemax(right,mid+1,end,index,value);
                }
                maxtree[node]=max(maxtree[left],maxtree[right]);
            }
        }
    public:
        SegmentTree(vector<int>&inputarr){
            n=inputarr.size();
            arr=inputarr;
            mintree.resize(4*n,INT_MAX);
            maxtree.resize(4*n,INT_MIN);
            sumtree.resize(4*n,0);
            buildmax(0,0,n-1);
            buildmin(0,0,n-1);
            buildsum(0,0,n-1);
        }
        int rangeSum(int L,int R){
            return querysum(0,0,n-1,L,R);
        }
        int rangeMin(int L,int R){
            return querymin(0,0,n-1,L,R);
        }
        int rangeMax(int L,int R){
            return querymax(0,0,n-1,L,R);
        }
        void update(int index,int value){
            updatesum(0,0,n-1,index,value);
            updatemin(0,0,n-1,index,value);
            updatemax(0,0,n-1,index,value);
        }
};

int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    SegmentTree segtree(arr);
    cout << segtree.rangeSum(0, 4) << "\n";
    cout << segtree.rangeMin(0, 4) << "\n";
    cout << segtree.rangeMax(0, 4) << "\n";
}