/*

    This proragm populates a vector by inserting 
    element in the correct position. Idea is to 
    learn about: v.insert(v.begin() + n, num);

 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void addToVector(vector<int> &, int);

int main()
{
    vector<int> v;
    while (true)
    {
        cout << "Enter a number: " << endl;
        string userInput;
        getline(cin, userInput);
        stringstream ss(userInput);
        int num;
        if (ss >> num)
        {
            string extra;
            if (ss >> extra)
            {
                cout << "enter int only!" << endl;
            }
            else
            {
                if (num == -1)
                {
                    break;
                }
                else
                {
                    cout << "Calling add to Vector" << endl;
                    addToVector(v, num);
                }
            }
        }
    }
}

void addToVector(vector<int> &v, int num)
{
    if (v.size() == 0)
    {
        v.push_back(num);
    }
    else
    {
        int size = v.size();
        for (size_t i = 0; i < size; i++)
        {
            if (v[i] >= num)
            {
                v.insert(v.begin() + i, num);
                i++;
            }
            else if (i == size - 1)
            {
                v.push_back(num);
            }
        }
    }

    cout << "So far our vector looks like this: " << endl;
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}