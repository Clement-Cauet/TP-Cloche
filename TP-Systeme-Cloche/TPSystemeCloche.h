#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TPSystemeCloche.h"
#include <qtcpsocket.h>
#include <qdebug.h>
#include <QTimer>
#include <QRandomGenerator>

class TPSystemeCloche : public QMainWindow
{
    Q_OBJECT

public:
    TPSystemeCloche(QWidget *parent = Q_NULLPTR);

private:
    Ui::TPSystemeClocheClass ui;
	QTcpSocket * socket;
	QTimer *timer1;
	QTimer *timer2;

public slots:
	void connexion();
	void disconnexion();
	void clavierChange();
	void cloche1();
	void cloche2();
	void cloche3();
	void cloche4();
	void songOn();
	void songOff();
	void song();
};
