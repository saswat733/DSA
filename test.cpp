#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> binaryConvert(int num)
{
    vector<int> ans;
    while (num != 1)
    {
        if (num % 2 == 1)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
        num = num / 2;
    }
    ans.push_back(1);
    return ans;
}

int decimalConvert(vector<int> binaryNo)
{
    int ans = 0;
    int power = 0;
    for (int i = binaryNo.size() - 1; i >= 0; i--)
    {
        ans += binaryNo[i] * pow(2, power);
        power++;
    }
    return ans;
}

vector<int> bitManipulation(int num, int j)
{
    vector<int> binaryCode = binaryConvert(num);
    vector<int> realAns;
    for (int i = j; i > 0; i--)
    {
        if (i == 1)
        {
            if (binaryCode[i] == 0)
            {
                realAns.push_back(0);
                binaryCode[i] = 1;
            }
            else
            {
                realAns.push_back(1);
            }
        }
    }

    int ans = decimalConvert(binaryCode);

    realAns.push_back(ans);

    realAns.push_back(num);

    return realAns;
}

int main()
{
    int n = 11;
    int i = 2;
    vector<int> ans = bitManipulation(n, i);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
