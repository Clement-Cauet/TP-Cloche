
//*********************************************************************************************
//* Programme : main.cpp								Date : 30/11/2021
//*														Dernière MAJ : 30/11/2021
//*--------------------------------------------------------------------------------------------
//*Programmeurs :	CAUET Clément							Classe : BTSSN2
//*					DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------
//*
//* BUT : Permet d'ouvrir l'IHM.
//*
//*********************************************************************************************

#include "TPSystemeCloche.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPSystemeCloche w;
    w.show();
    return a.exec();
}
