// https://informatics.msk.ru/mod/statements/view.php?id=43201#1

#include <iostream>

using namespace std;

#define int long long

int n[100001];
pair<int, int> k[30001];
int ps[100001];

int32_t main()
{
    int N, K;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> n[i];
    cin >> K;
    for (int i = 1; i <= K; i++)
        cin >> k[i].first >> k[i].second;
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i - 1] + n[i];
    for (int i = 1; i <= K; i++)
        cout << ps[k[i].second] - ps[k[i].first - 1] << " ";
}