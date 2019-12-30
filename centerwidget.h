#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>

class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//重载虚函数，当窗口需要刷新的时候用。如果要在窗口输出内容，则需要重载虚函数。
    void setDrawType(int type);
protected:
    void mousePressEvent(QMouseEvent *e);    //虚函数，在其中处理鼠标事件发生的时候的处理逻辑。
    void mouseMoveEvent(QMouseEvent *e);
signals:

public slots:
private:
     int drawType;
     QString mouseClickInfo;  //保存点击信息的字符串
     QString mousePosInfo;    //保存鼠标位置的字符串
};

#endif // CENTERWIDGET_H
