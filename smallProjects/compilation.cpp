#include <iostream>
#include <vector>
#define PRINT_JOE


int main(){

    #ifdef PRINT_JOE
        std::cout << "Joe\n"; // If we tried to do something like std::cout << PRINT_JOE << endl; -> We will get a compilation error
    #endif

    #ifdef PRINT_ROB
        std::cout << "Rob"; //C++ already is dimming this because the identifier has not been defined. 
    #endif

    #if 0
        std::cout << "HELLO";
    #endif

    #if 1 //This temporarily enables the code to be eligible / runnable / compilable by the compiler. 
        std::cout << "j"; 
    #endif



    return 0;
}