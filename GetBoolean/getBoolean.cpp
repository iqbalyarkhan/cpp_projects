/*
Using the code for GetInteger and the boolalpha stream manipulator, write a function
GetBoolean that waits for the user to enter “true” or “false” and returns the corresponding
boolean value.
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

bool GetBoolean();

int main(){

    bool returnedBool;
    returnedBool = GetBoolean();
    cout << "Returned bool is: " << returnedBool << endl;
    return 0;
}

//Function GetBoolean that returns false or true
//based on user inputc
bool GetBoolean(){
    bool result;

    while(true){
        stringstream ss;
        string input;
        cout << "Enter boolean value: " << endl;
        getline(cin, input);
        ss << input;
        bool booleanResult;
        if (input >> booleanResult){
            //The input was of the form true or false
            string extra;
            if(input >> extra){
                //The input had extra shit after
                cout << "Please enter true or false ONLY, there was extra shit: " << extra << endl;
            } else {
                return booleanResult;
            }
        } else {
            cout << booleanResult << " is not of type bool, please enter true or false only" << endl;
        }

        cout << "Retry: " << endl;
    }
}