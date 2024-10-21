  void push(int x) {
        
        StackNode*temp=top;
        StackNode*node=new StackNode( x);
       
        node->next=temp;
        top=node;
        
        // code here
    }

    int pop() {
        // code here
         
        StackNode*temp=top;
        if(temp==NULL)
        {
            return -1;
        }
        else
        {
           top=temp->next;
            return temp->data;
        }
        
        
    }
