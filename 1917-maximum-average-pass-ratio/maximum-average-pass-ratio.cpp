class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int e=extraStudents;
        priority_queue<pair<double,pair<int,int>>> pq;
        int n=classes.size();
        for(int i=0;i<n;i++){
            auto v=classes[i];

            double gain=(double)(v[0]+1)/(v[1]+1)-(double)v[0]/v[1];
            pq.push({gain,{i,1}});

        }
        vector<int> temp(n,0);
        while(e--){
            auto p=pq.top();
            pq.pop();
            int idx=p.second.first;
            int x=p.second.second;
            temp[idx]++;
            if(x+1<=extraStudents){
                double gain=(double)(classes[idx][0]+x+1)/(classes[idx][1]+x+1)-(double)(classes[idx][0]+x)/(classes[idx][1]+x);
                pq.push({gain,{idx,x+1}});
            }
        }
        double sum=0;
        for(int i=0;i<n;i++){
            int extra=temp[i];
            double newGain=(double)(classes[i][0]+extra)/(classes[i][1]+extra);
            sum+=newGain;
        }
        return sum/n;
    }
};