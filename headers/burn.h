double jump() {
    return t / (rand() % int(H) + 1);
}

point next(point v) {
    double d = jump();
    double ang = double(rand() % 360 * 1000 + rand() % 1000) / 1000.0;
    ang = ang / 180 * M_PI;
    return point(v.x + d * cos(ang), v.y + d * sin(ang));
}

double e(int v) {
    double res = 0;
    for (int u = 0; u < n; ++u) {
        if (u == v) {
            continue;
        }
        point pt = p[u] - p[v];
        point nd = (pt / pt.len()) * d[v][u];
        point df = nd - pt;
        res += df.len() * df.len();
    }
    return res;
}

double e() {
    double res = 0;
    for (int v = 0; v < n; ++v) {
        res += e(v);
    }
    return res;
}

void burn(int k) {
    if (k == 0) {
        t *= 0.99;
    }
    cure[k] = e();
    for (int v = 0; v < n; ++v) {
        point nxt = next(p[v]);
        point cur = p[v];
        double nxte = cure[k] - e(v);
        p[v] = nxt;
        nxte += e(v);
        p[v] = cur;
        if (nxte < cure[k] || (exp((opte - nxte) / max(double(1e-5), t)) > double(rand() % 1000) / 1000.0)) {
            cure[k] = nxte;
            ar[k][v] = p[v] = nxt;
            opte = min(opte, cure[k]);
        }
    }
}

void changes(int k) {
    burn(k);
    if (be > cure[k]) {
        be = cure[k];
        b = k;
    }
}