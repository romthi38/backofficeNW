/**
 *  @file main.cpp
 *  @brief Fichier principal du projet
 *  @author tromanin
 *  @date vendredi 4 septembre 2015, 09:00:00
 */

/* Documentation tag for Doxygen
 */

/**
 * @mainpage Documentation Back Office New World
 *
 * @section intro_sec Introduction
 *
 * Ceci est la documentation de l'application générée par Doxygen.
 *
 * @section Copyright T.Romanin
 *
 * <BR><BR>
 *
 */

#include <QApplication>
#include "mainwindow.h"

/**
 *  @brief main est obligatoire dans tout programme C++
 *  @fn fonction main
 *  @param argc
 *  @param argv
 *  @return Renvoie a.exec()
 *
 *  Permet de lancer la MainWindow, si il n'y a pas de retour de cette fonction,
 *  alors par défaut 0 sera retourné.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    
    return a.exec();
}
