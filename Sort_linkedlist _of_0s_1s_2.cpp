
//not optimal 
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        vector<int> p;
        Node* temp=head;
        while(temp!=NULL)
        {
            p.push_back(temp->data);
            temp=temp->next;
            
    }
    
    sort(p.begin(),p.end());
    temp=head;
    for(int i=0;i<p.size();i++)
    {
      temp->data=p[i];
      temp=temp->next;
    }
    
    return head;
    }
};
