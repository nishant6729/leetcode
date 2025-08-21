class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx=0;
        vector<vector<int>> ans;
        bool flag=false;
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        while(idx<intervals.size()){
            vector<int> temp=intervals[idx];
            int start=temp[0];
            int end=temp[1];
            if(!flag){
                int start2=newInterval[0];
                if(start<start2){
                    ans.push_back(temp);
                    idx++;
                    continue;
                }
                else{
                    if(ans.size()==0) ans.push_back(newInterval);
                    else if(ans.back()[1]>=start2){
                        ans.back()[1]=max(ans.back()[1],newInterval[1]);
                    }
                    else{
                        ans.push_back(newInterval);
                    }
                    flag=true;
                    continue;
                }
            }
            else{
                if(ans.back()[1]>=intervals[idx][0]){
                    ans.back()[1]=max(ans.back()[1],intervals[idx][1]);
                }
                else{
                    ans.push_back(intervals[idx]);
                }
            }
            idx++;
        }
        if(!flag){
            if(ans.back()[1]>=newInterval[0]){
                ans.back()[1]=max(ans.back()[1],newInterval[1]);
            }
            else{
                ans.push_back(newInterval);
            }
        }
        return ans;
    }
};