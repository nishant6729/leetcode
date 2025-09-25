class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() { }

    void addNum(int num) {
        // keep insertion rule same (equal goes to left)
        if(left.size()==0 || left.top()>=num){
            left.push(num);
        }
        else{
            right.push(num);
        }

        // CHANGE: rebalance immediately after insertion (minimal fix)
        if(left.size() > right.size() + 1){   // left too big -> move one to right
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size()){  // right bigger -> move one to left
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        // CHANGE: no rebalancing here — just return median
        if(left.size()==right.size()){
            return ( (double)left.top() + (double)right.top() ) / 2.0;
        }
        else {
            return (double)left.top();
        }
    }
};
