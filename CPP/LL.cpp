#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert_front(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
}

void insert_back(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> next = NULL;
}

void insert_pos(Node* &head, int data, int pos){
    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void delete_front(Node* &head){
    Node* temp = head;
    head = head -> next;
    delete temp;
}

void delete_back(Node* &head){
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = NULL;
}

void delete_pos(Node* &head, int pos){
    Node* temp = head;
    for(int i = 0; i < pos - 1; i++){
        temp = temp -> next;
    }
    Node* temp2 = temp -> next;
    temp -> next = temp -> next -> next;
    delete temp2;
}

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    insert_front(head, 2);
    insert_front(head, 3);
    insert_back(head, 4);
    insert_back(head, 5);
    insert_pos(head, 6, 3);
    display(head);
    delete_front(head);
    delete_back(head);
    delete_pos(head, 2);
    display(head);

    return 0;
}