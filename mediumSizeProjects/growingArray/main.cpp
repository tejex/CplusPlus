#include<iostream>
#include<string>
#include<cassert>

#include "dynamicArray.cpp"

using namespace std;

//Custom Dynamic Array project
//Pointers, dynamic memory, RAII, object lifetime, copy/move behaviour
//Going to do this without vector library. 

//For this I am thinking of is just using a standard array no vector
//and somehow working around / through that to make this work. 

//manage the array's memory
//support adding and removing an integer from the ends
//report size and capacity of th array
//grow when full / allocate more memory when its full


//my issue is that isn't the array that we use going to have a fixed size?
//how can we make it so that they can have dynamic sizes

//we can use a vector that does not have a fixed number / memory and instead allow the user to 
//dictate how large / how much memory should be allocated. something like this:
//vector<int> allocated(numbers)

int main(){

    DynamicArray array(2);

    assert(array.getSize() == 0);
    assert(array.getCapacit() == 2);

    array.add(20);
    array.add(30);
    array.add(40);

    assert(array.getSize() == 3);
    assert(array.getCapacit() >= 3);

    for(int expected = 40; expected >= 20; expected -= 10){
        int removed = array.remove();
        assert(removed == expected);
    }

    assert(array.getSize() == 0);
    // Removing from an empty array
    int emptyResult = array.remove();
    assert(emptyResult == 0);
    assert(array.getSize() == 0);

    // Reusing the array after emptying it
    array.add(99);
    assert(array.getSize() == 1);

    int removed = array.remove();
    assert(removed == 99);
    return 0;
}

