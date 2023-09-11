#include "Exceptions.h"

template <class T>
class DynamicArray{
    //size is the actual size of the dynamic array
    //while length is the length/number of elements
    //that are stored in the array
    private:
        int size{1};
        int length{0};
        T *first_element;

        //Helper functions
        T *Resize_Array(bool increase_size){                
            if(increase_size){
               size *= 2;                
            }else{
                size /= 2;
            }
            T *resized_array = (T*) malloc(sizeof(T) * size);

            //transfering old values into new array
            for(int i = 0;i < length;i++){
                *(resized_array + i) = *(first_element + i);
            }
            

            //freeing old array memory
            free(first_element);        
            return resized_array;
        }
        void shift_array(int index, bool shift_right){
            if(length == size/2){
                first_element = Resize_Array(false);
            }

            if(shift_right){
                for(int i = length; i > index;i--){
                    *(first_element + i) = *(first_element + i - 1);
                }
            }else{
                for(int i = index; i < length + 1;i++){
                    *(first_element + i) = *(first_element + i + 1);
                }
            }

            
        }

    public:
        DynamicArray(int size){       
            if(size == 0){
                size = 1;
            }     
            this->size = size * 2;
            //initializing the dynamic array with twice 
            //the requested size
            first_element = (T*) malloc(sizeof(T) * size);
        }
        ~DynamicArray(){
            free(first_element); first_element = nullptr;
        }

        T get_item(int index){
            if(index >= length || index < 0){
                free(first_element);
                throw IndexOutOfBoundException();
            }
            return *(first_element + index);
        }

        void add(T item){
            if(length == size){
                first_element = Resize_Array(true);
            }
            *(first_element + length) = item;
            length++;
        }

        void insert(T item, int index){
            if(length == size){
                first_element = Resize_Array(true);
            }       
            //shifts the array to the right
            shift_array(index, true);
            *(first_element + index) = item;
            length++;
        }

        T remove(int index){
            if(index >= length || index < 0){
                free(first_element);
                throw IndexOutOfBoundException();
            }
            //saves the deleted item
            T item_to_remove = *(first_element + index);
            //shifts the array to the left            
            shift_array(index, false);
            length--;
            //ensures that the size never gets to 0
            if(length == size/2 && size > 1){
                first_element = Resize_Array(false);
            }

            return item_to_remove;
        }

        void clear(){
            length = 0;
        }

        int len(){
            return length;
        }
        int s(){
            return size;
        }
    
};
