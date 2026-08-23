class LRUCache {
public:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    unordered_map<int, Node*> mp;

    Node* head; // Most recently used
    Node* tail; // Least recently used

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    // Remove node from its current position
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Add node just after head
    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // It was recently used
        remove(node);
        addFront(node);

        return node->value;
    }

    void put(int key, int value) {

        // Already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            remove(node);
            addFront(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        mp[key] = node;
        addFront(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};