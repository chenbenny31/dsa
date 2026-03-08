#include <cstdio>
#include <cstdlib>
#include <cassert>

using std::malloc;
using std::free;

class SinglyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
    };

    Node* head;
    int len;

    Node* make_node(int val, Node* next) {
        Node* node = static_cast<Node*>(malloc(sizeof(Node)));
        node->val = val;
        node->next = next;
        return node;
    }

public:
    SinglyLinkedList(): head(nullptr), len(0) {}

    ~SinglyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            free(cur);
            cur = next;
        }
    }

    int size() const { return len; }
    bool empty() const { return len == 0; }

    int front() const {
        assert(head);
        return head->val;
    }

    void push_front(int val) {
        head = make_node(val, head);
        ++len;
    }

    void pop_front() {
        assert(head);
        Node* old_head = head;
        head = head->next;
        free(old_head);
        --len;
    }

    void insert_after(int idx, int val) {
        assert(idx >=0 && idx < len);
        Node* cur = head;
        for (int i = 0; i < idx; i++) {
            cur = cur->next;
        }
        cur->next = make_node(val, cur->next);
        ++len;
    }

    void remove_after(int idx) {
        assert(idx >=0 && idx < len);
        Node* cur = head;
        for (int i = 0; i < idx; i++) {
            cur = cur->next;
        }
        Node* target = cur->next;
        cur->next = target->next;
        free(target);
        --len;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }

    void print() const {
        for (const Node* cur = head; cur; cur = cur->next) {
            printf("%d -> ", cur->val);
        }
        printf("null\n");
    }
};

int main() {
    SinglyLinkedList list;
    assert(list.empty());

    for (int i = 4; i >= 0; i--) {
        list.push_front(i);
    }
    assert(list.size() == 5);
    assert(list.front() == 0);
    list.print();

    list.insert_after(2, 99);
    list.print();

    list.remove_after(2);
    list.print();

    list.pop_front();
    assert(list.front() == 1);
    list.print();

    list.reverse();
    assert(list.front() == 4);
    list.print();

    printf("all tests passed\n");
    return 0;
}
