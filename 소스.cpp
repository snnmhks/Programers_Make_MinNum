#include <iostream>
#include<vector>
using namespace std;

vector<int> ListOrder(vector<int> list, int MaxNum, bool UpDown)
{
    int* tmp = new int[MaxNum];
    vector<int> tmpV;
    for (int i = 0; i < MaxNum; i++)
    {
        tmp[i] = 0;
    }
    for (int i = 0; i < list.size(); i++)
    {
        tmp[list[i]]++;
    }

    if (UpDown)
    {
        for (int i = 0; i < MaxNum; i++)
        {
            for (int j = 0; j < tmp[i]; j++)
            {
                tmpV.push_back(i);
            }
        }
    }
    else if (!UpDown)
    {
        for (int i = MaxNum - 1; i >= 0; i--)
        {
            for (int j = 0; j < tmp[i]; j++)
            {
                tmpV.push_back(i);
            }
        }
    }
    delete[] tmp;
    return tmpV;
}