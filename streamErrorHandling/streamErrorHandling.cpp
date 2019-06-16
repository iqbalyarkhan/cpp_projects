#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void processFile();

int main(){
    processFile();
    return 0;
}

void processFile(){
    ifstream inputStream("errorData.txt");
    if (!inputStream.is_open()){
        cout <<"Couldn't open file, exiting program" << endl;
    } else{
        while(true){
            int total;
            int currVal;
            inputStream >> currVal;
            if (inputStream.fail()){
                inputStream.clear();
                cout << "Failed val: " << currVal << endl;
                break;
            }
            cout << "Curr total: " << total << " + " << currVal << " = ";
            total += currVal;
            cout << total << endl;
        }
    }
}