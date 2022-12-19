#include <iostream>
#include<vector>
using namespace std;

// 두 리스트에서 숫자를 각각 1개씩 뽑아 곱하고 이후에 또 뽑아서 곱하고 이전에 구한수와 더해가면서 모든 수를 다 뽑을 때 까지
// 진행할 때 최소수를 수하는 문제이다.
// 아주 간단한 이론인데 가장 높은 수는 가장 낮은 수를 곱해야 가장 작은 값이 나오기 때문에 한쪽은 가장 높은 수를 뽑고
// 한쪽은 가장 낮은 수를 뽑아서 곱하면 된다.
// 그러면 A리스트는 오름차순, B리스트는 내림차순으로 정렬하여 순서대로 곱한 뒤 더해나가면 끝이다.

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
