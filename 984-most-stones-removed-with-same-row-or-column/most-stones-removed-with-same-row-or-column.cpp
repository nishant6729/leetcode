class DisjointSet{
public:
        int n;

        vector<int> size;
        vector<int> parent;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }

        }
        int findParent(int n){
            if(parent[n]==n) return n;
            return parent[n]=findParent(parent[n]);
        }
        void DoUnion(int a,int b){
            a=findParent(a);
            b=findParent(b);

            if(a==b)  return;

            if(size[a]<=size[b]){
                parent[a]=b;
                size[b]+=size[a];
            }
            else{
                parent[b]=a;
                size[a]+=size[b];
            }

           
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();  // kitne stones hai

        DisjointSet ds(n+1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.DoUnion(i,j);
                }
            }
        }
        int component=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) component++;
        }
        return n-component;
    }
};