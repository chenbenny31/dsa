#include <list>
#include <unordered_map>

struct LRUCache {
    int cap;
    std::list<std::pair<int, int>> lst; // {key, val}, front = MRU
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> mp;

    explicit LRUCache(int cap) : cap(cap) {}

    int get(int key) {
        if (!mp.count(key)) { return -1; }
        lst.splice(lst.begin(), lst, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int val) {
        if (mp.count(key)) {
            map[key]->second = val;
            lst.splice(lst.begin(), lst, mp[key]); // splice(dst, src, iter-to-elem)
            return;
        }
        if (static_cast<int>(mp.size()) == cap) {
            mp.erase(lst.back().first);
            lst.pop_back();
        }
        lst.push_front({key, val});
        mp[key] = lst.begin();
    }
};

// splice over erase + push_front: 3 pointer rewires vs de-allocate + re-allocate introducing overhead
//   splice(pos, other): move entire other list before pos
//   splice(pos, other, it): move single elemet at it before pos
//   splice(pos, other, first, last): move range [first, last) before pos
