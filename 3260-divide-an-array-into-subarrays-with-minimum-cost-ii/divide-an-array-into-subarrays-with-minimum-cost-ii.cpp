class Solution {
public:
    typedef long long ll;
    typedef pair<ll,ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();

        // first ele toh fix hai yani baki k-1 ele dhundhne hai 

        int i=1;

        
        long long sum=0;

        set<P> included;
        set<P> remaining;

        // initial window ko bna lete hai 
        while(i<n && i-dist<1){  // initial point window ka 1 se aage aa jae 
            included.insert({nums[i],i});
            sum+=nums[i];

            if(included.size()>k-1){
                P temp=*included.rbegin();   // max element ek window me jo top k-1 min elements me nhi hai
                remaining.insert(temp);  // same window me but k se jyda ho gya ele ka count toh remaing wale me daal ke rkho

                included.erase(temp);
                sum-=temp.first;
                
            }
            i++;
        }

        ll result=LLONG_MAX;
        while(i<n){ // saari windows lete hai 

            included.insert({nums[i],i});
            sum+=nums[i];

            if(included.size()>k-1){
                P temp=*included.rbegin();   // max element ek window me jo top k-1 min elements me nhi hai
                remaining.insert(temp);  // same window me but k se jyda ho gya ele ka count toh remaing wale me daal ke rkho

                included.erase(temp);
                sum-=temp.first;
                
            }
            result=min(result,sum);   // ek window se kch mila 

            // window slide krenge 
            P temp={nums[i-dist],i-dist};  // jisko nikalna hai 
            if(included.count(temp)){
                included.erase(temp);
                sum-=temp.first;

                // k se size choti ho gyi included ki 
                if(!remaining.empty()){
                    P here=*remaining.begin();
                    included.insert(here);

                    sum+=here.first;
                    remaining.erase(here);
                }
            }
            else{
                remaining.erase(temp);
            }
            i++;
        }
        return nums[0]+result;   

    }
};