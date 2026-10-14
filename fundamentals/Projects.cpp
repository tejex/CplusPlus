#include <iostream>
#include <vector>
using namespace std;

int add(int a, int b){

    return a + b;
}
int subract(int a, int b){

    return a - b;
}
int divide(int a, int b){

    return a / b;
}
int multiply(int a, int b){

    return a * b;
}

int sum(vector<int>arr){
    int total = 0;
    
    for(int i=0;i<arr.size();i++){
        total += arr[i];
    };

    return total;
}

int average(vector<int>arr){
    int total = sum(arr);
    
    return total / arr.size();
}

int minimum(vector<int> arr){
    int minimum = 100000000;

    for(int i = 0; i < arr.size(); i++){
        if(minimum > arr[i]){
            minimum = arr[i];
        };
    }

    return minimum;
}

int maximum(vector<int> arr){
    int maximum = 0;

    for(int i = 0; i < arr.size(); i++){
        if(maximum < arr[i]){
            maximum = arr[i];
        };
    }

    return maximum;
}

int main(){

    int (*operations[4])(int, int);

    operations[0] = add;
    operations[1] = subract;
    operations[2] = divide;
    operations[3] = multiply;

    bool quit = true;
    string proceed = "";

    while(quit == false){
        cout << "What would you like to do? Add - 0, Subtract - 1, Divide - 2, Multiply - 3" << endl;
        
        int answer;
        cin >> answer;

        cout << "Provide the 2 numbers you wish to perform this operation on. " << endl;
        int x;
        int y;

        cin >> x;
        cin >> y;

        cout << "Result is: " << (operations[answer](x,y)) << endl;

        cout << "Would you still like ot proceed? Y or N" << endl;
        
        cin >> proceed;
        if(proceed == "N"){
            break;
        }
        else if(proceed == "Y"){
            continue;
        }
        
        
        while(proceed != "Y" || proceed != "N"){
            cout << "Please input either Y or N" << endl;
            cin >> proceed;
            if (proceed == "Y" || proceed == "N")
            {
               break;
            }
        }
        if(proceed == "N"){
            break;
        }
    }


    int (*coolOps[4])(vector<int>);

    coolOps[0] = average;
    coolOps[1] = sum;
    coolOps[2] = minimum;
    coolOps[3] = maximum;


    while(true){
        int nums;
        cout << "How many numbers do you want in the array" << endl;
        cin >> nums;

        vector<int> arr(nums);

        for(int i=0; i < nums; i++){
            arr[i + 1] = i + 1;
        };

        int answer;
        cout << "What would you like to see, AVG-0, SUM-1, MIN-2, MAX-3" << endl;
        cin >> answer;

        int result = coolOps[answer](arr);

        cout << "Your result is " << result << endl;

        cout << "Goodbye" << endl;
        break;
    }


    return 0;
}