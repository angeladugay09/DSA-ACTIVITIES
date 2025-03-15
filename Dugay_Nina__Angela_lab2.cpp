#include <iostream>
using namespace std;

typedef struct Node{
    string songName;
    Node *link;
} Node;

Node* createNode(string data);

void traverse(Node *head) {
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist:" <<endl;
    while(temp != NULL) {
        cout << temp->songName<< "->" <<endl;
        if(temp->link == NULL) {
            cout << "NULL" <<endl;
        }

        temp = temp->link;
    }
}

Node *createNode(string data) {
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

Node *insertAtEnd(string data, Node *head) {
    if(head == NULL) {
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end. \n" <<endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL) {
        temp = temp->link;
    }

    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has beed inserted at the end. \n" <<endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head) {
    Node *newNode = createNode(data);
        newNode->link = head;

        head = newNode;

        cout << "A new node has been inserted at the beginning. \n" <<endl;

        return head;
}

string insertAfter(string after, string data, Node *head) {
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0) {
        if(temp == NULL) {
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "An new node has been added after " + after + ".\n";
}

string deleteAtEnd(Node *head) {
    if(head == NULL) {
        return "The linked list is empty. \n";
    }

    if(head->link == NULL) {
        delete head;
        return "The head has been deleted. \n";
    }

    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link != NULL) {
        temp = temp->link;
    }

    temp->link = NULL;

    return "A node has been deleted at the end. \n";
}

Node *deleteFromBeginning(Node *head) {
    if(head == NULL) {
        cout << "THe linked list is empty. \n" <<endl;
        return NULL;
    }

    if(head->link == NULL) {
        delete head;
    }

    head = head->link;

    cout << "A node has been delete from the beginning. \n" <<endl;

    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head) {
    if(head == NULL) {
        cout << "The linked list is empty. \n" <<endl;
        return NULL;
    }

    if(head->songName.compare(givenNode) == 0) {
        head = deleteFromBeginning(head);
        cout << "The Node " + givenNode + " has been deleted. \n" <<endl;
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0) {
        if(temp == NULL) {
            cout << "NO such node exist. \n" <<endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }

    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" <<endl;
    return head;
}

int main() {

    Node *head = createNode("Sanctuary by Joji");
    head = insertAtEnd("Beat It by Sean Kingston & Chris Brown", head);
    head = insertAtEnd("Rock with You by Michael Jackson", head);
    head = insertAtEnd("Tibok by Earl Agustin", head);

    head = insertAtBeginning("Walang Tayo by Ex Batallion & Flow G.", head);
    head = insertAtBeginning("Randomatic by James Reid", head);
    head = insertAtBeginning("Kaya Pala by Patch Quiwa", head);
    head = insertAtBeginning("Blue Butterflies by JHIN", head);

    cout << insertAfter("Blue Butterflies by JHIN", "Tingin by Cup of Joe", head) <<endl;
    cout << insertAfter("Tingin by Cup of Joe", "Namumula by Cup of Joe", head) <<endl;
    cout << insertAfter("Namumula by Cup of Joe", "Palagi by TJ Monterde", head) <<endl;
    
    cout << deleteAtEnd(head) <<endl;
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("Kaya Pala by Patch Quiwa", head);
    
    traverse(head);

    return 0;
}
