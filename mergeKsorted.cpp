#include <vector>
#include <algorithm>
#include <iostream>
#include<queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* head = ans;
        priority_queue<ListNode* ,vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        while(pq.size()>0 && lists.size()>0){
            ListNode* temp = pq.top();
            head -> next = new ListNode(pq.top()->val);
            pq.pop();
            if(temp->next){
                pq.push(temp->next);
            }    
            head = head-> next;
        }
        return ans->next;
    }
};