#include "leftwidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <ctime>
#include "mainwindow.h"

LeftWidget::LeftWidget(QWidget *parent) :
	QWidget(parent)
{
	pmain=(MainWindow *)parent;
//	xLabel=new QLabel(this);
//	xLabel->setText(tr("x 坐标:"));
//	yLabel=new QLabel(this);
//	yLabel->setText(tr("y 坐标:"));
//	radiusLabel=new QLabel(this);
//	radiusLabel->setText(tr("半径:"));
//	speedLabel=new QLabel(this);
//	speedLabel->setText(tr("速度:"));
//	angleLabel=new QLabel(this);
//	angleLabel->setText(tr("角度:"));
//	colorLabel=new QLabel(this);
//	colorLabel->setText(tr("颜色:"));
	levelLabel=new QLabel(this);
	levelLabel->setText (tr("当前球数:"));
	keyPressLabel=new QLabel(this);
	keyPressLabel->setText (tr("按下的按键:"));
	keyPressInfo=new QLabel(this);
	keyPressInfo->setText (tr("初始化"));

//	xEdit=new QLineEdit("100",this);
//	yEdit=new QLineEdit("50",this);
//	radiusEdit=new QLineEdit("10",this);
//	speedEdit=new QLineEdit("5",this);
//	angleEdit=new QLineEdit("40",this);
	levelEdit=new QLineEdit("1",this);


//	addButton=new QPushButton(tr("添加"),this);
	startButton=new QPushButton(tr("开始"),this);
	stopButton=new QPushButton(tr("暂停"),this);

//	colorPreview=new PaintLabel(this);//自定义类
//	colorPreview->setText(tr("       "));  //初始字符串确定控件大小

	QGridLayout *mainLayout=new QGridLayout(this);
//	mainLayout->addWidget(xLabel,0,0);
//	mainLayout->addWidget(xEdit,0,1);
//	mainLayout->addWidget(yLabel,1,0);
//	mainLayout->addWidget(yEdit,1,1);
//	mainLayout->addWidget(radiusLabel,2,0);
//	mainLayout->addWidget(radiusEdit,2,1);
//	mainLayout->addWidget(speedLabel,3,0);
//	mainLayout->addWidget(speedEdit,3,1);
//	mainLayout->addWidget(angleLabel,4,0);
//	mainLayout->addWidget(angleEdit,4,1);
//	mainLayout->addWidget(colorLabel,5,0);
//	mainLayout->addWidget(colorPreview,5,1);
//	mainLayout->addWidget(addButton,6,0);
	mainLayout->addWidget (levelLabel,0,0);
	mainLayout->addWidget (levelEdit,0,1);
	mainLayout->addWidget (startButton,1,0);
	mainLayout->addWidget (stopButton,1,1);
	mainLayout->addWidget (keyPressLabel,2,0);
	mainLayout->addWidget (keyPressInfo,2,1);
	setLayout(mainLayout);

//	connect(addButton,SIGNAL(clicked()),this,SLOT(addBall()));
	connect(startButton, SIGNAL(clicked()),this,SLOT(startGame()));
	connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));
	//实现按钮点击事件的槽方法

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

	return ;
}

void LeftWidget::keyPressEvent(QKeyEvent *e)
{
	RightWidget *right=pmain->getRightWidget();
	this->KeyPressNum=QString::number(e->key());
	this->keyPressInfo->setText (KeyPressNum);
	right->moveBall (e->key ());
	return ;
}

void LeftWidget::stopBall(){
	if(stopButton->text()==tr("暂停")){
		pmain->StopTimer();
		stopButton->setText(tr("开始"));
	}
	else{
		pmain->resumeTimer();
		stopButton->setText(tr("暂停"));
	}
}

void LeftWidget::startGame()
{
//todo:
	qDebug() <<"Start Game\n";
	RightWidget *right=pmain->getRightWidget();
	right->clearBalls ();

	bool ok;
	this->level=levelEdit->text ().toUInt (&ok);
	right->setLevel (this->level);

	right->addBall(Ball(400,400,20,0,0,"D:/Git/Commodity/QtProject/yinxian.png"));
	srand(time(0));
	int x=0,y=0,sp=0, an=0, r=0, ima=0;
	for(unsigned int i=0;i+1<this->level;++i){
		x=rand()%right->getMinX ();
		y=rand()%right->getMinX ();
		sp=Ball::MIN_SPEED+rand()%(Ball::MAX_SPEED-Ball::MIN_SPEED);
		an=rand()%360;
		r=15+rand()%25;
		ima=rand()%(this->imaginList.size ());
		right->addBall (Ball(x,y,r,sp,an,this->imaginList.at (ima)));
	}
	right->addBall(Ball(30,20,30,Ball::MAX_SPEED,49,"D:/Git/Commodity/QtProject/weiqu.png"));
	return ;
}

//实现按钮点击事件的槽方法
