#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

int main(int argc, char **argv) {
    string s;
    cout << "name of test: ";
    cout.flush();
    cin >> s;
    freopen((string("tests/") + s).c_str(), "w", stdout);
    int n, m;
    cin >> n >> m;
    cout << n << " " << m << "\n";
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << "\n";
    }
    cout.flush();
    fclose(stdout);
    cout << "got it!" << endl;
    return 0;
}