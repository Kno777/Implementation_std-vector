#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> vec{12,34,56,78};
    Vector<int>::iterator it;
    
    for(it = vec.begin();  it !=  vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
}