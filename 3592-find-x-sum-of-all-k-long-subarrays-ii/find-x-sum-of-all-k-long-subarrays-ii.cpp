class Solution {
public:
    long long sum=0;
    set<pair<int,int>> main;
    set<pair<int,int>> scd;

    void removeFromSet(const pair<int,int> &p,int x){
        if(main.find(p)!=main.end()){
            sum-=1LL* p.first *p.second;
            main.erase(p); 

            if(!scd.empty()){
                auto largest=*scd.rbegin();

                main.insert(largest);
                scd.erase(largest);
                sum+=1LL * largest.first * largest.second;


            }
        }
        else{
            scd.erase(p);
        }
    }
    void insertInSet(const pair<int,int> &p,int x){
        if(main.size()<x || p>*main.begin()){
            sum+=1LL * p.first * p.second;

            main.insert(p);

            if(main.size()>x){
                auto smallest=*main.begin();

                main.erase(smallest);
                sum-=1LL * smallest.first *smallest.second;

                scd.insert(smallest);
            }
        }   
        else{
            scd.insert(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // Level ka question kafi kch sikhata hai 
        vector<long long> result;
        unordered_map<long long,int> mp;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            if(mp[nums[j]]>0){
                removeFromSet({mp[nums[j]],nums[j]},x); // Purana ka track rkh kr hi remove kr skte isliye update se pehle remove
            }
            mp[nums[j]]++;
            insertInSet({mp[nums[j]],nums[j]},x);

            if(j-i+1==k){
                result.push_back(sum);
                removeFromSet({mp[nums[i]],nums[i]},x);
                mp[nums[i]]--;

                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                else{  
                    insertInSet({mp[nums[i]],nums[i]},x);
                }
                i++;  // Shrink
            }
            j++;  // Expand
        }

        return result;
    }
};