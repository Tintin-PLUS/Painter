#ifndef CANVAS_H
#define CANVAS_H


#include <vector>
#include <QImage>
#include <QColor>
#include <Shapes/Point.h>
#include <Algorithms/AlgorithmBase.h>
#include <Shapes/DotPoint.h>
#include <Shapes/Polygon.h>
#include <Shapes/Rectangle.h>
class PixelSet;
class Curve;
class CtrlPoint;
class FoldLine;
class Line;
class Circle;
class Triangel;
using namespace std;
class Canvas{

protected:
    QColor color=0xFF0000;   //画笔颜色
    QColor fill_color=Qt::red;
    int penWidth = 1;
public:
    Canvas():color(0, 0, 0) {}
    Canvas(const Canvas& B);
    const Canvas& operator=(const Canvas& B);
    ~Canvas();
    int id_counter = 0;   //图形编号
    std::vector<PixelSet *> PixelSets;   //画布上所有图形的集合
    int getID(int x, int y);
    int getType(int id);
    int getNewID();
    void delID(int id);
    void fill(int id);
    void getImage(QImage *image);
    void drawCurve(int id,ALGORITHM algo, FoldLine *fl);
    void drawDotPoint(int id, int x, int y, int iwidth = 10, QColor icolor = Qt::black);
    void drawLine(int id, int x1, int y1, int x2, int y2, ALGORITHM algorithm);
    void drawRectangle(int id,int x1,int y1,int x2,int y2);
    void drawCircle(int id,ALGORITHM algo,Point &center,int x);
    void drawTriangle(int id, int x1, int y1, int x2, int y2,int x3,int y3, ALGORITHM algorithm);
    void drawPolygon(int id, const vector<Point>& vertexs, ALGORITHM algorithm);
    FoldLine* drawFoldLine(int id,const vector<Point>& vertexes);
    void drawEllipse(int id, int x, int y, int rx, int ry);
    void drawCtrlPoint(int id,int index, FoldLine * fl);
    void setColor_pen(int r, int g, int b);
    void setColor_fill(int r, int g, int b);
    void setColor_pen(QColor pcolor);
    void setColor_fill(QColor pcolor);
    void setPen_width(int w);
    void clear_all();
    void translate(int id, int dx, int dy);
    void rotate(int id, int x, int y, int r);
    void scale(int id, int x, int y, double s);
    void clip(int id, int ix1, int iy1, int ix2, int iy2, ALGORITHM algorithm = COHEN);
    void clipAll(int ix1, int iy1, int ix2, int iy2, ALGORITHM algorithm = COHEN);
    void clearPixelSet();
    PixelSet* getPixelSet(int id);
};
#endif //CANVAS_H
