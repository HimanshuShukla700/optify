#include <iostream>
using namespace:: std;
struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void remove(int value) {
        if (!head) {
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
using namespace std;
int main() 
{
    LinkedList s1;
    int choice;
    bool found;
    while(1)
    {
        std::cout << std::endl << "operation on the linked list" << std::endl;

        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Reverse"<<endl;
        
        cout<<"Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            cout << "Insert your element: ";
                int value;
                cin >> value;
                s1.insert(value);
                cout << endl;
                break;
            case 2:
            cout<<"Enter the element to delete"<<endl;
            int del;
            cin>>del;
            s1.remove(del);
            cout<<endl;
            break;
            case 3:
            cout<<"Enter the element to search"<<endl;
            int s;
            cin>>s;
            found = s1.search(s);
            if(found)
            cout<<s<<" found in the list"<<endl;
            else
            cout<<s<<" not found in the list"<<endl;
            cout<<endl;
            break;
            case 4:
            s1.display();
            cout<<endl;
            break;
            case 5:
            s1.reverse();
            cout<<"List reversed"<<endl;
            cout<<endl;
            break;
        }
    }
    return 0;
}