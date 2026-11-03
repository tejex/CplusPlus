#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
#include<sstream>
#include <mutex>

using namespace std;

//what does this file need to do?
//define functions that will execute the log reading features
//with however many threads 

//now the question becomes, how can we do this? how will this be designed?
//we have three log files, so, what a thread for each file? how can 3-4 threads work in one file? what if 1 already
//finishes reading the work in the file, how do they split it up

//need these questions answered before moving on. 

int allErrors = 0, allInfo = 0, allWarn = 0, allDebug = 0;

mutex countsMutex;
mutex outputMutex;


namespace fs = std::filesystem;
void countCategories(const fs::path& filePath) {
    //open file -> call this method.
    //reason i am returning a vector of vectors here is because I want to group the categories by count
    //first one will be for errors, second for Info and thirs for Warnings

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

    int errorCount = 0;
    int warnCount = 0;
    int infoCount = 0;
    int debugCount = 0;


    for(string line : fileLines){
        istringstream parser {line};
        string status;
        getline(parser,status,'[');
        getline(parser, status, ']');
        if(status == "INFO"){
            infoCount += 1;
        }
        else if(status == "ERROR"){
            errorCount += 1;
        }
        else if(status == "WARN"){
            warnCount += 1;
        }
        else if(status == "DEBUG"){
            debugCount += 1;
        }
    }
    //locking so only one thread can manipulate the global count at a tim
    {
        lock_guard<mutex> lock(countsMutex);
        allErrors += errorCount;
        allInfo += infoCount;
        allWarn += warnCount;
        allDebug += debugCount;

    }

    //Ahh we have multiple threads writing to this so the counts are off, maybe we need to lock
    //the global ones and only allow one thread to write it at a time 


    //locking so only 1 thread can print out the info. 
    {
        lock_guard<mutex> lock(outputMutex);
        cout << "Error count for file-> " << filePath << " | count = " << errorCount<< endl;
        // cout << "Info count " << infoCount << " global info count " << allInfo << endl;
        // cout << "Warn count " << warnCount << " global warn count " << allWarn << endl;
        // cout << "Debug count " << debugCount << " global debug count " << allDebug << endl;  
    }




    return;
}

