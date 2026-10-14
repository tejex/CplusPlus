#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

#include "helpers.h"

using namespace std;

void writeToFile(int count, string status){
    ofstream outF{"results.txt", ios::app};

    if(!outF){
        cerr << "results.txt cant be openend to be written on" << endl;
        return;
    }

    //im an idiot i didnt open the file in append mode so it wrote directly over it

    outF << status << " " << count << "\n";
    outF.close();
}

void printLines(vector<string> arr){

    for(string line : arr){
        cout << line << endl;
    }
}