#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>

class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CenterWidget(QWidget *parent = 0);
	void paintEvent(QPaintEvent *);
    void setDrawType(int type);
	void setDrawColor(Qt::GlobalColor color);
protected:
	void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
	void keyPressEvent(QKeyEvent *e);

signals:

public slots:

private:
     int drawType;
	 QString mouseClickInfo;
	 QString mousePosInfo;
	 QString KeyPressInfo;
	 Qt::GlobalColor DRAW_COLOR;

};

#endif // CENTERWIDGET_H
