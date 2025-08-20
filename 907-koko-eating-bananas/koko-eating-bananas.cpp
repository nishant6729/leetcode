class Solution {
public:
    long long helper(vector<int>& piles,int mid,int limit){
        long long count=0;
        for(auto& i:piles){
            count+=1LL * i/mid;
            if(i%mid!=0) count++;
            if(count>limit) return count;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(lo<=hi){ // binary search on answer
            int mid=lo+(hi-lo)/2;
            long long time=helper(piles,mid,h);
            if(time>h){
                lo=mid+1;
            }
            else{
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }
};