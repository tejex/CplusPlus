#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

#include "helpers.h"
using namespace std;

//Log analyzer program in C++

int main(){

    int totalLines = 0;

    ifstream file {"sample.log"};

    if(!file){
        cerr << "File cannot be opened for reading"<< endl;
    }

    string inputFromFile{};

    vector<string> fileLines{};

    int lines = 0;

    //Ah we can use the '|' as the separator and grab each word / block from the log file. 

    while(getline(file, inputFromFile)){
        // cout << inputFromFile << '\n';
        fileLines.push_back(inputFromFile);
        lines += 1;
    }
    //Since we already read everything until the end of the file stream, the stream
    // is already at the end, so we will need to start back up top, but since we already
    //appened / pushed every line into the array / vector we have, we can sort of 
    // loop through that instead.
    

    //The above works fine as well, we just need to 'restart' the stream at the top and 
    //use a loop like before to read through the file again, but this is a bit better
    //since we already stored each line into an array. 

    int errorCount = 0, warningCount = 0, infoCount = 0, unknown = 0;

    vector<string> errorLines {}, warningLines{}, infoLines{}, unknownLines{};


    for(const string line : fileLines){
        istringstream parser {line};
        string timestamp, status;

        getline(parser, timestamp,'|');
        parser >> status;

        if(status == "INFO"){
            infoCount += 1;
            infoLines.push_back(line);
        }
        else if(status == "ERROR"){
            errorCount += 1;
            errorLines.push_back(line);
        }
        else if(status == "WARNING"){
            warningCount += 1;
            warningLines.push_back(line);
        }
        else{
            unknown += 1;
            unknownLines.push_back(line);
        }
    }
    //Trailing an leading white space markers are in the way. 


    cout << "File has " << lines << "  lines" << endl;
    cout << "File has " << errorCount << " errors " << warningCount << " warnings " << " and " << infoCount << " info status labels and " << unknown << " unidentified status lines" << endl;

    cout << "Search a key word to reveal all the matching lines from your log file " << endl;
    cout << "Choose between Error - 0, Info - 1, Warning - 2 and Unknown - 3 " << endl;
    int key;
    cin >> key;

    while(key != 0 || key != 1|| key != 2 || key != 3){
        cout << "please enter an appropriate value" << endl;
        cin >> key;
        if(key == 0 || key == 1|| key == 2 || key == 3){
            break;
        }
    }
    if(key == 0){
        printLines(errorLines);
        writeToFile(errorCount, "Error");
    }
    else if(key == 1){
        printLines(infoLines);
        writeToFile(infoCount, "Info");
    }
    else if(key == 2){
        printLines(warningLines);
        writeToFile(warningCount, "Warning");
    }
    else if(key == 3){
        printLines(unknownLines);
        writeToFile(unknown, "Unknown");
    }
    return 0;
}