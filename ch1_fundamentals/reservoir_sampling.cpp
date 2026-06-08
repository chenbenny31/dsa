#include <cstdlib>
#include <vector>

std::vector<int> reservoir_sample(const std::vector<int>& stream, int k) {
    std::vector<int> out(stream.begin(), stream.begin() + k);
    for (int i = k; i < static_cast<int>(stream.size()); i++) {
        int j = rand() % (i + 1);
        if (j < k) { out[j] = stream[i]; }
    }
    return out;
};
