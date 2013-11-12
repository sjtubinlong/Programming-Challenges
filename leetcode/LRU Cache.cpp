class LRUCache{
public:
    struct KVPair{
        int key;
        int value;
        KVPair( int k, int v ):key(k),value(v){};
    };
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if( dict_.find(key) == dict_.end() ){
            return -1;
        }
        unordered_map< int, list<KVPair>::iterator >::iterator iter = dict_.find(key);
        if( iter == dict_.end() ){
            //ERROR OCCURED
            return -2;
        }
        KVPair cur = *(iter->second);
        list_.erase( iter->second );
        list_.push_front( cur );
        dict_[key] = list_.begin();
        return cur.value;
    }
    
    void set(int key, int value) {
        unordered_map< int, list<KVPair>::iterator >::iterator iter = dict_.find(key);
        if( iter==dict_.end() ){
            if( dict_.size() >= capacity_ ){
                dict_.erase( list_.back().key );
                list_.pop_back();
            }
        }else list_.erase( iter->second );
        KVPair cur( key, value );
        list_.push_front(cur);
        dict_[key] = list_.begin();
    }
private:
    int capacity_;
    list< KVPair > list_;
    unordered_map< int, list<KVPair>::iterator > dict_;
};