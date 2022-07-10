#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int>arr;

void sliding_rmq_maximum()
{
    deque<int>dq(k);

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for (int i = k; i < n; ++i)
    {
        cout << arr[dq.front()] << " ";

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl;
}

void sliding_rmq_minimum()
{
    deque<int>dq(k);

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    for (int i = k; i < n; ++i)
    {
        cout << arr[dq.front()] << " ";

        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl;
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sliding_rmq_maximum();
    sliding_rmq_minimum();

    return 0;
}
