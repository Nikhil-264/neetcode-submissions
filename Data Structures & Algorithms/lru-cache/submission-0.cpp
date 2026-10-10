class Node {
public:
    int key, val;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};
class DLL {
public:
    Node* head;
    Node* tail;

    DLL(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node){
        Node * currHeadNext = head->next;
        head->next = node;
        node->prev = head;
        currHeadNext->prev = node;
        node->next = currHeadNext;
    }

    void deleteNode(Node* node){
        Node* NodePrev = node->prev;
        Node* NodeNext = node->next;
        NodePrev->next = NodeNext;
        NodeNext->prev = NodePrev;
    }

    void deleteBeforeTail(){
        Node* nodeBeforeTail = tail->prev;
        Node* nodeBB = tail->prev->prev;
        nodeBB->next = tail;
        tail->prev = nodeBB;
        delete nodeBeforeTail;
    }
};

class LRUCache {
    map<int, Node*> mpp;
    int capacity; 
    DLL dll;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        dll.head->next = dll.tail;
        dll.tail->prev = dll.head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        dll.deleteNode(node);
        dll.insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            dll.deleteNode(node);
            dll.insertAfterHead(node);
        }
        else{
            if(mpp.size() == capacity){
                Node* node = dll.tail->prev;
                mpp.erase(node->key);
                dll.deleteBeforeTail();
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            dll.insertAfterHead(node);
        }
    }
};