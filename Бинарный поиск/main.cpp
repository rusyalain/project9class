// https://algocourses.ru/files/course_bp2024/contest-44337-ru.pdf
// Задача: A

#include <iostream>

using namespace std;

#define int long long

int N[100001];
int K[100001];

int32_t main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> N[i];
    for (int i = 1; i <= k; i++)
    {
        cin >> K[i];
        int l = 1, r = n + 1;
        while (r - l > 1)
        {
            int sr = (r + l) / 2;
            if (N[sr] <= K[i])
            {
                l = sr;
            }
            else
            {
                r = sr;
            }
        }
        if (abs(N[l] - K[i]) <= abs(N[r] - K[i]))
            cout << N[l] << "\n";
        else
            cout << N[r] << "\n";
    }
}