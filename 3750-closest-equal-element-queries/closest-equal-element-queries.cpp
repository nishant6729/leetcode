class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int,set<int>> mp;


        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].insert(i);
        }


        vector<int> ans;

        for(auto& q:queries){

            
            int ele=nums[q];

            if(mp[ele].size()==1){
                ans.push_back(-1);
            }
            else{
                if(q==*(mp[ele].begin())){
                    int n1=*(prev(mp[ele].end()));  

                    int n2=*(mp[ele].upper_bound(q));

                    int d1=(q-n1+n)%n;
                    int d2=n2-q;

                    ans.push_back(min(d1,d2));

                }

                else if(q==*(prev(mp[ele].end()))){
                    int n1=*(mp[ele].begin());
                    
                    int n2=*(prev(mp[ele].lower_bound(q)));

                    int d1=(n1-q+n)%n;

                    int d2=q-n2;

                    ans.push_back(min(d1,d2));

                }   

                else{
                    int n1=*(mp[ele].upper_bound(q));

                    int n2=*(prev(mp[ele].lower_bound(q)));

                    int d1=n1-q;

                    int d2=q-n2;

                    ans.push_back(min(d1,d2));
                }
            }

        }

        return ans;
    }
};