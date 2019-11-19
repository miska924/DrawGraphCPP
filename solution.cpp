#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

typedef long long ll;

#include "headers/declaration.h"
#include "headers/main_functions.h"
#include "headers/graphic.h"
#include "headers/burn.h"

int main(int argc, char **argv) {
    srand(time(NULL));
    constants();
    read();
    calcDist();
    run(argc, argv);
    return 0;
}