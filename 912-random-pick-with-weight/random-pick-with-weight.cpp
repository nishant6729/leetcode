#include <vector>
#include <random>

class Solution {
private:
    std::discrete_distribution<int> dist;
    std::mt19937 gen;

public:
    Solution(const std::vector<int>& w)
      : dist(w.begin(), w.end()) {
        std::random_device rd;
        gen.seed(rd());
    }

    int pickIndex() {
        return dist(gen);
    }
};
