/*
This program shows how to take input from a user and store, 
in a vector. Only when the user hits 'q', do we call 
insertion sort to sort all user inputs. 
Use of stringstream is also displayed
 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void insertionSort(vector<int> &);

int main(){
    vector<int> v;
    while(true){
        cout << "Enter a number or press \"q\" to QUIT: " << endl;
        string userInput;
        getline(cin, userInput);
        stringstream ss(userInput);
        int number;
        if (ss >> number){
            string extra;
            if(ss >> extra){
                cout << extra << " was extra, please enter an int only!" << endl;
            } else {
                v.push_back(number);
            } 
        } else {
            if(userInput == "q"){
                insertionSort(v);
                break;
            }
            cout << userInput << " is not an integer." << endl;
        }
    }

    if (!v.empty()){
        for (size_t i = 0; i < v.size(); ++i){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

void insertionSort(vector<int>& v){
    //Earlier I used v[i] instead of key,that didn't print desired results.
    //Asked on SO to clarify here: https://stackoverflow.com/questions/56613677/c-insertion-sort-confusion
    for (size_t i = 0; i < v.size(); ++i){
        int j = i - 1;
        int key = v[i];
        while(v[j] > key && j >= 0){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}