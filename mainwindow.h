﻿#ifndef MAINWINDOW_H
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
	~MainWindow(){}
private:
	CenterWidget *centerWidget;

	QMenu *fileMenu;
	QMenu *drawMenu;
	QMenu *colorMenu;
	QMenu *fillMenu;

	QAction *exitAction;
	QAction *lineAction;
	QAction *ellipseAction;
	QAction *rectangleAction;
	QAction *blackAction;
	QAction *greenAction;
	QAction *yellowAction;
	QAction *fillAction;

	QToolBar *drawToolBar;
protected slots:
	void line();
	void ellipse();
	void rectangle();
	void reDrawInBlack();
	void reDrawInGreen();
	void reDrawInYellow();
	void fillColor();
};

#endif // MAINWINDOW_H
