#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

int_least32_t processFile();

int main(){
    processFile();
    return 0;
}

int processFile(){
    string fileName;
    cout << "Enter file name: " << endl;
    cin >> fileName;
    fileName = fileName.c_str();
    ifstream inputFile(fileName);
    if (!inputFile.is_open()){
        cout << "Couldn't open file: " <<  fileName <<endl;
        return -1;
    } else {
        string capitalName, countryName;
        while(getline(inputFile,capitalName) && getline(inputFile, countryName)){
            cout << capitalName << " is the capital of " << countryName << endl;
        }
    }

    return 0;
}