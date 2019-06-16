#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<int>&);
void printVector(vector<int>&);

int main(){
    vector<int> numbers;
    int num;
    while (true){
        cout << "Enter number to store in vector\nEnter -1 to quit:\n";
        cin >> num;
        if (num != -1){
            numbers.push_back(num);
        } else{
            break;
        }
    }
    
    selectionSort(numbers);
    printVector(numbers);
}

void selectionSort(vector<int>& v){
    for (size_t i = 1; i < v.size(); ++i){
        int sortedUntil = i - 1;
        for (int j = i - 1; )

    }
}

void printVector(vector<int>& v){

}