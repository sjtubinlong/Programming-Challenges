//data-structure application: hash-table, double linked list
class LRUCache{
public:
    class Node {
    public:
        int key;
        int value;
        Node(int k, int v): key(k), value(v) {}
    };
    
    int _capacity;
    list<Node> _list;
    map<int, list<Node>::iterator> _data;
    
    LRUCache(int capacity):  _capacity(capacity) {}
    
    int get(int key) {
        if(_data.find(key) == _data.end()) return -1;
        list<Node>::iterator it = _data[key];
        if(it != _list.begin()){
            _list.erase(it);
            _list.push_front(*it);
            _data[key] = _list.begin();
        }
        return it->value;
    }
    
    void set(int key, int value) {
        if(_data.find(key) != _data.end()) {
            list<Node>::iterator it = _data[key];
            _list.erase(it);
            it->value = value;
            _list.push_front(*it);
            _data[key] = _list.begin();
        }else{
            if(_data.size() >= _capacity){
                _data.erase(_list.back().key);
                _list.pop_back();
            }
            _list.push_front(Node(key, value));
            _data[key] = _list.begin();
        }
    }
};

