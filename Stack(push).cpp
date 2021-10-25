#include <iostream>

class Stack                                                                     
{                                                                               
public:                                                                         
    Stack();   /* constructor */                                            
    ~Stack();  /* destructor */                                             
                                                                                
    void push(int elem);  /* method */                                      
private:                                                                        
    int* content; /* fields */                                              
    int size;                                                               
    int capacity;                                                           
}; 

Stack::Stack()
{                                                                               
    this->content = new int[32];                                            
    this->size = 0;
    this->capacity = 32;                                                    
}                                                                               
                                                                                
Stack::~Stack()                                                                 
{                                                                               
    delete this->content;                                                   
}   

void Stack::push(int elem)
{                                                                               
    if (size >= capacity) {
       int* content2 = new int[32];
        for (int i=0; i<32; i++){
            content2[i]=content[i];
            }
        capacity = capacity*2;
        content = new int[capacity]; 
        for (int i=0; i<32; i++){
            content[i]=content2[i];
            }
        content[size] = elem;
        size++;
    }
    else {
        content[size] = elem;
        size++;
    }
}                                                                               
                                                                                
int main()                                                                      
{                                                                               
    Stack st;                                                               
    st.push(1);                                                             
    st.push(2);                                                             
    return 0;                                                               
} 
