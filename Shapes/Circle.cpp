#include <Shapes/Circle.h>
#include <Algorithms/CommonFuncs.h>
Circle::Circle()
{
    type = CIRCLE;
}
Circle::Circle(const Circle& B):PixelSet(B)
{
    type=CIRCLE;
    cx=B.cx;
    cy=B.cy;
    cr=B.cr;
    vertexes.clear();
    vertexes.assign(B.vertexes.begin(), B.vertexes.end());
    algorithm = B.algorithm;
}
Circle::Circle(ALGORITHM algo,int x,int y,int r)
{
    type=CIRCLE;
    cx = x;
    cy = y;
    cr = r;
    algorithm = algo;
}


void Circle::refresh()
{
    points.clear();
    if(fill_flag){
        if (algorithm == MIDPOINT) {
            midPointcircle(cx,cy,cr,*this);
        }
        //fillCircle();
    }
    else{
        if (algorithm == MIDPOINT) {
            midPointcircle(cx,cy,cr,*this);
        }
    }
}

void Circle::paint(QImage *image)
{
    refresh();
    PixelSet::paint(image);
}

void Circle::fill(QColor fcolor)
{
    fill_flag=true;
    color=fcolor;
    refresh();
}

void Circle::rotate(int x, int y, int r)
{
    rotatePoint(cx, cy, x, y, r);
    refresh();
}

void Circle::scale(int x, int y, float s)
{
    scalePoint(cx, cy, x, y, s);
    cr = cr*s;
    refresh();
}

void Circle::translate(int dx, int dy) {
    PixelSet::translate(dx, dy);
    cx += dx; cy += dy;
}
