#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>


using namespace std;

//what does this file need to do?
//define functions that will execute the log reading features
//with however many threads 

//now the question becomes, how can we do this? how will this be designed?
//we have three log files, so, what a thread for each file? how can 3-4 threads work in one file? what if 1 already
//finishes reading the work in the file, how do they split it up

//need these questions answered before moving on. 

int countAllLines(){
    //open file -> call this method
    return 0;
}
namespace fs = std::filesystem;
void countCategories(const fs::path& filePath) {
    //open file -> call this method.
    //reason i am returning a vector of vectors here is because I want to group the categories by count
    //first one will be for errors, second for Info and thirs for Warnings

    vector<int> errorCount = {0};
    vector<int> infoCount = {0};
    vector<int> warningCount = {0};
    vector<int> unknown = {0};

    //First we check if the directory exists and we check if it is actually a directory
    //then when these pass do we go on and start looping through. 

    ifstream input(filePath);
    string stringInput{};

    vector<string> fileLines;

    while(getline(input, stringInput)){
        fileLines.push_back(stringInput);
    }

    //Since this is a parallel processing style algorithm
    //will need to figure out how to do the following:
    // - create multiple threads & run them on each file, or create multiple threads and start them all together.
    // - will be back, gonna study how this works and will implement the solution here.

    for(string line : fileLines){
        cout << line << endl;
    }


    return;
}

