class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* node = head;
        while(node!=nullptr){
            Node* prev = nullptr;
            for(size_t id=0; id<m && node!=nullptr; id++){
                prev = node;
                node = node->next;
            }
            for(size_t id=0; id<n && node!=nullptr; id++){
                Node* temp = node;
                node = node->next;
                delete temp;
            }
            prev->next = node;
        }
        return head;
    }
};