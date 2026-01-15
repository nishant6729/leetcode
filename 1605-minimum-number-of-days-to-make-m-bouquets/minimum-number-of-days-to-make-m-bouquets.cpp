class Solution {
public:

    bool canBeTaken(int mid,vector<int>& bloomDay,int m,int k){
        int count=0;
        int overall=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                count++;
                if(count==k){
                    overall++;
                    count=0;
                }
            }
            else count=0;


        }

        return overall>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Dekhke lg rha ki O(nlogn) chl jaega but order disturb nhi kr skte 
        // Therefore apply BS on answers


        int lo=*min_element(bloomDay.begin(),bloomDay.end());
        int hi=*max_element(bloomDay.begin(),bloomDay.end());

        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;


            if(canBeTaken(mid,bloomDay,m,k)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }

        return ans;
    }
};