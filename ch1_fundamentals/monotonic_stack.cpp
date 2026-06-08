#include <vector>

// increasing stack (top = min): pop when top < cur -> next greater
// decreasing stack (top = max): pop when top > cur -> next smaller
std::vector<int> next_greater(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    std::vector<int> out(n, -1);
    std::vector<int> stk;
    stk.reserve(n);
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.back()] < arr[i]) {
            out[stk.back()] = arr[i];
            stk.pop_back();
        }
        stk.push_back(i);
    }
    return out;
}
