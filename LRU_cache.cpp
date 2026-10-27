class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node() {
        key = val = -1;
        next = prev = NULL;
    }

    Node(int k, int value) {
        key = k;
        val = value;
        next = prev = NULL;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> mpp;
    int cap;
    Node* head;
    Node* tail;

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        nextNode->prev = node;
        node->prev = head;
        node->next = nextNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key_) {
        if (mpp.find(key_) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key_];
        int value = node->val;

        deleteNode(node);
        insertAfterHead(node);

        return value;
    }

    void put(int key_, int value) {
        if (mpp.find(key_) != mpp.end()) {
            Node* node = mpp[key_];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if (mpp.size() == cap) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
            delete node;
        }

        Node* newNode = new Node(key_, value);
        mpp[key_] = newNode;
        insertAfterHead(newNode);
    }
};
