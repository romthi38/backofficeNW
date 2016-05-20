/**
 *  @file mainwindow.cpp
 *  @brief Fenêtre de base
 *  @author tromanin
 *  @date vendredi 4 septembre 2015, 09:00:00
 *
 *  Fenêtre de connexion à l'application
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windowmenu.h"
#include <QString>
#include <QMessageBox>

/**
 *  @brief MainWindow::MainWindow
 *  @param parent
 *
 *  Initialisation de l'interface utilisateur.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 *  @brief MainWindow::~MainWindow
 *
 *  Suppression de l'interface utilisateur.
 */

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 *  @brief MainWindow::on_pushButtonAuthentification_clicked
 *  @todo Enlever l'affichage du mot de passe en dur, préférer un passage par une base de données
 *
 *  Cette procédure fait que lorsque l'on clique sur le bouton "S'authentifier".
 *  Il faut remplir les 2 lineEdit avec les bons identifiants pour accéder à l'appli,
 *  sinon on a l'affichage en rouge d'un message d'erreur.
 */

void MainWindow::on_pushButtonAuthentification_clicked()
{
    QString login = ui->lineEditPseudo->text();
    QString passwd = ui->lineEditMdp->text();
    if(login == "admin" && passwd == "admin")
    {
        WindowMenu *allerMenu = new WindowMenu();
        allerMenu->setModal(true);
        allerMenu->show();
        this->close();
    }
    else
    {
        ui->labelError->setText("Erreur d'identification, veuillez réessayer");
    }
}

/**
 *  @brief MainWindow::on_action_Quitter_triggered
 *
 *  Lorsque l'on clique sur "Quitter" dans l'onglet Fichier,
 *  cela ferme l'application.
 */

void MainWindow::on_action_Quitter_triggered()
{
    this->close();
}

/**
 *  @brief MainWindow::on_action_propos_triggered
 *
 *  Lorsque l'on clique sur "à propos" dans l'onglet Fichier,
 *  cela affiche un texte.
 */

void MainWindow::on_action_propos_triggered()
{
    QMessageBox::information(this,"Informations application","Cette application sert à faciliter le back office du site New World pour les employés de l'entreprise.");
}
