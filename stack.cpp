
#include "stack.h"



// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c ) 
{
   if( current_capacity < c )
   {
      // New capacity will be the greater of c and
      // 2 * current_capacity. 

      if( c < 2 * current_capacity )
         c = 2 * current_capacity;

      double* newdata = new double[ c ];
      for( size_t i = 0; i < current_size; ++ i )
         newdata[i] = data[i];

      current_capacity = c;
      delete[] data;
      data = newdata;
   }
}

stack:: stack(){
    current_size = 0;
    data = new double[5];
    current_capacity = 5;
}

stack::stack( const stack& s):
current_capacity(s.size()),
current_size(s.size()),
data(new double[s.size()]){
    for(int i=0;i<s.size();i++){
        data[i] = s.data[i];
    }
}

stack::stack (std::initializer_list<double> init):
current_capacity(init.size()),
current_size(init.size()),
data(new double[init.size()]){
    int i=0;
    for(double x: init){
        data[i] = x;
        i++;
    }
    
}

stack::~stack(){
    delete[] data;
}

const stack& stack::operator = (const stack& s){
    ensure_capacity(s.size());
    for(int i=0;i<s.current_size;i++){
        data[i] = s.data[i];
    }
    
    return *this;
}

void stack::push(double d){
    ensure_capacity(current_size+1);
    data[current_size] = d;
    current_size++;
}

void stack::pop(){
    if(current_size == 0){
        throw std::runtime_error("pop: stack is already empty!");
    }
    current_size--;
}

void stack::clear(){
    current_size = 0;
}

void stack::reset(size_t s){
    if(s<current_size){
        current_size = s;
    }
}

double stack::peek() const{
    if(current_size == 0) throw std::runtime_error("peek: stack is empty!");
    else return data[current_size-1];
}

size_t stack::size() const{
    return current_size;
}

bool stack::empty() const{
    return current_size == 0;
}

std::ostream& operator << ( std::ostream& out, const stack& s){
    for(int i=0;i<s.current_size;i++){
        out<<s.data[i]<<" ";
    }
    return out;
}
    


    




 
