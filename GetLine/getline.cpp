#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int GetInteger();

int main(){
    int userEntered;
    userEntered = GetInteger();
    cout << "User entered: " << userEntered << endl;
}

int GetInteger(){
    cout << "Enter an int: " << endl;
    string userInput;
    while (true){
        stringstream ss;
        getline(cin,userInput);
        ss << userInput;
        //Making sure that an int was passed
        int result;
        if (ss >> result){
            //Making sure that there is no extra stuff after
            string extra;
            if (ss >> extra){
                cout << "Unexpected stuff at end of input: " << extra << endl;
            } else{
                return result;
            }
        } else {
            cout << "Number you entered is not an INT. Please enter an integer" << endl;
        }
        cout << "Retry: " << endl;
        // ss.clear();
    }
}
