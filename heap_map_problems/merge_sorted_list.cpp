/**

 Merge k sorted linked lists and return it as one sorted list.
    1 -> 10 -> 20
    4 -> 11 -> 13
    3 -> 8 -> 9

 so after merging all the sorted list we will get
 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        while(A[i]!=NULL){
            // cout<<A[i]->val<<" ";
            pq.push(A[i]->val);
            A[i]= A[i]->next;
        }
        // cout<<"break";
    }
    // remove the first element and assign it 
    // to the head of the final linked list
    ListNode* head = (ListNode*)(malloc(sizeof(ListNode)));
    ListNode* curr = (ListNode*)(malloc(sizeof(ListNode)));
    if(pq.size()>=1){
        // cout<<"hello";
        head->val = pq.top();
        // cout<<head->val<<" ";
        // pq.pop();
        head->next = NULL;
        head = curr;
    }
    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    while(!pq.empty()){
        ListNode* temp = (ListNode*)(malloc(sizeof(ListNode)));
        temp->val = pq.top();
        temp->next = NULL;
        pq.pop();
        curr->next = temp;
        curr=temp;
    }
    return head->next;
}

