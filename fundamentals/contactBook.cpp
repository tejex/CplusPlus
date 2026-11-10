#include <iostream>
#include <vector>
using namespace std;

struct Contact{
    string name;
    int age;
};


int main(){

    vector<Contact> contacts;

    while(true){
        cout << "Add a contact" << endl;
        cout << "-------------" << endl;

        string name;
        int age;

        cout << "Enter their name: ";
        cin >> name;
        cout << "" << endl;
        cout << "Enter their age: ";
        cin >> age;
        cout << "" << endl;

        Contact newContact;
        newContact.name = name;
        newContact.age = age;

        cout << "New contact name " << newContact.name << "New contact age: " << newContact.age << endl;

        contacts.push_back(newContact);
        string answer;
        cout << "Would you like to continue? "<< " Press Y or N - pressing and entering anything else will continue the process" << endl;
        cin >> answer;
        
        if(answer == "N"){
            break;
        }
    }

    cout << "Here are all your contacts" << endl;

    for(int i=0;i<contacts.size();i++){
        Contact contact = contacts[i];
        cout << contact.name << " " << contact.age << endl;
    }

}