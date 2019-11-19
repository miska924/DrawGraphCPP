double rnd() {
    return double(rand() % 1000) + double(rand() % 1000) * 1000 + double(rand() % 1000) / 1000;
}

double rnd(double r) {
    double res = rnd();
    double cnt = res / r;
    return res - r * ll(cnt);
}

double rnd(double l, double r) {
    return rnd(r - l) + l;
}

void constants() {
    cout << "number of processes: ";
    cout.flush();
    cin >> COUNT;
    CNT = sqrtl(COUNT);
    while (CNT * CNT < COUNT) {
        CNT++;
    }
    S = 0.8 / CNT;
    TAB = H / CNT;
    B = TAB * 0.1;
}

void bfs(int v) {
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    queue<int> q;
    d[v][v] = 0;
    used[v] = true;
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); ++i) {
            int to = g[u][i];
            if (!used[to]) {
                used[to] = true;
                q.push(to);
                MXD = max(MXD, d[v][to] = d[v][u] + 1);
            }
        }
    }
}

void read() {
    cout << "test: ";
    cout.flush();
    string s;
    cin >> s;
    freopen((string("tests/") + s).c_str(), "r", stdin);
    cin >> n >> m;
    if (m == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    } else {
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    for (int i = 0; i < CNT * CNT; ++i){
        cure[i] = INF;
    }
    fclose(stdin);
}

void calcDist() {
    for (int i = 0; i < n; ++i) {
        bfs(i);
    }
}

void get(int k) {
    for (int i = 0; i < n; ++i) {
        p[i] = ar[k][i];
    }
}
