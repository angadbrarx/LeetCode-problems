//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/*  Step1 - Find mid
    Step2 - sort left and right recursively
    Step3 - Merge 2 sorted LL
*/

class Solution{
  public:
  //Step 1 - find mid
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while( left != NULL && right != NULL){
            if(left -> data < right -> data){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }   
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
            
        ans = ans -> next;
        return ans;
        
    }
    
    /*
    Node* merge(Node* left, Node* right){
        Node* curr1 = left;
        Node* curr2 = right;
        Node* next1 = curr1 -> next;
        
        
        if(left -> next == NULL && right != NULL){
             left -> next = right;
             return left;
        }
        
        while(next1 != NULL && curr2 != NULL){
            if(curr2 -> data > curr1 -> data && curr2 -> data < next1 -> data){
                curr1 -> next = curr2;
                Node* next2 = curr2 -> next;
                curr2 -> next = next1;
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1 = curr1 -> next;
                next1 = next1 -> next;
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return left;
                }
            }
        }
        return left;
    }
    
    */
    
    
    
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        //find mid
        Node* mid = findMid(head);
        
        //split into two halves 
        Node* left = head;
        Node* right = mid -> next;
        mid -> next = NULL;
        
        //sort recursively
        left = mergeSort(left);
        right = mergeSort(right);
        
        //merge both halves
        //if(left -> data <= right -> data)
        Node* final = merge(left, right);
        //else
            //Node* final = merge(right, left);
        
        return final;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends