#include <vector>

template<typename T>
struct Stack {
    std::vector<T> data;
    void push(T v) { data.push_back(std::move(v)); }
    T pop() { T v = std::move(data.back()); data.pop_back(); return v; }
    T& top() { return data.back(); }
    bool empty() { return data.empty(); }
};
