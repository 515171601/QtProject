#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "centerwidget.h"
#include <QMainWindow>
#include<QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();
private:
	CenterWidget *centerWidget; //定义私有指针.

	QMenu *fileMenu;
	QMenu *drawMenu;
	QAction *exitAction;
	QAction *lineAction;
	QAction *ellipseAction;
	QAction *rectangleAction;
	QToolBar *drawToolBar;
protected slots:
	void line();
	void ellipse();
	void rectangle();
};

#endif // MAINWINDOW_H
