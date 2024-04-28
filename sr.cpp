#include<iostream>
using namespace std;
int s=0;
int sum(int n)

{
if(n<1)
    {
        return 0;
    }
        else 
       //s= s+n;
        //n--;
        //sum(n);
        //above is same as this 
        s= n+sum(n-1);

        return s;
        
}
    int main ()
    {
        int n;
        cout<<"enter till u want sum"<<endl;
        cin>>n;
        
        int result= sum(n);
        cout<<"the result is "<<result;
        return 0;
    }

