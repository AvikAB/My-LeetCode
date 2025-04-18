class Router {
private:
    struct Packet {
        int src, dst, time;
        bool operator==(const Packet& other) const {
            return src == other.src && dst == other.dst && time == other.time;
        }
    };

    struct Hash {
        size_t operator()(const Packet& p) const {
            return ((hash<int>()(p.src) * 31 + hash<int>()(p.dst)) * 31) ^ hash<int>()(p.time);
        }
    };

    int limit;
    queue<Packet> q;
    unordered_set<Packet, Hash> seen;
    unordered_map<int, vector<int>> timeMap;
    unordered_map<int, int> startIndex;

public:
    Router(int memoryLimit){
        limit = memoryLimit;
    }
    bool addPacket(int src, int dst, int time) {
        Packet p{src, dst, time};
        if (seen.count(p)) return false;
        if ((int)q.size() == limit) {
            Packet old = q.front(); 
            q.pop();
            seen.erase(old);
            startIndex[old.dst]++;
            if(startIndex[old.dst] == (int)timeMap[old.dst].size()){
                timeMap.erase(old.dst);
                startIndex.erase(old.dst);
            }
        }
        q.push(p);
        seen.insert(p);
        timeMap[dst].push_back(time);
        if (!startIndex.count(dst)) startIndex[dst] = 0;
        return true;
    }

    vector<int> forwardPacket(){
        if (q.empty()) return {};
        Packet p = q.front(); 
        q.pop();
        seen.erase(p);
        startIndex[p.dst]++;
        if (startIndex[p.dst] == (int)timeMap[p.dst].size()){
            timeMap.erase(p.dst);
            startIndex.erase(p.dst);
        }
        return {p.src, p.dst, p.time};
    }
    int getCount(int dst, int start, int end){
        if (!timeMap.count(dst)) return 0;
        const vector<int>& times = timeMap[dst];
        int idx = startIndex[dst];
        auto it = lower_bound(times.begin() + idx, times.end(), start);
        auto it1 = upper_bound(times.begin() + idx, times.end(), end);
        return abs(it-it1);
    }
};
