#include "mainwindow.h"
//实例化
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	setWindowTitle("Game");//标题
    splitter=new QSplitter(Qt::Horizontal,this);  //水平切分,水平分割，将来可以嵌套分割。
    left=new LeftWidget(this);//实例化左右窗体
    right=new RightWidget(this);

    splitter->addWidget(left);//把窗体添加到分割中
    splitter->addWidget(right);

    splitter->setStretchFactor(0,1);  //设置切分的默认比例，1:4
    splitter->setStretchFactor(1,4);  //第一个窗格比例是1，第二个是4.
    splitter->setStyleSheet("QSplitter::handle { background-color: gray }"); //setStyleSheet,类似网页样式表，不深究。把分割器背景颜色设置为灰色.
    splitter->setHandleWidth(10);  //设置分割条的大小和样式

    this->setCentralWidget(splitter);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeToShow()));//绑定定时器中的timeout事件到槽方法timeToShow()
	timer->start(this->TIMEOUT);
}

MainWindow::~MainWindow()
{

}
void MainWindow::timeToShow(){//处理定时器
	right->updateBalls();//调用rightwidget中定义的更新球。各自有各自的职责。
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	QPixmap  pixmap = QPixmap("D:/Git/Commodity/QtProject/background.jpg").scaled(this->size());//pixmap对象
	QPainter painter(this);
	painter.drawPixmap(this->rect(), pixmap);//绘制
	return ;
}
void MainWindow::StopTimer(){
    timer->stop();
}
void MainWindow::resumeTimer(){
	timer->start(this->TIMEOUT);
}
