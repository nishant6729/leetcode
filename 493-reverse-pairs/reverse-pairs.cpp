class Solution {
public:
    int c=0;
    void reversepairs(vector<int> &a,vector<int> &b){
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()){
            if((double)a[i]>(double)2*b[j]){
                c+=a.size()-i;
                j++;
            }
            else{
                i++;
                // j=0;
            }
        }
    }
    void merge(vector<int> &v1,vector<int> &v2,vector<int> &v3){
        int i=0;
        int j=0;
        int k=0;
        while(k<v3.size()){
            if(i>=v1.size()){
            v3[k]=v2[j];
            j++;
            k++;
            }
        else if(j>=v2.size()){
            v3[k]=v1[i];
            i++;
            k++;
            }
        else if(v1[i]<=v2[j]){
            v3[k]=v1[i];
            i++;
            k++;
            }
        else if(v2[j]<v1[i]){
            v3[k]=v2[j];
            j++;
            k++;
        }
        }
    }
    void mergesort(vector<int> &v){
        int n=v.size();
        if(n==1) return ;
        int n1=n/2;
        int n2=n-n/2;
        vector<int> a(n1);
        vector<int> b(n2);
        for(int i=0;i<n1;i++){
            a[i]=v[i];
        }
        for(int i=0;i<n2;i++){
            b[i]=v[i+n1];
        }
        mergesort(a);
        mergesort(b);
        reversepairs(a,b);
        merge(a,b,v);
        a.clear();
        b.clear();
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums);
        return c;
    }
};