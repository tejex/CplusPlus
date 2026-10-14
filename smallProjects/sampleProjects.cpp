#include <iostream>
#include <vector>
using namespace std;

int getRandom(vector<int> choices){
    srand(time(nullptr));
    int randomChoice = choices[rand() % choices.size()];

    return randomChoice;
}

void incrementValue(int n){
    n += 1;
}
//This does not work because we copy in the value of the parameter, but we only increment
//the copy, and since that does not get returned, the original never gets updated either. 

void incrementPointer(int* n){
    (*n) += 1;
} 
//This will work because we are passing a pointer to the function, which points to the address
//of the variable we actually want to increment. This works because the pointer has the adress
//We then visit whats at that address (our variable) then we increment and save it.

void incrementReference(int& n){
    (n) += 1;
}
//This also works because I think we are accessing the address of the integer we pass into the function
//so again, we visit the address and increment and put back the value stored at that address.

struct Player {
    int health;
    int x;
    int y;
};

void printPlayer(Player &player){
    cout << "Player health: " << player.health << endl;
    cout << "Player position " << player.x << player.y << endl;
}

int main(){

    int a = 5;

    // cout << "before increment on value: " << a << endl;
    // incrementValue(a);
    // cout << "After increment on value: " << a << endl;
    // a = 5;
    // cout << " " << endl;
    // cout << "Before increment pointer " << a << endl;
    // int *x;
    // x = &a;
    // incrementPointer(x);
    // cout << "After increment on value: " << a << endl;
    // cout << " " << endl;
    // cout << "Before increment by reference: " << a << endl;
    // incrementReference(a);
    // cout << "After increment by reference: " << a << endl;

    Player playerA = {
        playerA.health = 10,
        playerA.x = 0,
        playerA.y = 0,
    };

    printPlayer(playerA);

    playerA.x += 10;
    playerA.y -= 20;

    cout << " " << endl;

    playerA.health -= 5;
    
    printPlayer(playerA);    
    
    return 0;
}