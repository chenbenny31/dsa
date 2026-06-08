template<typename T>
struct Queue {
    struct Node { T val; Node* next = nullptr; }
    Node* head = nullptr;
    Node* tail = nullptr;

    void enqueue(T v) {
        Node* node = new Node{std::move(v)};
        if (!tail) { head = tail = node; return; }
        tail->next = node;
        tail = node;
    }

    T dequeue() {
        T v = std::move(head->val);
        Node* old = head;
        head = head->next;
        if (!head) { tail = nullptr; }
        delete old;
        return v;
    }

    bool empty() { return !head; }
}
