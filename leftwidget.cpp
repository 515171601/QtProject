#include "leftwidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <ctime>
#include "mainwindow.h"
#include <QPicture>

LeftWidget::LeftWidget(QWidget *parent) :
	QWidget(parent)
{
	pmain=(MainWindow *)parent;

//实例化各个标签, 并设置显示的文本内容:
	levelLabel=new QLabel(this);
	levelLabel->setText (tr("当前难度:"));
	keyPressLabel=new QLabel(this);
	keyPressLabel->setText (tr("按下的按键:"));
	keyPressInfo=new QLabel(this);
	keyPressInfo->setText (tr("初始化"));
	targetLabel=new QLabel(this);
	targetLabel->setText (tr("目标:"));
	targetPicture=new QLabel(this);

//实例化编辑框, 并初始化内容为1:
	levelEdit=new QLineEdit("1",this);

//实例化两个按钮, 并设置显示的文本内容:
	startButton=new QPushButton(tr("开始"),this);
	stopButton=new QPushButton(tr("暂停"),this);

//将窗口网格化, 便于设置各个标签的位置:
	QGridLayout *mainLayout=new QGridLayout(this);
//设置各个Label的位置:
	mainLayout->addWidget (levelLabel,0,0);
	mainLayout->addWidget (levelEdit,0,1);
	mainLayout->addWidget (startButton,1,0);
	mainLayout->addWidget (stopButton,1,1);
	mainLayout->addWidget (keyPressLabel,2,0);
	mainLayout->addWidget (keyPressInfo,2,1);
	mainLayout->addWidget (targetLabel,3,0);
	mainLayout->addWidget (targetPicture,3,1);
	setLayout(mainLayout);

//将信号和对应的槽函数连接, 当触发信号时自动调用槽函数并传参
	connect(startButton, SIGNAL(clicked()),this,SLOT(startGame()));
	connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));

//加载各个表情到私有成员, 用于后头的显示:
	//这里使用绝对路径, 便于调试:
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/bishi.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/huaji.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/lei.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/pen.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/taikaixin.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/kuanghan.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/bugaoxing.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/jingku.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/yi.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/jingya.png"));
	this->imaginList.push_back (QString("D:/Git/Commodity/QtProject/hehe.png"));
//素质return:
	return ;
}

//keyPressEvent键盘按下事件槽函数:
void LeftWidget::keyPressEvent(QKeyEvent *e)
{
	//通过pmain主窗口指针简介访问到右窗口:
	RightWidget *right=pmain->getRightWidget();

	//更新私有成员, 并显示当前键盘按下的信息, 主要用于调试
	this->KeyPressNum=QString::number(e->key());
	this->keyPressInfo->setText (KeyPressNum);

	//调用右窗口的moveBall函数实现小球的移动
	right->moveBall (e->key ());

	return ;
}

void LeftWidget::keyReleaseEvent(QKeyEvent *e)
{
	RightWidget *right=pmain->getRightWidget();
	right->keyRelease (e->key ());
	return ;
}

//stopBall槽函数:
void LeftWidget::stopBall(){

	//点击后重置显示文本内容
	if(stopButton->text()==tr("暂停")){
		pmain->StopTimer();
		stopButton->setText(tr("开始"));
	}
	else{
		pmain->resumeTimer();
		stopButton->setText(tr("暂停"));
	}
	return ;
}

//startGame开始游戏函数:
void LeftWidget::startGame()
{
	//向Qt控制台输出信息, 用于调试
	qDebug() <<"Start Game\n";

	//通过pmain主窗口指针简介访问到右窗口:
	RightWidget *right=pmain->getRightWidget();

	//首先清空右窗口中所有的小球:
	right->clearBalls ();

	//从编辑框中获得文本, 并转化为int, 同时设置私有变量
	bool ok;
	this->level=levelEdit->text ().toUInt (&ok);
	right->setLevel (this->level);

	//向右窗口中添加表情:
	//第一个表情为玩家操控的特殊表情:
	right->addBall(Ball(400,400,20,0,0,"D:/Git/Commodity/QtProject/yinxian.png"));

	//设置随机数种子:
	srand(time(0));
	int x=0,y=0,sp=0, an=0, r=0, ima=0;
	//循环添加作为干扰的表情球和目标表情球:
	for(unsigned int i=0;i<this->level;++i){
		//采用随机数的方式设置各个表情球的参数:
		//同时限制最大和最小参数:
		x=rand()%right->getMinX ();
		y=rand()%right->getMinX ();
		sp=Ball::MIN_SPEED+rand()%(Ball::MAX_SPEED-Ball::MIN_SPEED);
		an=rand()%360;
		r=15+rand()%25;
		//随机设置表情的贴图:
		ima=rand()%(this->imaginList.size ());
		right->addBall (Ball(x,y,r,sp,an,this->imaginList.at (ima)));
	}
	//获取作为目标表情球的最后一个表情球的贴图信息:
	QPixmap temp(right->getLastBall ().getImage ());
	this->targetPicture->setPixmap (temp);

	return ;
}

