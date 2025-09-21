class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int i=0;
        int j=1;
        int n=intervals.size();
        vector<vector<int>> ans;
        while(i<n){
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];

            while(j<n && intervals[j][0]<=currEnd){
                currEnd=max(currEnd,intervals[j][1]);
                j++;
                
            }
            if(j-1!=i){
                int tempEnd=currEnd;
                int tempStart=intervals[i][0];
                ans.push_back({tempStart,tempEnd});
            }
            else{
                ans.push_back(intervals[i]);
            }
            i=j;
            j=i+1;
        }
        return ans;
    }
};