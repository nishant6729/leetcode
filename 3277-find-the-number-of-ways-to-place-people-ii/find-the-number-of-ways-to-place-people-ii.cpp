class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // pichle wale part me O(n^3) bhi accepted tha but isme constraint ki wajah se optimisation  zaruri hai

        // har point ko A bnaenge fir B ke cases dekhenge
        auto lambda=[](vector<int>& point1,vector<int>&point2){
            if(point1[0]==point2[0]){
                return point1[1]>point2[1];    //har point jo A ban skta woh left me hona chahiye uske eligible sare B right me
            }   
            else{
                return point1[0]<point2[0];
            } 
        };
        int n=points.size();
        int result=0;
        sort(points.begin(),points.end(),lambda);
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];    // left point toh hai kyuki x ke basis pe sorting
            int bestY=INT_MIN;     // koi bich me na fse dekhne ke liye
            
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                if(y2>y1) continue;  // upper part me chla gya fail hai 

                if(y2>bestY){
                    result++;
                    bestY=y2;      //is bestY se chota koi banda aaya toh pichla wala bestY wala bnda bich me fs jaega 
                }
            }
        }
        return result;
    }
};