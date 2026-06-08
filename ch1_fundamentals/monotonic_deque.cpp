#include <deque>
#include <vector>

// front of deque = index of current window maximum
std::vector<int> sliding_window_max(const std::vector<int>& arr, int k) {
    int n = static_cast<int>(arr.size());
    std::vector<int> out;
    std::deque<int> dq; // indices
    out.reserve(n - k + 1);
    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) { dq.pop_front(); }
        while (!dq.empty() && arr[dq.back()] <= arr[i]) { dq.pop_back(); }
        dq.push_back(i);
        if (i >= k - 1) { out.push_back(arr[dq.front()]); }
    }
    return out;
};
