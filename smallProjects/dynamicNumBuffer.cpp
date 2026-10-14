#include<iostream>
#include<vector>
using namespace std;

int main(){

    while(true){
        cout << "How many numbers would you like to store " << endl;
        int numbers;
        int total = 0;
        cin >> numbers;
        vector<int> allocated(numbers);
        cout << "okay memory has been allocated, please enter the numbers you want" << endl;
        int count = 0;
        while(count != numbers){
            int choice;
            cin >> choice;
            allocated.push_back(choice);
            if(choice <= 0){
                continue;
            }
            total += choice;
            count += 1;
        }
        cout << "Total " << total << endl;
        break;
    }
    return 0;
}