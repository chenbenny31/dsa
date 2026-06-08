#include <list>
#include <unordered_map>

struct LFUCache {
    int cap, min_freq = 0;
    struct Entry {
        int val, freq;
        std::list<int>::iterator it;
    };
    std::unordered_map<int, Entry> key_map; // key -> {val, freq, iter}
    std::unordered_map<int, std::list<int>> freq_map; // freq -> keys (front = MRU)

    explicit LFUCache(int cap) : cap(cap) {}

    void touch(int key) {
        int f = key_map[key].freq;
        freq_map[f].erase(key_map[key].it);
        if (freq_map[f].empty()) {
            freq_map.erase(f);
            if (min_freq == f) { min_freq++; }
        }
        key_map[key].freq++;
        freq_map[f + 1].push_front(key);
        key_map[key].it = freq_map[f + 1].begin();
    }

    int get(int key) {
        if (!key_map.count(key)) { return -1; }
        touch(key);
        return key_map[key].val;
    }

    void put(int key, int val) {
        if (!cap) { return; }
        if (key_map.count(key)) {
            touch(key);
            key_map[key].val = val;
            return;
        }
        if (static_cast<int>(key_map.size()) == cap) {
            int evict = freq_map[min_freq].back();
            freq_map[min_freq].pop_back();
            if (freq_map[min_freq].empty()) { freq_map.erase(min_freq); }
            key_map.erase(evict);
        }
        min_freq = 1;
        freq_map[1].push_front(key);
        key_map[key] = {val, 1, freq_map[1].begin()};
    }
};
