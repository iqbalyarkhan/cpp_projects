/*
Write a function OpenFile that accepts as input an ifstream by reference and prompts the user
for the name of a file. If the file can be found, OpenFile should return with the ifstream opened
to read that file. Otherwise, OpenFile should print an error message and reprompt the user.
(Hint: If you try to open a nonexistent file with an ifstream, the stream goes into a fail state and you
will need to use .clear() to restore it before trying again).
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

void OpenFile(ifstream &);

int main(){
    ifstream testFile;
    OpenFile(testFile);
    string line;
    getline(testFile,line);
    cout << line << endl;
}

void OpenFile(ifstream &myStream){
    while (true){
        myStream.clear();
        cout << "Enter file name: " << endl;
        string fileName;
        getline(cin, fileName);
        myStream.open(fileName);
        if (!myStream.is_open()){
            cout << "Couldn't open file, try again." << endl;
        } else {
            break;
        }
    }
    // return myStream;
}