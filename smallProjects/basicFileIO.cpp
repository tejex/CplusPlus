#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//There are 3 basic file I/O classes in C++
// - ifstream (derived from istream) - ofstream (derived from ostream) and fstream (derived from iostream)

//unlike cout, cin and cerr, which are already ready for use, file streams have to be explicitly set up by the programmer
// this is extremely simple. to open a file for reading or wrting, simply instantiate an object 
// of the appropriate file io class, with the name of the file as a parameter. 

// Then use the insertion >> or the extraction << operatr to write to or read data from the file. 

//Once you are done, there are several ways to close a file, the close() function or we can let the file i/o variable
// go out of scope, the file I/O class destructor will close the file for us.

int main(){

    //File output
    //To do this, we will use the ofstream class. 
    //ofstream is used for writing files. 

    ofstream outF{"activity.txt"};

    if(!outF){
        cerr << "activity.log cant be openend to be written on" << endl;
        return 1;
    }

    outF << "This is line 1\n"; 
    outF << "This is line 2\n";
    //this is how we write to the text file, using ofstream

    outF.close();

    //File input
    //Now we will take the file we wrote in the last example and read it back in from disk. 
    //Remember that if ifstream returns 0, we have reached the end of the file. 
    
    ifstream inF{"activity.txt"};

    if(!inF){
        cerr << "Uh oh, Sample.txt could not be opened for reading! ";
    }

    string strInput{};

    while(getline(inF, strInput)){
        cout << strInput << '\n';
        //We can do the above to see what is printed on the file we just wrote to, but in order 
        //to read them in a line by line basis, we can use the getline() method provided by the string library.
    }

    //Buffered output
    //This basically means that anythig that is output to a filestream may not be written to disk immediately. 
    //Instead several output operations are batched and handled together. This is done mainly for performance

    //Explicitly opening files using open()
    //Just like it is possible to explicitly close a file stream using close(), its also possible to explicitly open a file 
    //stream using open(), open() works just like the file stream constructors -- it takes a file name and optional file mode. 

    ofstream outputF{"activity.txt"};
    outputF << "This is line 1";
    outputF << "This is line bambro 2";
    outputF.close();

    outputF.open("activity.txt", ios::app); 
    //ios::app means append mode, without this it just clears the file out and then whatever you write
    //will get appended into the new file. 

    outputF << "This is line 3\n";

    outputF.close(); //Need to close the file, or it will close when it goes out of scope. 


    return 0;
}