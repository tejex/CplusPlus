#include <iostream>
#include <string>
using namespace std;


void addOne(int *n){
    (*n)++;
    //Without the parentheses we would actually be moving the pointer instead of increasing the integer
    //So we get the address, go to it, then increase by 1
};

// void move(point * p){

//     p->x++;
// };

int add(int a , int b){

    int answer = a + b;
    return answer;
}

int subtract(int a, int b){

    return a - b;
}


int main(){
    
    int a = 3;
    int b = 5;
    float f = 4.5;
    double c = 5.34;
    double sum;

    // cout << "The sum of a, b, f and c is " << a + b + c + f << endl;

    int marks[5]  = {1,2,3,4,5};
    // //This is an array that contains 5 elements
    for(int i = 0; i < 2;i++){

    }
    
    char keys[] = {'b','c','d','f'};

    // cout << keys[0] << endl;

    string someText = "This is a new piece of text";

    // cout << "initial value of the text is " << someText << endl;

    // //What i think this is doing is, its taking the input from the user using (cin) then updating the variable / storing it in the variable
    // getline(cin, someText);

    // cout << "New value is " << someText <<endl;

    //for loops and while loops are basically similar to other languages. 
    //pointers is where it gets a little difficult

    int n = 5;

    void* p1;
    int* p2; 

    p1 = &n;
    p2 = (int*)p1; //since p1 is the one holding the address of the variable we want to modify and since
    // it is a void pointer, we need to type cast it to tell c++ what its type is, because we know it. 

    *p2 += 1; // This is incrementing the value at the address of where p1 is pointing at, which is n
    //By doing *p2, we basically have access to what n is storing right here, indirectly able to modify its value. 

    //so printing the value of n, or n itself, will now show the incremented value. 

    cout << n << endl;

    //Structures
    //basically a user defined type, kind of like classs. 

    struct Person{
        string name;
        int age;
        bool do_code;
    };

    Person x1;
    Person x2;

    x1.name = "bob";
    x1.age = 10000;
    x1.do_code = false;

    x2.name = "bam";
    x2.age = 22;
    x2.do_code = true;

    cout << x1.name << "(" << x1.age << ")\n";
    cout << x2.name << "(" << x2.age << ")";

    //*****************************************************************************************************************/
    //Function parameters passed by value are copied in and out of functions
    //Passing the parameter to the function as a pointer will enable us to use the pass by reference strategy
    //This will give us control of the variables, we can directly read / write to them and wont have to do this to copies.

    int num = 2;

    cout << "before adding " << num << endl;
    //Passing the address of num instead of the actual value copied. 
    //Allowing the function to directly edit the value of the  variable in memory
    addOne(&num);

    cout << "after adding " << num << endl;


    //Dynamic Allocation ******************************************************************************* //
    //In C++, memory can be allocated at runtime using the new operator. This is known as dynamic allocation. 
    //Doing this lets us create new memory from the heap and returns a pointer to the new piece of memory we created. 
    //This is useful when we dont know the size of the data structure until the program is run. eg linked lists and trees

    int *p = new int; // allocate one int on the heap

    *p = 42; //store a value through the pointer. (at this address, put the number 42)

    printf("%\n", *p);  //read it back.

    delete p;
    p = nullptr;

    //Function Pointers ******************************************************************************* //
    //Just like we can point to a variable with a pointer, we can also point to a function, a function pointer 
    // stores the address of a function, letting us call that function through the pointer. This is very useful 
    //For passing a function as an argument to another funtion, such as a sort function that accepts a custom comparison, 
    // or a map-style helper that applies a function to every element, 

    //Syntax -> int (*operation) (int , int);


    int (*operation)(int, int);
    operation = add;

    printf("%d\n", operation(5,5));


    //Function pointers and Arrays
    //An array of function pointers lets us select behavior by an index, we can call different functions
    //via accessing different indexes. 

    int (*operations[2])(int, int); // creating a array that can store address of 2 functions

    operations[0] = add;
    operations[1] = subtract;

    printf("%d\n", operations[0](5,5));
    printf("%d\n", operations[1](9,5)); // we are calling the functions through the pointers in the array.

    //very useful when there are several possible actions with the same inputs and outputs
    //same paramters and same return values

    // index -> behavior

    return 0;
}