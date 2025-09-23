#include <unordered_map>
using namespace std;

class LRUCache {
public:
    struct ListNode {
        int val;              // stores the key (same as your version)
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    // minimal change: map now stores {value, prevPointer}
    unordered_map<int, pair<int, ListNode*>> mp;
    int n;
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int currSize = 0;

    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        int value = it->second.first;
        ListNode* prev = it->second.second;
        ListNode* node = prev->next;

        // move node to tail if not already tail
        if (node != curr) {
            // unlink node
            prev->next = node->next;
            if (node->next) {
                // update prev pointer for the node that followed 'node'
                mp[node->next->val].second = prev;
            }
            // append node to tail
            curr->next = node;
            mp[node->val].second = curr; // new prev of moved node
            node->next = nullptr;
            curr = node;
        }
        return value;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // update value and move to tail
            it->second.first = value;
            ListNode* prev = it->second.second;
            ListNode* node = prev->next;
            if (node != curr) {
                prev->next = node->next;
                if (node->next) mp[node->next->val].second = prev;

                curr->next = node;
                mp[node->val].second = curr;
                node->next = nullptr;
                curr = node;
            }
            return;
        }

        // insert new key
        if (currSize < n) {
            ListNode* temp = new ListNode(key);
            curr->next = temp;
            mp[key] = {value, curr};
            curr = temp;
            currSize++;
        } else {
            // evict LRU (head = dummy->next)
            ListNode* lru = dummy->next;
            if (lru) {
                mp.erase(lru->val);
                dummy->next = lru->next;
                if (dummy->next) {
                    mp[dummy->next->val].second = dummy;
                }
                if (lru == curr) { // if it was the only node
                    curr = dummy;
                }
                delete lru;
            }
            // insert new node at tail
            ListNode* temp = new ListNode(key);
            curr->next = temp;
            mp[key] = {value, curr};
            curr = temp;
        }
    }
};
