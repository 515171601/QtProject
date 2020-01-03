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

	levelLabel=new QLabel(this);
	levelLabel->setText (tr("当前球数:"));
	keyPressLabel=new QLabel(this);
	keyPressLabel->setText (tr("按下的按键:"));
	keyPressInfo=new QLabel(this);
	keyPressInfo->setText (tr("初始化"));
	targetLabel=new QLabel(this);
	targetLabel->setText (tr("目标:"));
	targetPicture=new QLabel(this);


	levelEdit=new QLineEdit("1",this);


	startButton=new QPushButton(tr("开始"),this);
	stopButton=new QPushButton(tr("暂停"),this);

	QGridLayout *mainLayout=new QGridLayout(this);
	mainLayout->addWidget (levelLabel,0,0);
	mainLayout->addWidget (levelEdit,0,1);
	mainLayout->addWidget (startButton,1,0);
	mainLayout->addWidget (stopButton,1,1);
	mainLayout->addWidget (keyPressLabel,2,0);
	mainLayout->addWidget (keyPressInfo,2,1);
	mainLayout->addWidget (targetLabel,3,0);
	mainLayout->addWidget (targetPicture,3,1);
	setLayout(mainLayout);

	connect(startButton, SIGNAL(clicked()),this,SLOT(startGame()));
	connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));

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
//变更循环次数:
	for(unsigned int i=0;i<this->level;++i){
		x=rand()%right->getMinX ();
		y=rand()%right->getMinX ();
		sp=Ball::MIN_SPEED+rand()%(Ball::MAX_SPEED-Ball::MIN_SPEED);
		an=rand()%360;
		r=15+rand()%25;
		ima=rand()%(this->imaginList.size ());
		right->addBall (Ball(x,y,r,sp,an,this->imaginList.at (ima)));
	}
//	right->addBall(Ball(30,20,30,Ball::MAX_SPEED,49,"D:/Git/Commodity/QtProject/weiqu.png"));
	QPixmap temp(right->getLastBall ().getImage ());
	this->targetPicture->setPixmap (temp);
//	mainLayout->addWidget (targetPicture,3,1);
//	setLayout(mainLayout);
	return ;
}

