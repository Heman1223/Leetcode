class MyLinkedList { 
private:
    struct Node{
        int val;
        Node* next;
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
    };
    Node* head;
    int size;
public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        Node* curr = head;
        for(int i=0;i<index;++i){
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
        }else{
            Node* curr = head;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        Node* newNode = new Node(val);
        for (int i = 0; i < index - 1; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        Node* toDelete;
        if(index ==  0){
            toDelete = head;
            head = head->next;
        }else{
            Node* curr = head;
            for(int i=0;i< index - 1;i++){
                curr = curr->next;
            }
            toDelete = curr->next;
            curr->next = toDelete->next;
        }
        delete toDelete;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */