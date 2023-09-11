#include "Exceptions.h"

template <class T>
class StaticArray{
    private:
        int size;
        T *first_element;
    public:
        const int &length = size;

        StaticArray(int size){  
            this->size = size;          
            first_element = (T*) malloc(sizeof(T) * size);
        }

        T get_item(int index){
            if(index >= size || index < 0){
                throw IndexOutOfBoundException();
            }
            return *(first_element + index);
        }
        void set_item(T value, int index){
            if(index >= size || index < 0){
                throw IndexOutOfBoundException();
            }
            *(first_element + index) = value;
        }
};