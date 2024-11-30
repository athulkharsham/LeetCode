#include <iostream>

using namespace std;

class Node
{
public:
    int data{};
    Node *next = nullptr;
    Node(int value) : data(value){}
};

class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

public:
	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;
    
    void print()
    {
        for(Node *curr = head; curr!=nullptr; curr = curr->next)
        {
            cout << curr->data << "->";
        }
        cout << "nullptr" << endl;
    }
    void print_nodes()
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void insert_end(int val)
    {
        Node *item = new Node(val);

        if(head == nullptr)
        {
            head = tail = item;
        }
        else
        {
            tail->next = item;
            tail = item;
        }
        length++;
    }

    int search_improved(int val)
    {
        Node *previous = nullptr;
        int index = 0;
        for(Node *current = head; current!=nullptr ; current=current->next, index++)
        {
            if(current->data == val)
            {
                if(previous!=nullptr)
                {
                    return index;
                }
                swap(previous->data, current->data);
                return index-1;
            }
            previous = current;
        }
        return -1;
    }

    void insert_front(int val)
    {
        Node *newNode = new Node(val);

        if(head==nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    ~LinkedList()
    {
        while (head!=nullptr)
        {
            Node *current = head->next;
            delete head;
            head = current;
        }
    }

	// bool is_same(const LinkedList &other) {	// using length
	// 	if(length != other.length)
	// 		return false;

	// 	Node* other_h = other.head;

	// 	for (Node* cur_h = head; cur_h; cur_h = cur_h->next) {
	// 		if(cur_h->data != other_h->data)
	// 			return false;
	// 		other_h = other_h->next;
	// 	}
	// 	return true;
	// }


    bool is_same(const LinkedList &other)
    {
        if(length == 0 && other.length == 0)
        {
            return true;
        }
        if(length!=other.length)
        {
            return false;
        }
        Node *other_h = other.head;
        while(head->next != nullptr)
        {
            if(head->data != other_h->data)
            {
                return false;
            }
            head = head->next;
            other_h = other_h->next;
        }
        return 1;
    }

    void delete_last()
    {
        if(length==0)
        {
            return;
        }
                
        Node *temp = head;
        if(length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *previous = head;

            while(temp->next != nullptr)
            {
                previous = temp;
                temp = temp->next;
            }
            tail = previous;
            tail->next = nullptr;
        }

        delete temp;
        length --;
    }

    void delete_node_with_key(int value)
    {
        if(length==0)
        {
            cout << "Error : empty list" << endl;
            return; 
        }
        Node *temp = head;
        if(length == 1 && temp->data != value)
        {
            cout << "Error: value does not exist" << endl;
            return;
        }
        else if(length ==1 && temp->data == value)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *previous = head;

            while(temp->next != nullptr && temp->data != value)
            {
                previous = temp;
                temp = temp->next;
            }
            previous->next = temp->next;
        }
        delete temp;
        length--;
    }

    void reverse()
    {
        if(length <= 1)
        {
            return;
        }

        Node *temp = head;
        head = tail;
        tail = temp;

        Node *after = temp->next;
        Node *before = nullptr;

        for(int i = 0; i < length; i ++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }
};



int main()
{
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);

    list.print();
    list.reverse();
    list.print();

    return 0;
}