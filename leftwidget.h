#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include "paintlabel.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <string>

//MainWindow的前置类型声明, 告诉编译器有这么一个类, 但是定义在别处
//由于MainWindow函数中include了leftwidget.h, 所以这里不能递归include
class MainWindow;

class LeftWidget : public QWidget
{
//Qt的一个宏
	Q_OBJECT
public:
//默认构造函数
	explicit LeftWidget(QWidget *parent = 0);

//键盘按下事件的处理函数:
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent (QKeyEvent *e);

signals:

private:
//指向主窗口的指针
	MainWindow *pmain;

//各个标签, 用于显示信息:
	QLabel *keyPressLabel,*keyPressInfo,
	*levelLabel, *targetLabel, *targetPicture;
//调节难度的编辑框:
	QLineEdit *levelEdit;

//控制暂停和重新启动的按钮:
	QPushButton *startButton,*stopButton;
//储存摁下键盘的键盘号, 主要用于调试:
	QString KeyPressNum;
//储存加载的表情:
	QVector<QString> imaginList;
//储存当前的难度:
	unsigned int level;

//开始游戏和暂停游戏的槽函数:
public slots:
	void stopBall();		//控制游戏的启动与暂停
	void startGame(void);	//重新设置表情并开始游戏
};

#endif // LEFTWIDGET_H
