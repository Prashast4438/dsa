void MyQueue:: push(int x)
{
        // Your Code
        if(front==NULL&&rear==NULL)
        {
            front=new QueueNode(x);
            rear=front;
        }
        else
        {
        QueueNode *temp=new QueueNode(x);
        rear->next=temp;
        rear=temp;
        }
   
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code 
        if(front==NULL&&rear==NULL)
        {
            return -1;
        }
       
            
        else
        {
         QueueNode *temp=front;
         front=temp->next;
          if (front == NULL) 
          {
           rear = NULL;
          }
    
         return temp->data;
        }
        
}
