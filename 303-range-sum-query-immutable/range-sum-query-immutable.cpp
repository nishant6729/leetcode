class NumArray {
public:
    vector<int> v;
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int prevSum=0;
        v=nums;
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            prevSum+=nums[i];
            temp[i]=prevSum;
            
        }
        prefixSum=temp;

    }
    
    int sumRange(int left, int right) {
        int temp=prefixSum[left]-v[left];
        int req=prefixSum[right]-temp;
        return req;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */