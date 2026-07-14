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
//walk both lists together
//at each step:
  //sum = l1->val + l2->val + carry
  //digit = sum % 10   (keep ones place)
  //carry = sum / 10   (carry to next)
  //create node with digit

//handle leftover carry at end

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            int digit=sum%10;
            tail->next=new ListNode(digit);
            tail=tail->next;
        }
        return dummy->next;
    }
};
