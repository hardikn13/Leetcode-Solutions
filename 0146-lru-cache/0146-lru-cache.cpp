class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val) {
                this -> key = key;
                this -> val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newNode)
    {
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteNode(Node* delNode)
    {
        Node* prevv = delNode -> prev;
        Node* nextt = delNode -> next;
        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            Node* arc = mp[key];
            int ans = arc -> val;

            mp.erase(key);
            deleteNode(arc);
            addNode(arc);

            mp[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            Node* arc = mp[key];
            mp.erase(key);
            deleteNode(arc);
        }

        if(mp.size() == n)
        {
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};




// ANOTHER APPROACH
// ----------------

// class LRUCache {
// public:
//     list<int> dll;
//     map<int, pair<list<int>::iterator, int>> mp;
//     int n;

//     LRUCache(int capacity) {
//         n = capacity;    
//     }
    
//     void makeRecentlyUsed(int key)
//     {
//         dll.erase(mp[key].first);
//         dll.push_front(key);
//         mp[key].first = dll.begin();
//     }

//     int get(int key) {
//         if(mp.find(key) != mp.end())
//         {
//             makeRecentlyUsed(key);
//             return mp[key].second;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(mp.find(key) != mp.end())
//         {
//             mp[key].second = value;
//             makeRecentlyUsed(key);
//         }
//         else
//         {
//             if(dll.size() == n)
//             {
//                 int k = dll.back();
//                 mp.erase(k);
//                 dll.pop_back();
//             }
//             dll.push_front(key);
//             mp[key] = {dll.begin(), value};
//         }
//     }
// };