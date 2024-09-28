class Node {
public:
    int val;
    Node *prev, *next;

    Node(int val) {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class MyCircularDeque {
public:
    int n, t;
    Node *head, *tail;

    MyCircularDeque(int k) {
        n = k;
        t = k;
        head = NULL;
        tail = NULL;
    }
    
    bool insertFront(int value) {
        if(n <= 0)
            return false;

        Node* temp = new Node(value);

        if(head == NULL)
            head = tail = temp;
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        n--;
        return true;
    }
    
    bool insertLast(int value) {
        if(n <= 0)
            return false;

        Node* temp = new Node(value);
        if(tail == NULL)
            head = tail = temp;
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        n--;
        return true;
    }
    
    bool deleteFront() {
        if(head == NULL)
            return false;

        Node* toDelete = head;

        if(head == tail)
            head = tail = NULL;
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete toDelete;
        n++;
        return true;
    }
    
    bool deleteLast() {
        if(tail == NULL)
            return false;

        Node* toDelete = tail;

        if(head == tail)
            head = tail = NULL;
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete toDelete;
        n++;
        return true;
    }
    
    int getFront() {
        if(head == NULL)
            return -1;

        return head->val;
    }
    
    int getRear() {
        if(tail == NULL)
            return -1;

        return tail->val;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    bool isFull() {
        return n == 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
