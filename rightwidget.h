#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H
#include "ball.h"
#include <QWidget>
#include <QList>
#include "paintlabel.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>


class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//重载虚函数
    void updateBalls();  //定义移动小球的接口
    void addBall(const Ball& b);  //添加小球的接口
	void moveBall(const int &direction);
	void clearBalls(void);
	void setLevel(unsigned int le) ;
	int getMinX() const;
	int getMinY() const;
	Ball &getLastBall() ;

private:
    QList<Ball> balls;//多个小球
	unsigned int level;
	const int minX, minY;
	int frontKey;
signals:

public slots:

};

#endif // RIGHTWIDGET_H
