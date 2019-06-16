#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

void addToVector(vector<int>&);

int main(){
    while(true){
        cout << "Enter a number: " << endl;
        string userInput;
        getline(cin,userInput);
        stringstream ss(userInput);
        int num;
        if (ss >> num){
            string extra;
            if (ss >> extra){
                cout << "enter int only!" << endl;
            } else {
                addToVector(v);
            }
        }
    }
}

void addToVector(<vector>int v){
    
}