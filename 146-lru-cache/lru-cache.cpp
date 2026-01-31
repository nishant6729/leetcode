class LRUCache {
public:
    list<int> dll;

    unordered_map<int,pair<int,list<int>::iterator>> mp;

    int k;
    LRUCache(int capacity) {
        k=capacity;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        int ans=mp[key].first;

        auto it=mp[key].second;

        dll.erase(it);

        dll.push_back(key);

        mp[key].second=prev(dll.end());

        return ans;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mp[key].first=value;

            dll.erase(mp[key].second);
            
            dll.push_back(key);

            mp[key].second=--dll.end();
     
        }
        else{
            if(mp.size()<k){
                dll.push_back(key);

                mp[key].first=value;
                mp[key].second=--dll.end();


            }
            else{

                int thatKey=*dll.begin();
                dll.erase(dll.begin());

                mp.erase(thatKey);

                mp[key].first=value;

                dll.push_back(key);

                mp[key].second=--dll.end();
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */