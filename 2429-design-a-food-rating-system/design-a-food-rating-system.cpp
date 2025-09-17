class FoodRatings {
public:
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second > b.second; // smaller string should come first
            return a.first < b.first;                           // larger rating should come first
        }
    };
    vector<string> foodsGlobal;
    vector<string> cuisinesGlobal;
    vector<int> ratingsGlobal;
    unordered_map<string,int> foodIdx;
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,Comp>> mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        foodsGlobal=foods;
        cuisinesGlobal=cuisines;
        ratingsGlobal=ratings;
        for(int i=0;i<foods.size();i++){
            foodIdx[foods[i]]=i;
        }
        for (int i = 0; i < (int)foods.size(); ++i) {
            mp[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    void updateMP(string& cuisine,string& food,int newRating){
        
        mp[cuisine].push({newRating,food});
    }
    void changeRating(string food, int newRating) {
        int idx=foodIdx[food];
        ratingsGlobal[foodIdx[food]]=newRating;
        string cuisine=cuisinesGlobal[idx];
        updateMP(cuisine,food,newRating);
    }
    
    string highestRated(string cuisine) {
        auto& pq=mp[cuisine];
        while(!pq.empty()){
            int curr=pq.top().first;
            int idx=foodIdx[pq.top().second];
            if(curr==ratingsGlobal[idx]){
                return pq.top().second;
            }
            pq.pop();

        }
        return "";
    }   
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */