#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <deque>

using namespace std;
void populateDeque(deque<int>&);
void printDeque(deque<int>&);
void rotateClockWise(deque<int>&);
void rotateCounterClockWise(deque<int>&);

int main()
{
    deque<int> d;
    populateDeque(d);
    printDeque(d);
    rotateClockWise(d);
    printDeque(d);
    rotateCounterClockWise(d);
    printDeque(d);

}

void populateDeque(deque<int>& d)
{
    cout << "Enter integers or press q to quit: " << endl;

    while (true)
    {
        std::string userInput;
        getline(std::cin, userInput);
        std::stringstream ss(userInput);
        int num;
        if (ss >> num)
        {
            string extra;
            if (ss >> extra)
            {
                cout << "There was extra stuff: " << extra << endl;
                cout << "Retry: " << endl;
            }
            else
            {   
                if (num == -1){
                }
                d.push_back(num);
            }
        }
        else
        {
            if (userInput == "q"){
                break;
            }
            std::cout << "User input is not an integer: " << userInput << std::endl;
            std::cout << "Retry" << std::endl;
        }
    }
}

void printDeque(deque<int>& d){
    for (int i = 0; i < d.size(); ++i){
        cout << d[i] << " ";
    }

    cout << endl;
}

void rotateClockWise(deque<int>& d){
    cout << "Rotating clockwise..." << endl;
    int lastElement = d.at(d.size() - 1);
    d.pop_back();
    d.push_front(lastElement);
}
void rotateCounterClockWise(deque<int>& d){
    cout << "Rotating counter clockwise..." << endl;
    int firstElement = d.at(0);
    d.pop_front();
    d.push_back(firstElement);
}