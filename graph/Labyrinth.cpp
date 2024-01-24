#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int X, Y;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
            if (v[i][j] == 'B')
            {
                X = i;
                Y = j;
            }
        }
    }
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        if (x == X && y == Y)
            break;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }

    if (dist[X][Y] == -1)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n" << dist[X][Y] << '\n';
    string ans;
    while (dist[X][Y] != 0)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = X + dx[i], ny = Y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == dist[X][Y] - 1)
            {
                X = nx;
                Y = ny;
                if (dx[i] == 1)
                    ans.push_back('U');
                if (dx[i] == -1)
                    ans.push_back('D');
                if (dy[i] == 1)
                    ans.push_back('L');
                if (dy[i] == -1)
                    ans.push_back('R');
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}