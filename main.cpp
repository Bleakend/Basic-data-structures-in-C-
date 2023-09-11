#include <iostream>
#include "StaticArray.h"
#include "DynamicArray.h"

class int_container{
    private:
        int i;
    public:        
        int_container(int i){
            this->i = i;
        }
        int get_i(){
            return i;
        }

};

int  main(){
    // StaticArray<int_container> container_list(5);

    // for(size_t i = 0;i < 5;i++){        
    //     container_list.set_item(int_container(i), i);
    // }

    // for(size_t i = 0;i < 5;i++){        
    //     std::cout << container_list.get_item(i).get_i() << std::endl;
    // }

    DynamicArray<int> list(2);

    for(int i = 0;i < 4;i++){
        list.add(i);        
    }
    std::cout << "array size: "<< list.s() << std::endl;
    list.remove(3);
    list.remove(2);
    std::cout << "array size: " << list.s() << std::endl;
    list.add(2);
    list.add(5);
    list.add(67);
    std::cout << "array size: " << list.s() << std::endl;

    for(int i = 0;i < list.len();i++){
        std::cout << list.get_item(i) << std::endl;
    }    
}