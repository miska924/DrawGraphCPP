void correctirize(int k) {
    MNX = INF;
    MXX = -INF;
    MNY = INF;
    MXY = -INF;
    for (int i = 0; i < n; ++i) {
        MNX = min(MNX, p[i].x);
        MXX = max(MXX, p[i].x);
        MNY = min(MNY, p[i].y);
        MXY = max(MXY, p[i].y);
    }
    scale[k] = S * (H) / max(MXX - MNX, MXY - MNY);
    for (int i = 0; i < n; ++i) {
        p[i] = p[i] - point(MNX, MNY) +
               point(max(double(0), (-(MXX - MNX) + (MXY - MNY)) / 2),
                     max(double(0), ( (MXX - MNX) - (MXY - MNY)) / 2));
    }
}

double X(int j) {
    return double(j % CNT) * TAB + B;
}

double Y(int j) {
    return double(CNT - 1 - j / CNT) * TAB + B;
}

void Rib(int j, int v, int u) {
    glBegin(GL_LINES);
        glColor3f(0.5, 0.5, 0.5);
        point a = point(X(j), Y(j)) + (p[v] * scale[j] + (p[u] - p[v]) / (p[u] - p[v]).len() * R * S);
        point b = point(X(j), Y(j)) + (p[u] * scale[j] + (p[v] - p[u]) / (p[v] - p[u]).len() * R * S);
        glVertex2f(a.x, a.y);
        glVertex2f(b.x, b.y);
    glEnd();
}

void Node(int j, int v) {
    glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        for (int i = 0; i < 360; ++i) {
            glVertex2f(X(j) + (p[v].x) * scale[j] + (R * cos(double(i + 0) / 180 * M_PI) * S),
                       Y(j) + (p[v].y) * scale[j] + (R * sin(double(i + 0) / 180 * M_PI) * S));
            glVertex2f(X(j) + (p[v].x) * scale[j] + (R * cos(double(i + 1) / 180 * M_PI) * S),
                       Y(j) + (p[v].y) * scale[j] + (R * sin(double(i + 1) / 180 * M_PI) * S));
        }
    glEnd();
    if (COUNT == 1) {
        glColor3f(0, 1, 1);
        string s = to_string(v + 1);
        glRasterPos2f(X(j) + p[v].x * scale[j]- R / 3 * (s.size()) * S, Y(j) + p[v].y * scale[j] - R / 3 * S);
        for (int i = 0; i < s.size(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
        }
    }
}

void Sign(int line, string s, double r, double g, double b) {
    double x = -H / 4 - 0.5;
    double y = H - H / 30 * line;
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < s.size(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
    }
}

void printInfo() {
    Sign(0, "INFORMATION", 0, 1, 0);
    Sign(2, "GLOBAL  MIN ENERGY:", 0, 1, 0);
    Sign(3, to_string(opte), 0, 1, 0);
    Sign(5, "CURRENT MIN ENERGY:", 0, 1, 0);
    Sign(6, to_string(be), 0, 1, 0);
    Sign(8, "TEMPERATURE:", 0, 1, 0);
    Sign(9, to_string(t), 0, 1, 0);
}

void Fittest(int j, bool b) {
    glBegin(GL_LINES);
        glColor3f(!b, b, 0);
        glVertex2f(X(j) - B / 2          , Y(j) - B / 2          );
        glVertex2f(X(j) - B / 2          , Y(j) - B / 2 * 3 + TAB);
        glVertex2f(X(j) - B / 2 * 3 + TAB, Y(j) - B / 2 * 3 + TAB);
        glVertex2f(X(j) - B / 2 * 3 + TAB, Y(j) - B / 2          );

        glVertex2f(X(j) - B / 2          , Y(j) - B / 2 * 3 + TAB);
        glVertex2f(X(j) - B / 2 * 3 + TAB, Y(j) - B / 2 * 3 + TAB);
        glVertex2f(X(j) - B / 2 * 3 + TAB, Y(j) - B / 2          );
        glVertex2f(X(j) - B / 2          , Y(j) - B / 2          );
    glEnd();
}

void drawAll(int k) {
    Fittest(k, e() / opte < 1.01);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            Rib(k, i, g[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        Node(k, i);
    }
}


void Draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    for (int k = 0; k < COUNT; ++k) {
        get(k);
        correctirize(k);
        drawAll(k);
        changes(k);
    }
    printInfo();

    glFlush();
    glutSwapBuffers();
}

void Timer(int value) {
    Draw();
    glutTimerFunc(0, Timer, 0);
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1 - H / 4, H + 1, -1, H + 1, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void run(int &argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000 * 0.8, 800 * 0.8);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("BURNING GRAPH");
    glutDisplayFunc(Draw);
    glutTimerFunc(50, Timer, 0);
    Initialize();
    glutMainLoop();
}
