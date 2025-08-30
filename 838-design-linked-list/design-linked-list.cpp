class MyLinkedList {
public:
    deque<int> dq;
    MyLinkedList() { }
    
    int get(int index) {
        if(index < 0 || index >= dq.size()) return -1;
        return dq[index];
    }
    
    void addAtHead(int val) {
        dq.push_front(val);
    }
    
    void addAtTail(int val) {
        dq.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0) dq.push_front(val);
        else if(index == dq.size()) dq.push_back(val);
        else if(index > dq.size()) return;
        else dq.insert(dq.begin() + index, val);
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= dq.size()) return;
        dq.erase(dq.begin() + index);
    }
};
