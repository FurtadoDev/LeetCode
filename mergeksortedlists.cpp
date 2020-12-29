/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         struct ListNode* head = nullptr;
    struct ListNode* temp = nullptr;
    struct ListNode* prev = nullptr;


    struct  comparator {
        constexpr bool operator()(const struct ListNode* lhs, const struct ListNode* rhs) const
        {
            return lhs->val > rhs->val;
        }
    };

    priority_queue<struct ListNode*, std::vector<struct ListNode*>, comparator> minHeap;
    //vector<ListNode*> test;

    if (!lists.empty()) {

        for (int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr)
                minHeap.push(lists[i]);
        }

        if (!minHeap.empty()) {
            head = minHeap.top();
            minHeap.pop();

            if (head->next != nullptr) {
                minHeap.push(head->next);
            }
            head->next = nullptr;
            prev = head;
        }
        
        while (!minHeap.empty()) {
            temp = minHeap.top();
            minHeap.pop();
            if (temp->next != nullptr) {
               minHeap.push(temp->next);
            }
            temp->next = nullptr;
            prev->next = temp;
            prev = prev->next;
        }
    }

    /*
    for (int i = 0; i < test.size(); i++) {
        cout << test[i]->val << endl;
    }*/

    return head;
        
    }
	
	void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = temp->next;
        free(temp);
    }
}


struct ListNode* createList(vector<int> v) {
    struct ListNode* head = nullptr;
    struct ListNode* temp = nullptr;

    if (v.size() >= 1) {
        head = new ListNode(v[0]);
        temp = head;
        int i = 1;
        while (i < v.size()) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
            i++;
        }
    }
        
    return head;
}


void printList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = temp->next;
        cout << temp->val << endl;
    }
    cout << endl;
}
};