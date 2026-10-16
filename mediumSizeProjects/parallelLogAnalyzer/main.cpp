#include<iostream>
#include<vector>
#include<string>
#include "parallel.h"
#include "parallel.cpp"
#include <filesystem>
#include<thread>


using namespace std;

namespace fs = std::filesystem;

fs::path targetDirectory = "logs";
//Parallel log analyzer project

// - accept a folder path and process the log files directly inside it
// - recognize lines with [INFO] [WARN] and [Error]
// - report total lines for each file and overall
// - support both sequential and parallel models
// - Allow the user to choose the number of worker threads
// - Both models should show identical counts
// - Report elapsed processing time to compare models
// - Handle empty files, missing folders and unreadable files clearly


//Class based? or Just regular functions in header files? 

int main(){

    int threads;

    bool parallel = true;
    int userProcessingChoice = 0;
    
    cout << "Would you like sequential processing 1 - Yes, 0 - No " << endl;
    
    cin >> userProcessingChoice;


    if(userProcessingChoice == 1){
        parallel = false;
    }

    if(userProcessingChoice == 0){
        parallel = true;

        cout << "How many threads would you like to process your data? You can only have up to 3" << endl;
        cin >> threads;
        
        while(threads > 3){
            if(threads <= 3 && threads != 0){
                break;
            }
            cout << "Please enter a number between 1-3" << endl;
            cin >> threads;
        }
    }

    cout << targetDirectory << endl;

    if(!fs::exists(targetDirectory) || !fs::is_directory(targetDirectory)){
        std::cout << "Working directory: " << fs::current_path() << '\n';
        std::cout << "Looking for: " << fs::absolute(targetDirectory) << '\n';
        cerr << "Directory does not exist or is invalid" << endl;
        return 0;
    }
    //pass the target directory along to these if / else statements and let them do the rest of the work 


    if(parallel){
        //conduct parallel processing on the log files here
        //open multiple threads here and have them execute the count categories
        //function.
        vector<thread> workers;
        //how can I close out the thread, or do thread.join...
        //would it be okay to do it right after calling the function? then whats 
        //the point? wanted to open three threads or x threads on the loop, then 
        //close them out, not open -> thread.join() each time, 
        for (const auto& entry : fs::directory_iterator(targetDirectory)) {
            if(fs::is_regular_file(entry.path())){
                workers.emplace_back(countCategories, entry.path());
            }
        }
        
        for(auto& worker: workers){
            worker.join();
        }
    }
    if(!parallel){
        cout << "Here " << endl;
        //conduct sequential processing on the log files here

        //Here we dont start any threads, instead we just call the function 
        //directly but for every file the directory we are exploring has.
         for (const auto& entry : fs::directory_iterator(targetDirectory)){
            countCategories(entry.path());
         }

    }

}