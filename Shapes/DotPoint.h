#ifndef DOTPOINT_H
#define DOTPOINT_H
#include <Shapes/PixelSet.h>
//示意点
class DotPoint :public PixelSet {
    int x, y;
    int width;
public:
    DotPoint();
    DotPoint(const DotPoint& B);
    DotPoint(int ix, int iy, int iwidth = 5, QColor icolor = Qt::black);
    void paint(QImage *image);
};
#endif // DOTPOINT_H
