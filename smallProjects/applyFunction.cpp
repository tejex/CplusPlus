#include<iostream>
#include<vector>
using namespace std;

int addOne(int num){
    int result = num + 1;
    return result;
}

int doubleValue(int num){
    num += num;

    return num;
}
int square(int num){
    int square = num * num;
    return square;
}

int applyTwice(int value, int (*operation)(int)){
    int result = operation(value);
    int secondRes = operation(result);

    return secondRes;
}

int main(){

    cout << applyTwice(5, addOne)<< endl;
    cout << applyTwice(3, doubleValue) << endl;
    cout << applyTwice(2, square) << endl;


    return 0;
}