class LRUCache {
private:
    int capacity;
    int length;
    int clock;
    map<int, pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->length = 0;
        this->clock = 0;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        } else {
            cache[key] = {clock++, cache[key].second};
            return cache[key].second;
        }
    }
    
    //当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            cache[key] = {clock++, value};
        }
        else if(this->length >= this->capacity) {
            //寻找最小clock的map元素
            int min = 0x3F3F3F3F;
            map<int, pair<int,int>>::iterator min_iter;
            for(map<int, pair<int,int>>::iterator iter = cache.begin(); iter != cache.end(); ++iter) {
                if((*iter).second.first < min) {
                    //cout << (*iter).second.first << ":" << (*iter).second.second  << endl;
                    min = (*iter).second.first;
                    min_iter = iter;
                }
            }
            //erase此元素
            cache.erase(min_iter);
            //添加key = {clock, value}
            cache[key] = {clock++, value};
            
        } else {
            cache[key] = {clock++,value};
            this->length++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */