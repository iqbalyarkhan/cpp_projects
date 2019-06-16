#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_LINES = 4;
const int NUM_COLUMNS = 3;
const int COLUMN_WIDTH = 20;

void printHeader();
void printBody();

int main(){
    cout << "[" << left << setw(10) << "Hello" << "]"<< endl;
    cout << "[" << right << setw(10) << "Hello" << "]" << endl;
    // printHeader();
    // printBody();
}

void printHeader(){
    for (int i = 1; i <= NUM_COLUMNS; i++){
        for (int j = 0; j < COLUMN_WIDTH; j++){
            cout << "-";
        }
        if (i != NUM_COLUMNS){
            cout << "+";
        }
    }
    cout << endl;
}

void printBody(){

    ifstream fileReader("data.txt");
    if (fileReader.is_open()){
        int firstNum;
        double secondNum;
        for (int i = 1; i <= NUM_LINES; i++){
            fileReader >> firstNum >> secondNum;
            cout << setw(COLUMN_WIDTH - 2) << i << setw(3) << "|" << setw(COLUMN_WIDTH - 2) << firstNum << setw(3) << "|" << setw(COLUMN_WIDTH) << secondNum << endl;
        }
    } else {
        cerr << "Couldn't open file: data.txt" << endl;
    }
}