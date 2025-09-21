class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> available;
    set<tuple<int,int,int>> rented;
    unordered_map<string,int> price_map;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry:entries){

            int shop=entry[0];
            int movie=entry[1];
            int price=entry[2];

            available[movie].insert({price,shop});    // sorted on the basis of price
            string key = to_string(shop) + "#" + to_string(movie); // CHANGED
            price_map[key]=price;
        }
    }
    
    vector<int> search(int movie) {
        int count=0;
        if(available[movie].size()==0) return {};
        vector<int> ans;
        for(auto& p:available[movie]){
            if(count<5){
                ans.push_back(p.second);
                count++;
            }
            else break;
            
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        string key = to_string(shop) + "#" + to_string(movie); // CHANGED
        int price=price_map[key];
        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        string key = to_string(shop) + "#" + to_string(movie); // CHANGED
        int price=price_map[key];
        available[movie].insert({price,shop});

        rented.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int count=0;

        for(auto& p:rented){
            if(count<5){
                ans.push_back({ get<1>(p), get<2>(p) });
                count++;
            }
            else break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */