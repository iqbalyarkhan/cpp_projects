/*
    This program reads in 2 files: keywords file that contains
    all keywords in C++ language and a second test file to 
    count the occurrence of keywords in that file. It then
    prints the count of keywords in test file.
 */
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

void openFile(ifstream&);
set<string> getKeyWords(ifstream&);
void readFile(ifstream&, stringstream&);
void printAndPopulateMap(set<string>&,stringstream&);

int main(){
    ifstream f;
    ifstream testFile;
    openFile(f);
    openFile(testFile);
    set<string> keyWordSet = getKeyWords(f);
    stringstream ss;
    readFile(testFile,ss);
    printAndPopulateMap(keyWordSet,ss);
}

void printAndPopulateMap(set<string>& keyWordSet,stringstream& ss){
    map<string,int> frequencyMap;
    string wordReceived;
    while(ss >> wordReceived){
        if (keyWordSet.count(wordReceived)){
            ++frequencyMap[wordReceived];
        }
    }

    for(map<string,int>::iterator itr = frequencyMap.begin(); itr != frequencyMap.end(); ++itr){
        cout << "Keyword "<<itr->first << " occurred " << itr->second << " times." << endl;
    }
}


void openFile(ifstream& f){
    while (true){
        cout << "Enter valid file name: " << endl;
        string fileName;
        getline(cin, fileName);
        f.open(fileName);
        if(!f.is_open()){
            cout << "Couldn't open file " << fileName << endl;
        } else {
            break;
        }
    }
}

set<string> getKeyWords(ifstream& f){
    set<string> keyWordSet;
    string keyword;
    while(f >> keyword){    
        keyWordSet.insert(keyword);
    }

    return keyWordSet;
}

void readFile(ifstream& f, stringstream& ss){
    if (f) {
        ss << f.rdbuf();    
        f.close();
    }
}
