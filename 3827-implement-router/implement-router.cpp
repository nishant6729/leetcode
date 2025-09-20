class Router {
public:
    deque<vector<int>> dq;
    set<vector<int>> visited;                       // keep as you had it
    unordered_map<int, deque<int>> destTimes;       // NEW: per-destination timestamps (in insertion order)
    int n;

    Router(int memoryLimit) : dq(), visited(), destTimes(), n(memoryLimit) {
    }

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> temp = {source, destination, timestamp};
        if (visited.find(temp) != visited.end()) return false;

        if ((int)dq.size() == n) {
            // evict oldest from dq, visited and destTimes
            vector<int> old = dq.front();
            dq.pop_front();
            visited.erase(old);

            int oldDest = old[1];
            auto it = destTimes.find(oldDest);
            if (it != destTimes.end()) {
                if (!it->second.empty()) it->second.pop_front();
                if (it->second.empty()) destTimes.erase(it);
            }
        }

        dq.push_back(temp);
        visited.insert(temp);
        destTimes[destination].push_back(timestamp); // append timestamp for this destination
        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty()) return {};              // guard empty
        vector<int> ans = dq.front();
        dq.pop_front();
        visited.erase(ans);

        int dest = ans[1];
        auto it = destTimes.find(dest);
        if (it != destTimes.end()) {
            if (!it->second.empty()) it->second.pop_front();
            if (it->second.empty()) destTimes.erase(it);
        }
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;
        const deque<int>& times = it->second;
        // deque has random-access iterators, so binary search works
        auto itL = lower_bound(times.begin(), times.end(), startTime);
        auto itR = upper_bound(times.begin(), times.end(), endTime);
        return (int)(itR - itL);
    }
};
