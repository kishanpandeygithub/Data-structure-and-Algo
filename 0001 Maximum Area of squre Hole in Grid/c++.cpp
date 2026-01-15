#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <algorithm>

class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int maxConsicutivehBars = 1;
        int maxConsicutivevBars = 1;

        int currentConcutiveBar = 1;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] - hBars[i - 1] == 1)
            {
                currentConcutiveBar++;
            }
            else
            {
                currentConcutiveBar = 1;
            }
            maxConsicutivehBars = max(maxConsicutivehBars, currentConcutiveBar);
        }
        currentConcutiveBar = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] - vBars[i - 1] == 1)
            {
                currentConcutiveBar++;
            }
            else
            {
                currentConcutiveBar = 1;
            }
            maxConsicutivevBars = max(maxConsicutivevBars, currentConcutiveBar);
        }

        int side = min(maxConsicutivehBars, maxConsicutivevBars) + 1;
        return side * side;
    }
};
int main()
{
    return 0;
}