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
    struct Node{
        public:
            int index;
            ListNode* nodePointer;

            Node(int i,ListNode* h){
                this->index=i;
                this->nodePointer=h;
            }
    };

    struct cNode{
        bool operator()(const Node &a,const Node &b)const{
            return a.nodePointer->val>b.nodePointer->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node,vector<Node>,cNode> pq;
        ListNode* head=new ListNode(-1);
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(Node(i,lists[i]));
            }
        }
        ListNode* temp=head;
        while(!pq.empty()){
            Node topNode=pq.top();
            pq.pop();

            temp->next=new ListNode(topNode.nodePointer->val);
            temp=temp->next;

            //check if more ahead
            if(topNode.nodePointer->next!=NULL){
                pq.push(Node(topNode.index,topNode.nodePointer->next));
            }

        }
        
        
        //check for empty case 
        return head->next?head->next:NULL;
    }
};