class LRUCache {

private:

    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k , int v){
            key=k;
            value=v;
            next=nullptr;
            prev=nullptr;
        }
    };



    void addNode(Node* node){
        node->prev=head;
        node->next=head->next;
        node->next->prev=node;
        head->next=node;
    }

    void removeNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void moveToHead(Node* node){
        removeNode(node);
        addNode(node);
    }
     
     Node* popTail(){
        Node* lruNode=tail->prev;
        removeNode(lruNode);
        return lruNode;
     }

     unordered_map<int,Node*>mapp;
     int capacity;
     Node* head;
     Node* tail;

public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    
    int get(int key) {
        if(mapp.find(key)!=mapp.end()){
            Node* node=mapp[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            Node* node=mapp[key];
            node->value=value;
            moveToHead(node);
        }
        else{
            Node* node=new Node(key,value);
            mapp[key]=node;
            addNode(node);

            if(mapp.size()>capacity){
                Node* lru=popTail();
                mapp.erase(lru->key);
                delete lru;
            }

        }
    }
};
