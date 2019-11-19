struct point {
    double x = 0, y = 0;
    point() {
        x = rnd(H);
        y = rnd(H);
    }
    point(double a, double b) {
        x = a;
        y = b;
    }
    point(double d) {
        x = rnd(d);
        y = rnd(d);
    }
    double len() {
        return sqrt(abs(x * x + y * y));
    }
};

istream& operator>>(istream &cin, point &p) {
    cin >> p.x >> p.y;
    return cin;
}

ostream& operator<<(ostream &cout, const point &p) {
    cout << p.x << " " << p.y;
    return cout;
}

point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
}

point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
}

point operator+=(point &a, const point &b) {
    return a = point(a.x + b.x, a.y + b.y);
}

point operator-=(point &a, const point &b) {
    return a = point(a.x - b.x, a.y - b.y);
}

point operator-(const point &a) {
    return point(-a.x, -a.y);
}

point operator*(const point &a, double d) {
    return point(a.x * d, a.y * d);
}

point operator*(double d, const point &a) {
    return point(a.x * d, a.y * d);
}

point operator/(const point &a, double d) {
    return point(a.x / d, a.y / d);
}

int operator==(const point &a, const point &b) {
    return abs(b.x - a.x) < EPS && abs(b.y - a.y) < EPS;
}

int operator!=(const point &a, const point &b) {
    return abs(b.x - a.x) >= EPS || abs(b.y - a.y) >= EPS;
}

double operator*(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

double operator%(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}