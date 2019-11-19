const double EPS = 1e-9;
const double INF = 1e9;
const double H = 10;
const int MAXN = 1000;
const int MAXCOUNT = 1e4;

struct point;
istream& operator>>(istream &cin, point &p);
ostream& operator<<(ostream &cout, const point &p);
point operator+(const point &a, const point &b);
point operator-(const point &a, const point &b);
point operator+=(point &a, const point &b);
point operator-=(point &a, const point &b);
point operator-(const point &a);
point operator*(const point &a, double d);
point operator*(double d, const point &a);
point operator/(const point &a, double d);
int operator==(const point &a, const point &b);
int operator!=(const point &a, const point &b);
double operator*(const point &a, const point &b);
double operator%(const point &a, const point &b);

double rnd();
double rnd(double r);
double rnd(double l, double r);

#include "point.h"

void constants();
void bfs(int v);
void read();
void calcDist();
void get(int k);

double jump();
point next(point v);
double e(int v);
double e();
void burn(int k);
void changes(int k);

void correctirize(int k);
double X(int j);
double Y(int j);
void Rib(int j, int v, int u);
void Node(int j, int v);
void Sign(int line, string s, double r, double g, double b);
void printInfo();
void Fittest(int j, bool b);
void drawAll(int k);
void Draw();
void Timer(int value);
void Initialize();
void run(int &argc, char **argv);

// PARAMETERS:
int COUNT;
int CNT = 10;
double S;
double SCALE;
double TAB;
double B;
double R = 0.2;
double MNX, MNY, MXX, MXY;
double MXD = 0;

int n, m;
point ar[MAXCOUNT][MAXN];
point p[MAXN];
vector<int> g[MAXN];
bool used[MAXN];
double d[MAXN][MAXN];
double scale[MAXCOUNT];

double opte = INF;
double cure[MAXCOUNT];
double be = INF;
int b = 0;

double t = H * H;
