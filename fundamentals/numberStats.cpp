#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& arr){
    int total = 0;
    for(int i =0;i<arr.size();i++){
        total += arr[i];
    }

    return total;
}
int average(int sum, int length){
    return static_cast<double>(sum) / length;
}


int main(){

    int smallest;
    int largest;

    cout << "How many integers do you want to enter ?" << endl;
    int length = 0;
    
    cin >> length;

    cout << "size of array: " << length << endl;

    vector<int> numbers;

    while(length > 0){
        int num;
        cout << "Please enter a number" << endl;
        cin >> num;
        numbers.push_back(num);
        if(numbers.size()==1){
            smallest = num;
            largest = num;
        }
        else{
            if(smallest > num){
                smallest = num;
            }
            if(largest < num){
                largest = num;
            }
        }
        length -= 1;
    }
    int total = sum(numbers);
    int avg = average(total, numbers.size());

    cout << "average: " << avg << endl;
    cout << "sum: " << total << endl;
    cout << "smallest: " << smallest << " largest: " << largest << endl;



    return 0;
}