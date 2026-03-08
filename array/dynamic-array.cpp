#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using std::malloc;
using std::free;
using std::memcpy;

class DynamicArray {
private:
    int* data;
    int len;
    int cap;

    void resize(int new_cap) {
        int* new_data = static_cast<int*>(malloc(new_cap * sizeof(int)));
        memcpy(new_data, data, len * sizeof(int));
        free(data);
        data = new_data;
        cap = new_cap;
    }

public:
    DynamicArray() : data(static_cast<int*>(malloc(sizeof(int)))), len(0), cap(1) {}
    ~DynamicArray() { free(data); }

    int size() const { return len; }
    bool empty() const { return len == 0; }
    auto ssize() const { return static_cast<std::ptrdiff_t>(len); }

    void push_back(int val) {
        if (len == cap) { resize(cap * 2); }
        data[len++] = val;
    }

    void pop_back() {
        assert(len > 0);
        --len;
        if (len > 0 && len == cap / 4) {
            resize(cap / 2);
        }
    }

    int& operator[](int i) { return data[i]; }
    const int& operator[](int i) const { return data[i]; }

    int* begin() { return data; }
    int* end() { return data + len; }
    const int* begin() const { return data; }
    const int* end() const { return data + len; }
};

int main() {
    DynamicArray arr;
    assert(arr.empty());

    for (int i = 0; i < 20; i++) {
        arr.push_back(i);
    }
    assert(arr.size() == 20);
    assert(arr[10] == 10);

    arr[5] = 999;
    assert(arr[5] == 999);

    for (int i = 0; i < 15; i++) {
        arr.pop_back();
    }
    assert(arr.size() == 5);

    printf("remaining:");
    for (const auto& x : arr) {
        printf(" %d", x);
    }
    printf("\n");

    printf("all tests passed\n");
    return 0;
}
