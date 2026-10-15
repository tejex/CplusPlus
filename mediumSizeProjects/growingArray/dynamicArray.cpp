
#include<iostream>
#include<string>

using namespace std;

class DynamicArray{
    private:
        int capacity;
        int size;
        int *array;

    public:
        ~DynamicArray() {
            delete[] this->array;
        }
        DynamicArray(int capacity){
            this->capacity = capacity;
            this->size = 0;
            this->array = new int[capacity];

            //makes sense, we have a pointer pointing to nothing up top in the private section
            //when we have a value for capacit we simply point that pointer to a new array
            //we instantiate with the newly acquired capacity value
            
        }

        int getSize(){
            return this->size;
        }

        int getCapacit(){
            return this->capacity;
        }

        int remove(){
            if(this->size == 0){
                return 0;
            }
            //raw array does not have a pop_back method, we will implement this.
            int lastElement = this->array[this->size - 1];
            //maybe we can have a pointer point to the last element of the array. 
            //then we can just delete it that way after retrieving the value


            //Doing this in a sense removes the last element because when a new
            //one is added it simply replaces the old value because move size down one. 
            this->size -= 1;
            
            return lastElement;
        }
        int add(int item){

            //first we need to check if the array is full and if it is
            //we call the resize method on it

            if(this->capacity == this->size){
                //this means its full
                cout << "Array is full" << endl;
                this->resizeArray();
            }


            //to add an item we need to know the position of the last item
            //in the array that has been added, + 1. Basically the last free
            //spot.
            this->array[this->size] = item;

            //we can probably have a pointer point at array[0] to start
            //then as we add we can move this up to array[1] array[2] and so on. 
            //this will give us the next free spot.
            //when we remove an item we should also move this down back to array[1] and so on..

            this->size += 1;

            //instead of a pointer with the aaddress we can just keep track of the index

            return 0;
        }

        int resizeArray(){
            //Resize the array..

            //Basically double its capacity
            //copy all the elements over
            //Delete the old array

            this->capacity *= 2;
            int *newArr = new int[this->capacity];

            for(int i=0;i < this->size;i++){
                newArr[i] = this->array[i];
            }
            //copy over all elements into the new array and then 
            //we need to delete the old array and set newArr as the array
            //we want it to be.

            delete[] this->array; //deleting whats at the pointer before reassigning. 
            this->array = newArr; //does this make sure the old one is deleted?

            return 0;
        }
    
};