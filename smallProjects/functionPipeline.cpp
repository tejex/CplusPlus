#include<iostream>
#include<vector>
using namespace std;

int runPipeline(int value, int (*operations[])(int), int operationCount){
    int prevResult = operations[0](value);
    for(int i=1; i< operationCount; i++){
        prevResult = operations[i](prevResult);
    }

    return prevResult;
}

int addOne(int num){
    cout << " add one " << num << endl;
    int result = num + 1;
    return result;
}

int doubleValue(int num){
    cout << "double "<< num << endl;
    num *= 2;
    return num;
}
int square(int num){
    cout << "square " << num <<endl;
    int square = num * num;
    return square;
}

int main(){
    int (*operations[])(int) = {addOne, doubleValue, square};

    cout << runPipeline(2, operations, 3) << endl;

    return 0;
}