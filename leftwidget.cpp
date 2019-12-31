#include "leftwidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QEvent>
#include <QPainter>
#include <QString>
#include <QDebug>
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
	levelLabel->setText (tr("当前难度:"));
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

	return ;
}

void LeftWidget::keyPressEvent(QKeyEvent *e)
{
	RightWidget *right=pmain->getRightWidget();
	this->KeyPressNum=tr("Key Press : ")+QString::number(e->key());
	this->keyPressInfo->setText (KeyPressNum);
	right->moveBall (e->key ());
	return ;
}

//void LeftWidget::addBall(){
//	//pmain 是指向主窗口的指针，通过其接口 getRightWidget 获得
//	//右侧窗口指针，再调用 right 的addBall 接口添加小球
//	RightWidget *right=pmain->getRightWidget();
//	double x,y;
//	double radius,angle,speed;
//	QColor fillColor;
//	bool ok;
//	x=xEdit->text().toDouble(&ok);
//	y=yEdit->text().toDouble(&ok);
//	radius=radiusEdit->text().toDouble(&ok);
//	speed=speedEdit->text().toDouble(&ok);
//	angle=angleEdit->text().toDouble(&ok);
//	fillColor=colorPreview->getFillColor();
//	right->addBall(Ball(x,y,radius,speed,angle));//迂回的办法.
//}

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
	for(unsigned int i=0;i+1<this->level;++i){
		right->addBall (Ball(5*i,5*i,20,15,30));
	}
	right->addBall(Ball(30,20,30,10,49,"D:/Git/Commodity/QtProject/jingku.png"));
	return ;
}

//实现按钮点击事件的槽方法
