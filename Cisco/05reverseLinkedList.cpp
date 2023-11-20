/*
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.

Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.

GFG : https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1?page=1&company=Cisco&sortBy=submissions
*/

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

//* time : O(N) space : O(1)
Node* reverseLinkedList(Node* head) {

    //if list has only 1 element or it is null then..
    if( head == NULL || head-> next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;

    while( curr != nullptr) {

        Node* next = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    
}