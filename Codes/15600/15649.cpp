#include <iostream>
using namespace std;

bool visited[10];
int arr[10];
int m, n;

void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; ++i) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    solve(0);
    return 0;
}
