#include <cstdio>

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int sz;

public:
    DoublyLinkedList() : head(nullptr), sz(0) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int size() const { return sz; }
    bool empty() const { return sz == 0; }

    void push_front(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        sz++;
    }

    void push_back(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = node;
        }
        ++sz;
    }

    void pop_front() {
        if (!head) {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
        sz--;
    }

    int front() const { return head->val; }

    void insert(int idx, int val) {
        if (idx <= 0) {
            push_front(val);
            return;
        }
        Node* cur = head;
        for (int i = 0; i < idx - 1 && cur; i++) {
            cur = cur->next;
        }
        if (!cur) {
            return;
        }
        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        ++sz;
    }

    void remove(int idx) {
        if (idx < 0 || !head) {
            return;
        }
        if (idx == 0) {
            pop_front();
            return;
        }
        Node* cur = head;
        for (int i = 0; i < idx - 1 && cur->next; i++) {
            cur = cur->next;
        }
        if (!cur->next) {
            return;
        }
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        --sz;
    }

    void print() const {
        Node* cur = head;
        while (cur) {
            printf("%d -> ", cur->val);
            cur = cur->next;
        }
        printf("null\n");
    }
};

int main() {
    DoublyLinkedList list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.print();  // 1 -> 2 -> 3 -> null

    list.push_front(0);
    list.print();  // 0 -> 1 -> 2 -> 3 -> null

    list.insert(2, 99);
    list.print();  // 0 -> 1 -> 99 -> 2 -> 3 -> null

    list.remove(2);
    list.print();  // 0 -> 1 -> 2 -> 3 -> null

    list.pop_front();
    list.print();  // 1 -> 2 -> 3 -> null

    printf("size: %d\n", list.size());
    return 0;
}
