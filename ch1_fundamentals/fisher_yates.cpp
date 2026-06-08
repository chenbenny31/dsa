#include <algorithm>
#include <cstdlib> // rand
#include <vector>

void fisher_yates(std::vector<int>& arr) {
    for (int i = static_cast<int>(arr.size()) - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        std::swap(arr[i], arr[j]);
    }
}
