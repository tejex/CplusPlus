// #ifndef ADD_H
// #define ADD_H

// int add(int x, int y);

// #endif

//The above works but thats it.

#pragma

int add(int x, int y);

//This will prevent duplicate definitions being made into whatever file needs this function

//for example, if file A wants to use add but its also a header file, and main.cpp 
//wants to use add, if both import it and we import file A into main.cpp
//this will cause a duplicate definition error in cpp. 

//Using the conditional compilation tactics covered in previous chapters.

//Just finding out you can use something called a #pragma
// this is fairly common in modern c++ and we can replace the
//conditional compilation we have up top with a single #pragma definition
