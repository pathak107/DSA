#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node()
    {
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
    }
};

class list
{

    node *head;
    node *tail;

public:
    //functions
    list()
    {
        head = NULL;
        tail = NULL;
    }
    node *getHead() { return head; }
    void setHead(node *head) { this->head = head; }
    void insertFront(int x);
    void insertBack(int x);
    void print();
    void insertFromVector(vector<int> items);
    void insertFromArray(int items[], int size);
    int search(int x);
    node *FindMiddle();
    void reverse();
    void makeLoop(int pos);
    bool hasLoop();
    void removeLoop();
    void mergeAtAlternate(list &l);
    void deleteAll();
    void mergeSort();
    void sortedMerge(list &l2);
};

void list::insertFront(int x)
{
    node *temp = new node(x);

    //only when list is empty tail will be same as head
    //otherwise tail won't change in insertFront
    if (head == NULL)
    {
        tail = temp;
    }

    temp->next = head;
    head = temp;
}

void list::insertBack(int x)
{
    node *temp = new node(x);

    //only when list is empty tail will be same as head
    //otherwise head won't change in insertBack
    if (head == NULL)
    {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

void list::print()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << endl;
}

int list::search(int x)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    else
    {
        node *curr = head;
        int pos = 1;
        while (curr != NULL)
        {
            if (curr->data == x)
            {
                return pos;
            }
            pos++;
            curr = curr->next;
        }
        return -1;
    }
}

void list::insertFromVector(vector<int> items)
{
    for (int i = 0; i < items.size(); i++)
    {
        node *temp = new node(items[i]);
        if (head == NULL)
        {
            head = tail = temp;
        }
        tail->next = temp;
        tail = temp;
        temp->next = NULL;
    }
}

void list::insertFromArray(int items[], int size)
{
    for (int i = 0; i < size; i++)
    {
        node *temp = new node(items[i]);
        if (head == NULL)
        {
            head = tail = temp;
        }
        tail->next = temp;
        tail = temp;
        temp->next = NULL;
    }
}

node *list::FindMiddle()
{
    node *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = (fast->next)->next;
        slow = slow->next;
    }
    return slow;
}

void list::reverse()
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    node *curr = head, *prev = NULL, *next = NULL;
    tail = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (curr == NULL)
    {
        head = prev;
    }
}

void list::makeLoop(int pos)
{
    node *curr;
    curr = head;
    int i = 1;
    while (curr != NULL && i != pos)
    {
        curr = curr->next;
        i++;
    }
    tail->next = curr;
}

bool list::hasLoop()
{
    node *fast, *slow;
    fast = slow = head;
    if (tail->next = head)
    {
        return true;
    }
    while (fast != NULL || fast->next != NULL)
    {
        fast = (fast->next)->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void list::removeLoop()
{
    if (head == NULL)
    {
        return;
    }
    if (hasLoop() == 1)
    {
        node *fast, *slow;
        fast = slow = head;
        while (fast != NULL || fast->next != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;
            if (fast == slow)
            {
                break;
            }
        }
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

void list::mergeAtAlternate(list &l2)
{
    node *curr2 = l2.getHead();
    node *curr1 = head, *next1, *next2;
    while (curr1 != NULL && curr2 != NULL)
    {
        next1 = curr1->next;
        next2 = curr2->next;

        curr2->next = curr1->next;
        curr1->next = curr2;

        curr1 = next1;
        curr2 = next2;
    }

    l2.setHead(curr2);
}

void list::deleteAll()
{
    node *curr = head, *next;
    head = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}



void list::sortedMerge(list &l2)
{
    node *curr1 = this->head;
    node *curr2 = l2.getHead();
    node *next1 = curr1->next;
    node *next2 = curr2->next;
    node *head3 = NULL, *curr3 = NULL;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data < curr2->data)
        {
            if (head3 == NULL)
            {
                head3 = curr1;
                curr3 = curr1;
            }
            else
            {
                curr3->next = curr1;
                curr3 = curr1;
            }

            curr1->next = NULL;
            curr1 = next1;

            if (curr1 != NULL)
            {
                next1 = curr1->next;
            }
        }
        else
        {

            if (head3 == NULL)
            {
                head3 = curr2;
                curr3 = curr2;
            }
            else
            {
                curr3->next = curr2;
                curr3 = curr2;
            }

            curr2->next = NULL;
            curr2 = next2;
            if (curr2 !=NULL)
            {
                next2 = curr2->next;
            }
        }
    }
    if (curr1 != NULL)
    {
        curr3->next = curr1;
    }

    if (curr2 != NULL)
    {
        curr3->next = curr2;
    }

    this->setHead(head3);
    // l2.setHead(NULL);
}

int main()
{
    list l;
    vector<int> v{5, 6, 7, 8, 9, 10};
    int arr[] = {15, 16, 17, 18};
    // l.insertFront(1);
    // l.insertFront(2);
    // l.insertFront(3);
    // l.insertFront(4);
    // l.insertBack(1);
    // l.insertBack(2);
    // l.insertBack(3);
    // l.insertBack(4);
    // l.insertFromVector(v);
    // l.insertFromVector({11, 12, 13, 14});
    // l.insertFromArray(arr, 4);
    // cout << l.search(17) << "postion" << endl;
    // cout << "Middle: " << (l.FindMiddle())->data << endl;

    // l.print();

    // l.makeLoop(1);
    // cout << "Has loop: " << l.hasLoop() << endl;
    // l.removeLoop();
    // l.print();
    // l.deleteAll();
    // l.print();

    list l1, l2;
    l1.insertFromVector({1, 2, 3, 4});
    l2.insertFromVector({5, 6, 7, 8});
    l1.print();
    l2.print();
    l1.sortedMerge(l2);
    l1.print();
    l2.print();

    return 0;
}