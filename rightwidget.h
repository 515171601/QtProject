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
	//默认构造函数:
    explicit RightWidget(QWidget *parent = 0);
	//贴图刷新函数:
    void paintEvent(QPaintEvent *);//重载虚函数
	//表情球更新函数:
	void updateBalls();
	//表情球添加函数:
	void addBall(const Ball& b);
	//表情球移动函数:
	void moveBall(const int &direction);
	//表情球清空函数:
	void clearBalls(void);
	//设置难度函数:
	void setLevel(unsigned int le) ;
	//获得当前窗口的最小尺寸
	int getMinX() const;
	int getMinY() const;
	//获取表情球序列中最后一个小球, 即目标球:
	Ball &getLastBall() ;
	//清除键盘标志位的函数:
	void keyRelease(int key);

private:
	//储存表情球的数据结构, 这里采用QList便于增删减改
	QList<Ball> balls;

	//几个私有成员变量用于储存相应的信息:
	unsigned int level;		//储存当前的难度
	const int minX, minY;	//储存窗口最小的X,Y大小
	int directionFlag[4];	//方向标志位, 储存小球当前运动的方向

signals:

public slots:

};

#endif // RIGHTWIDGET_H
