class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N=nums.size();   // actual size

        int n=N/2;  

        int total=accumulate(nums.begin(),nums.end(),0);


        vector<vector<int>> left(n+1);  // left portion ke all possible subset ke sum size wise 

        vector<vector<int>> right(n+1);   // right portion ke all possible subset ke sum size wise 

        for(int mask=0;mask<(1<<n);mask++){    // explore all possible subset combination

            int sz=0;
            int lsum=0;
            int rsum=0;

            // ek subset bna lo 

            for(int i=0;i<n;i++){
                if(mask & (1<<i)){// check if yeh number lena chahiye ya nhi in the subset

                    sz++;  // kitne bnde le skta hu for this mask 

                    lsum+=nums[i];

                    rsum+=nums[i+n];

                }

                
            }

            // is pure se ek subset explore hua ese hi 2^n explore honge 

            left[sz].push_back(lsum);

            right[sz].push_back(rsum);

        }

        // left ko pkd ke right me best bnda dhundna hai isliye right ko sort size wise for binary search

        for(int sz=0;sz<=n;sz++){
            sort(right[sz].begin(),right[sz].end());  // hr size pe aane wale diff sum ko sort kr lo 
        } 

        int ans=INT_MAX;
        for(int sz=0;sz<=n;sz++){
            for(auto& a:left[sz]){
                int b=(total-2*a)/2;  // ideal value of b iske pass ki value dhundni hai

                int rsz=n-sz;

                

                auto it=lower_bound(right[rsz].begin(),right[rsz].end(),b);

                if(it!=right[rsz].end()){
                    ans=min(ans,abs(total-2*(a+(*it))));
                }

                if(it!=right[rsz].begin()){
                    auto tempIt=--it;

                    ans=min(ans,abs(total-2*(a+(*tempIt))));
                }

            }
        }

        return ans;
    }
};