class Solution {
public:
    const double epsilon=0.000001;
    bool solve(vector<double>& nums){
        if(nums.size()==1){
            return (abs(nums[0]-24)<=epsilon);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j) continue;
                vector<double> rem;
                for(int k=0;k<nums.size();k++){
                    if(k==i || k==j) continue;
                    rem.push_back(nums[k]);
                }
                double a=nums[i];
                double b=nums[j];
                vector<double> temp={a+b,a-b,b-a,a*b};
                if(abs(b)!=0.0){
                    temp.push_back(a/b);
                }
                if(abs(a)!=0.0){
                    temp.push_back(b/a);
                }
                for(auto val:temp){
                    rem.push_back(val); //Do
                    if(solve(rem)==true) return true; //Check
                    rem.pop_back(); // Undo
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i=0;i<cards.size();i++){
            nums.push_back(1.0 * cards[i]);
        }
        return solve(nums);
    }
};