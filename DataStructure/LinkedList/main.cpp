#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int _val) : val(_val),next(NULL) {}
};

Node *tail = NULL,*head = NULL;


void insertLast(int x) {

    Node *temp_node = new Node(x);

    if(head == NULL) {
        tail = head = temp_node;
    }
    else {
        tail->next = temp_node;
        tail = temp_node;
    }
}

void doTraverse() {

    Node *it = head;

    if(it==NULL)return;

    while(it->next!=NULL) {

        cout<<it->val<<endl;
        it = it->next;
    }

    cout<<it->val<<endl;

    return;
}

int main() {

   return 0;
}
