#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int countLines(){

    return 0;
}

int countWords(){

    return 0;
}

int main(){

    string fileName;
    cout << "Enter the name of the file you wish to analyze " << endl;

    cin >> fileName;

    ifstream file {fileName};

    if(!file){
        cerr << "File cannot be opened for reading"<< endl;
        return 0;
    }

    int lines = 0, words = 0;
    vector<string> allLines {};
    string inputFromFile;

    while(getline(file, inputFromFile)){
        allLines.push_back(inputFromFile);
        lines += 1;
        // cout << "lines: " << inputFromFile << endl;
    }

    vector<string> allWords{};


    for(const string line : allLines){
        istringstream parser {line};
        string word;
            
        // getline(parser, word, ' ');
        // this line above was consuming my word before
        // the loop below was able to start counting it. 
        
        while(parser >> word){ //parser >> word reads the next word in the stream and stores it in the word variable, 
            //The while loop is checking whether that operation has succeeded or not.
            //When it does succeed then it means we  
            words += 1;
            cout << word << endl;
        };
        allWords.push_back(word);
    }
    

    cout << "Number of lines: " << lines << endl;
    cout << "Number of words: " << words << endl;



    return 0;
}