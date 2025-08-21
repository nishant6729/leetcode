class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        int count=0;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(st.empty()) st.push(intervals[i]);
            else{
                if(intervals[i][0]<st.top()[1]){
                    count++;
                    if(st.top()[1]>intervals[i][1]){
                        st.pop();
                        st.push(intervals[i]);
                    }
                }
                else{
                    st.push(intervals[i]);
                }
            }
        }
        return count;
    }
};