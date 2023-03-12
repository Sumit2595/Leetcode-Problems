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
    #define pi pair<int,ListNode*>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(int i=0;i<n;i++)
        {    if(lists[i]==NULL)
              continue;
            auto temp=lists[i];
            pq.push({temp->val,temp});
        }
      ListNode* l1=NULL;
        ListNode* l2;
       while(pq.empty()==false)
       {    auto t=pq.top();
              pq.pop();
          ListNode* newNode=new ListNode(t.first);
           if(l1==NULL)
            l1=newNode;
           else
           {  l2=l1;
              while(l2->next!=NULL)
                l2=l2->next;
              l2->next=newNode;
           }
         ListNode* temp=t.second;
          if(temp->next!=NULL)
          {  temp=temp->next;
             pq.push({temp->val,temp}); 
          }
       }
      return l1;      
    }
};