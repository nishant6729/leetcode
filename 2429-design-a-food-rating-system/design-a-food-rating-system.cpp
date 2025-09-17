#include <bits/stdc++.h>
using namespace std;

// Comparator: larger rating first; on tie lexicographically smaller string first.
struct Comp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first == b.first) return a.second > b.second; // smaller string should come first
        return a.first < b.first;                           // larger rating should come first
    }
};

class FoodRatings {
public:
    unordered_map<string,int> foodIdx;
    vector<int> rating;
    vector<string> cuisinesGlobal;
    unordered_map<string,unordered_map<string,int>> mp;
    vector<string> foodGlobal;

    // === NEW: per-cuisine heap for O(log n) highest lookup with lazy deletion ===
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Comp>> heaps; // <<< CHANGED
    // ======================================================================

    // updateRating now updates map + rating vector + pushes new value into heap
    void updateRating(int newRating, string& food){
       int idx = foodIdx[food];
       const string &cuisine = cuisinesGlobal[idx];

       mp[cuisine][food] = newRating;   // update current rating map
       rating[idx] = newRating;         // keep vector consistent

       // push new pair into the cuisine heap (lazy deletion of old entries)
       heaps[cuisine].push({newRating, food}); // <<< CHANGED
    }

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        rating = ratings;
        foodGlobal = foods;
        cuisinesGlobal = cuisines;

        for (int i = 0; i < (int)foods.size(); ++i) {
            foodIdx[foods[i]] = i;
        }
        for (int i = 0; i < (int)foods.size(); ++i) {
            mp[cuisines[i]][foods[i]] = ratings[i];
        }

        // === NEW: initialize heaps with initial pairs ===
        for (int i = 0; i < (int)foods.size(); ++i) {                         // <<< CHANGED
            heaps[cuisines[i]].push({ratings[i], foods[i]});                   // <<< CHANGED
        }                                                                      // <<< CHANGED
        // =======================================================
    }

    void changeRating(string food, int newRating) {
        updateRating(newRating, food);
    }

    string highestRated(string cuisine) {
        // Use heap for this cuisine and pop stale entries until top is valid
        auto &pq = heaps[cuisine]; // creates empty pq if not present (same behavior as before)
        while (!pq.empty()) {
            auto top = pq.top(); // pair<int,string> -> {rating, food}
            int cur = mp[cuisine][top.second]; // current rating from the authoritative map
            if (top.first == cur) {
                return top.second;
            }
            // stale entry, discard
            pq.pop(); // <<< CHANGED
        }

        // fallback (shouldn't happen if inputs valid): scan map (keeps behavior safe)
        int maxRating = INT_MIN;
        string ans;
        for (auto &p : mp[cuisine]) {
            if (p.second > maxRating) {
                maxRating = p.second;
                ans = p.first;
            } else if (p.second == maxRating) {
                if (p.first < ans) ans = p.first;
            }
        }
        return ans;
    }
};
