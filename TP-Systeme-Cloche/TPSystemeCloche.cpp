//*********************************************************************************************
//* Programme : TPSytemeCloche.cpp								Date : 30/11/2021
//*														Dernière MAJ : 30/11/2021
//*--------------------------------------------------------------------------------------------
//*Programmeurs :	CAUET Clément							Classe : BTSSN2
//*					DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------
//*
//* BUT : Envoyer des trames à la carte ETZ510 pour faire sonner les cloches
//*
//*********************************************************************************************

#include "TPSystemeCloche.h"

TPSystemeCloche::TPSystemeCloche(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	socket = new QTcpSocket();
	ui.disconnectButton->setEnabled(false);
	ui.clavierEdit->setEnabled(false);
	ui.cloche1Button->setEnabled(false);
	ui.cloche2Button->setEnabled(false);
	ui.cloche3Button->setEnabled(false);
	ui.cloche4Button->setEnabled(false);
	ui.songOn->setEnabled(false);

	ui.widgetHistorique->clear();
}

/* Connexion au serveur TCP/IP */
void TPSystemeCloche::connexion() 
{
	if (ui.ipEdit->text().size() > 0 && ui.portEdit->text().size() > 0) {
		QString ip = ui.ipEdit->text();
		int port = ui.portEdit->text().toInt();
		socket->connectToHost(ip, port);

		ui.ipEdit->setEnabled(false);
		ui.portEdit->setEnabled(false);
		ui.connectButton->setEnabled(false);
		ui.disconnectButton->setEnabled(true);
		ui.clavierEdit->setEnabled(true);
		ui.cloche1Button->setEnabled(true);
		ui.cloche2Button->setEnabled(true);
		ui.cloche3Button->setEnabled(true);
		ui.cloche4Button->setEnabled(true);
		ui.songOn->setEnabled(true);

		ui.widgetHistorique->addItem("Connexion etablie");		
	}
}

/* Déconnexion du serveur TCP/IP */
void TPSystemeCloche::disconnexion()
{
	socket->disconnectFromHost();

	ui.connectButton->setEnabled(true);
	ui.ipEdit->setEnabled(true);
	ui.portEdit->setEnabled(true);
	ui.disconnectButton->setEnabled(false);
	ui.clavierEdit->setEnabled(false);
	ui.cloche1Button->setEnabled(false);
	ui.cloche2Button->setEnabled(false);
	ui.cloche3Button->setEnabled(false);
	ui.cloche4Button->setEnabled(false);
	ui.songOn->setEnabled(false);

	ui.widgetHistorique->addItem("Deconnexion");
}

/* Controle des cloches avec le clavier */
void TPSystemeCloche::clavierChange()
{
	QString clavierEdit = ui.clavierEdit->text();
	if (clavierEdit == "1") {
		cloche1();
	}
	else if (clavierEdit == "2") {
		cloche2();
	}
	else if (clavierEdit == "3") {
		cloche3();
	}
	else if (clavierEdit == "4") {
		cloche4();
	}
	ui.clavierEdit->clear();
}

/* Trame gestion de la cloche 1 */
void TPSystemeCloche::cloche1()
{
	/* Activation du marteau pour faire sonner la cloche 1 */
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char Cloche1On[12];
		Cloche1On[0] = 0x00;
		Cloche1On[1] = 0x01;
		Cloche1On[2] = 0x00;
		Cloche1On[3] = 0x00;
		Cloche1On[4] = 0x00;
		Cloche1On[5] = 0x06;
		Cloche1On[6] = 0x11;
		Cloche1On[7] = 0x06;
		Cloche1On[8] = 0x00;
		Cloche1On[9] = 0x02;
		Cloche1On[10] = 0x00;
		Cloche1On[11] = 0x01;

		/* Envoie de la trame */
		QByteArray dataOn(Cloche1On, 12);
		socket->write(dataOn);

		/* Relachement du marteau */
		char Cloche1Off[12];
		Cloche1Off[0] = 0x00;
		Cloche1Off[1] = 0x01;
		Cloche1Off[2] = 0x00;
		Cloche1Off[3] = 0x00;
		Cloche1Off[4] = 0x00;
		Cloche1Off[5] = 0x06;
		Cloche1Off[6] = 0x11;
		Cloche1Off[7] = 0x06;
		Cloche1Off[8] = 0x00;
		Cloche1Off[9] = 0x02;
		Cloche1Off[10] = 0x00;
		Cloche1Off[11] = 0x00;

		/* Envoie de la trame */
		QByteArray dataOff(Cloche1Off, 12);
		socket->write(dataOff);

		ui.widgetHistorique->addItem("Cloche 1 active");
	}
}

/* Trame gestion de la cloche 2 */
void TPSystemeCloche::cloche2()
{
	/* Activation du marteau pour faire sonner la cloche 2 */
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char Cloche2On[12];
		Cloche2On[0] = 0x00;
		Cloche2On[1] = 0x01;
		Cloche2On[2] = 0x00;
		Cloche2On[3] = 0x00;
		Cloche2On[4] = 0x00;
		Cloche2On[5] = 0x06;
		Cloche2On[6] = 0x11;
		Cloche2On[7] = 0x06;
		Cloche2On[8] = 0x00;
		Cloche2On[9] = 0x02;
		Cloche2On[10] = 0x00;
		Cloche2On[11] = 0x02;

		/* Envoie de la trame */
		QByteArray dataOn(Cloche2On, 12);
		socket->write(dataOn);

		/* Relachement du marteau */
		char Cloche2Off[12];
		Cloche2Off[0] = 0x00;
		Cloche2Off[1] = 0x01;
		Cloche2Off[2] = 0x00;
		Cloche2Off[3] = 0x00;
		Cloche2Off[4] = 0x00;
		Cloche2Off[5] = 0x06;
		Cloche2Off[6] = 0x11;
		Cloche2Off[7] = 0x06;
		Cloche2Off[8] = 0x00;
		Cloche2Off[9] = 0x02;
		Cloche2Off[10] = 0x00;
		Cloche2Off[11] = 0x00;

		/* Envoie de la trame */
		QByteArray dataOff(Cloche2Off, 12);
		socket->write(dataOff);

		ui.widgetHistorique->addItem("Cloche 2 active");
	}
}

/* Trame gestion de la cloche 3 */
void TPSystemeCloche::cloche3()
{
	/* Activation du marteau pour faire sonner la cloche 3 */
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char Cloche3On[12];
		Cloche3On[0] = 0x00;
		Cloche3On[1] = 0x01;
		Cloche3On[2] = 0x00;
		Cloche3On[3] = 0x00;
		Cloche3On[4] = 0x00;
		Cloche3On[5] = 0x06;
		Cloche3On[6] = 0x11;
		Cloche3On[7] = 0x06;
		Cloche3On[8] = 0x00;
		Cloche3On[9] = 0x02;
		Cloche3On[10] = 0x00;
		Cloche3On[11] = 0x04;

		/* Envoie de la trame */
		QByteArray dataOn(Cloche3On, 12);
		socket->write(dataOn);

		/* Relachement du marteau */
		char Cloche3Off[12];
		Cloche3Off[0] = 0x00;
		Cloche3Off[1] = 0x01;
		Cloche3Off[2] = 0x00;
		Cloche3Off[3] = 0x00;
		Cloche3Off[4] = 0x00;
		Cloche3Off[5] = 0x06;
		Cloche3Off[6] = 0x11;
		Cloche3Off[7] = 0x06;
		Cloche3Off[8] = 0x00;
		Cloche3Off[9] = 0x02;
		Cloche3Off[10] = 0x00;
		Cloche3Off[11] = 0x00;

		/* Envoie de la trame */
		QByteArray dataOff(Cloche3Off, 12);
		socket->write(dataOff);

		ui.widgetHistorique->addItem("Cloche 3 active");
	}
}

/* Trame gestion de la cloche 4 */
void TPSystemeCloche::cloche4()
{
	/* Activation du marteau pour faire sonner la cloche 4 */
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char Cloche4On[12];
		Cloche4On[0] = 0x00;
		Cloche4On[1] = 0x01;
		Cloche4On[2] = 0x00;
		Cloche4On[3] = 0x00;
		Cloche4On[4] = 0x00;
		Cloche4On[5] = 0x06;
		Cloche4On[6] = 0x11;
		Cloche4On[7] = 0x06;
		Cloche4On[8] = 0x00;
		Cloche4On[9] = 0x02;
		Cloche4On[10] = 0x00;
		Cloche4On[11] = 0x08;

		/* Envoie de la trame */
		QByteArray dataOn(Cloche4On, 12);
		socket->write(dataOn);

		/* Relachement du marteau */
		char Cloche4Off[12];
		Cloche4Off[0] = 0x00;
		Cloche4Off[1] = 0x01;
		Cloche4Off[2] = 0x00;
		Cloche4Off[3] = 0x00;
		Cloche4Off[4] = 0x00;
		Cloche4Off[5] = 0x06;
		Cloche4Off[6] = 0x11;
		Cloche4Off[7] = 0x06;
		Cloche4Off[8] = 0x00;
		Cloche4Off[9] = 0x02;
		Cloche4Off[10] = 0x00;
		Cloche4Off[11] = 0x00;

		/* Envoie de la trame */
		QByteArray dataOff(Cloche4Off, 12);
		socket->write(dataOff);

		ui.widgetHistorique->addItem("Cloche 4 active");
	}
}

/* Démarrage de la douce mélodie */
void TPSystemeCloche::songOn()
{
	timer1 = new QTimer(this);
	QObject::connect(timer1, SIGNAL(timeout()), this, SLOT(song()));

	timer2 = new QTimer(this);
	QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(songOff()));

	timer1->start(1000);
	timer2->start(5000);

}

/* Arrêt de la douce mélodie */
void TPSystemeCloche::songOff()
{
	QObject::disconnect(timer1, SIGNAL(timeout()), this, SLOT(song()));
	QObject::disconnect(timer2, SIGNAL(timeout()), this, SLOT(songOff()));
}

/* Appelle aléatoire des fonctions des différentes cloches */
void TPSystemeCloche::song()
{
	int rand = QRandomGenerator::global()->bounded(1, 4);

	if (rand == 1) {
		cloche1();
	}
	else if (rand == 2) {
		cloche2();
	}
	else if (rand == 3) {
		cloche3();
	}
	else if (rand == 4) {
		cloche4();
	}
}
