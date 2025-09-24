struct resultTable {
    int i;
    int p;
    int x;
    int y;
    resultTable *next;
}

struct Point {
    int x;
    int y;
    Point *next;
}

Point* swapPoint(double alpha, Point a, Point b) {
    if (alpha >= 0 && alpha <= 1) {
        Point *rs = new Point();
        rs->x = a.x;
        rs->y = a.y;
        Point *rsb = new Point();
        rsb->x = b.x;
        rsb->y = b.y;
        rs->next = rsb;
        return rs;
    }
}

resultTable* bresLine(Point a, Point b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    double alpha = (double) dy / dx;
    
}
