//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends

class Solution
{   
    public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
// M -2 w/o using map by changing links
    // TC = O(n)
    // SC = O(1)
    
    // public:
    // Node *copyList(Node *head)
    // {
    //     //Step 1 - create clone LL
        
    //     Node* cloneHead = NULL;
    //     Node* cloneTail = NULL;
        
    //     Node* temp = head;
    //     while(temp != NULL){
    //         insertAtTail(cloneHead, cloneTail, temp -> data);
    //         temp = temp -> next;
    //     }
        
    //     //Step 2 - add cloneNodes in between original list
        
    //     Node* originalNode = head;
    //     Node* cloneNode = cloneHead;
        
    //     while(originalNode != NULL && cloneNode != NULL){
    //         Node* next = originalNode -> next;
    //         originalNode -> next = cloneNode;
    //         originalNode = next;
            
    //         next = cloneNode -> next;
    //         cloneNode -> next = originalNode;
    //         cloneNode = next;
            
    //     }
        
    //     //Step 3 - random pointers copy
        
    //         temp = head;
    //         while(temp != NULL){
    //             if(temp -> next != NULL){
    //                 //tertiary operator to replace lines 80-85
    //                 // temp -> next -> random = temp -> random ? temp -> random -> next : NULL
                    
    //                 if(temp -> arb != NULL){
    //                     temp -> next -> arb = temp -> arb -> next;  
    //                 }
    //                 else{
    //                     temp -> next = NULL;
    //                 }
    //                 //moving temp forward by 2 as temp -> next = cloneNode
    //                 temp = temp -> next -> next;
    //             }
               
    //         }
            
        
    //     //Step 4 - Revert changes made in step 2
        
    //         originalNode = head;
    //         cloneNode = cloneHead;
            
    //         while(originalNode != NULL && cloneNode != NULL){
            
    //         originalNode -> next = cloneNode -> next;
    //         originalNode = originalNode -> next;
            
    //         if(originalNode != NULL)
    //             cloneNode -> next = originalNode -> next;
    //         cloneNode = cloneNode -> next;
            
    //     }
    //     //Step 5 - return ans
    //         return cloneHead;
    // }
        
    
    
    public:
    Node *copyList(Node *head)
    {
        //Step 1 - create clone LL
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //Step 2 - add cloneNodes in between original list
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
            
        }
        
        //Step 3 - random pointers copy
        
            temp = head;
            while(temp != NULL){
                if(temp -> next != NULL){
                    //tertiary operator to replace lines 80-85
                    temp -> next -> arb = temp -> arb ? 
                    temp -> arb -> next : temp -> arb;
                    
                    // if(temp -> arb != NULL){
                    //     temp -> next -> arb = temp -> arb -> next;  
                    // }
                    // else{
                    //     temp -> next = NULL;
                    // }
                    //moving temp forward by 2 as temp -> next = cloneNode
                    temp = temp -> next -> next;
                }
               
            }
            
        
        //Step 4 - Revert changes made in step 2
        
            originalNode = head;
            cloneNode = cloneHead;
            
            while(originalNode != NULL && cloneNode != NULL){
            
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL)
                cloneNode -> next = originalNode -> next;
            
            cloneNode = cloneNode -> next;
            
        }
        //Step 5 - return ans
            return cloneHead;
    }
// M-1 Using map
        // TC = O(n)
        // SC = O(n)
/*
        //Step 1 - Create clone list using next
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //Step 2 - create mapping of originalNode and cloneNode
        unordered_map<Node*, Node*>oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        //assign random pointers to clone LL
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> arb = oldToNewNode[originalNode -> arb];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
            
        }
        return cloneHead;
    }
    */   
    


};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends