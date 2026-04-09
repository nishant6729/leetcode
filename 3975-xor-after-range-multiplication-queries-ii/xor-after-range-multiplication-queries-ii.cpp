class Solution {
public: 
    long long expPow(long long a,long long b){


        if(b==0) return 1;  

        int mod=1e9+7;

        long long halfPow=expPow(a,b/2);
        long long result=(halfPow*halfPow)%mod;
        if(b%2==1){
            result=(1LL*result*a)%mod;
        }

        return result;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
          //difference array ki concept use kro 

        int n=nums.size();

       
        int mod=1e9+7;

        int threshold=ceil(sqrt(n));

        unordered_map<int,vector<vector<int>>> mp;   // k:-queries or k chote k honge jo dikkt de skte 

        
        for(auto& query:queries){
            int li=query[0];
            int ri=query[1];

            int k=query[2];
            int vi=query[3];

            if(k>=threshold){   // in k se dikkt ni
                for(int idx=li;idx<=ri;idx+=k){
                    nums[idx]=(1LL*nums[idx]*vi)%mod;
                }
            }
            else{  // dikkt wale k's
                mp[k].push_back(query);
            }   
        }

        for(auto& p:mp){
            int k=p.first;
            auto list=p.second; 

            vector<long long> diffArray(n,1);


            for(auto& query:list){
                int li=query[0];
                int ri=query[1];
                int vi=query[3];

                int steps=(ri-li)/k;  // kitni steps me ri-> li li window me chl skta with k diff

                int nextIdx=li+(steps+1)*k;   // li->ri ki window ke bahar wala pehle idx jo kth step leke aaega

                diffArray[li]=(1LL*diffArray[li]*vi)%mod;

                if(nextIdx<n) diffArray[nextIdx]=(1LL*diffArray[nextIdx]*expPow(vi,mod-2))%mod;


            }

            // cummulative product

            for(int i=0;i<n;i++){
                if(i-k>=0){
                    diffArray[i]=(diffArray[i]*diffArray[i-k])%mod;
                }
            }

            for(int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diffArray[i]) % mod;
            }

        }

        int result=0;
        
        for(auto& ele:nums){
            result=result^ele;
        }

        return result;


    }
};