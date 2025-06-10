/*********LARGEST RECTANGLE IN HISTOGRAM******** */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n) //assume  arr[] = {1,5,3,2}
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextLargerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> stk;

    for (int i = n - 1; i >= 0; i--) {

        while (!stk.empty() && stk.top() <= arr[i]) {
            stk.pop();
        }

        if (!stk.empty()) {
            result[i] = stk.top();
        }

        stk.push(arr[i]);
    }

    return result;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> heights = {2, 1, 6, 6, 2, 3};

    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int l = heights[i];
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }

    cout << "Area: " << area << endl;

    return 0;
}