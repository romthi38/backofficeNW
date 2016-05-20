/**
 *  @file windowmenu.cpp
 *  @brief Fenêtre de menu
 *  @author tromanin
 *  @date vendredi 4 septembre 2015, 09:00:00
 *
 *  On apparait sur cette fenêtre après s'être authentifié,
 *  c'est un menu de navigation pour aller sur chaque fenêtres.
 */

#include "windowmenu.h"
#include "ui_windowmenu.h"
#include <QPushButton>
#include <windowrayon.h>
#include <windowtypeproduit.h>
#include <windowmoderation.h>
#include <windowproduit.h>
#include <windowapercu.h>
#include <mainwindow.h>

/**
 *  @brief WindowMenu::WindowMenu
 *  @param parent
 *
 *  Initialisation de l'interface utilisateur.
 */

WindowMenu::WindowMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowMenu)
{
    ui->setupUi(this);
    ui->pushButtonModeration->hide();
}

/**
 *  @brief WindowMenu::~WindowMenu
 *
 *  Suppression de l'interface utilisateur.
 */

WindowMenu::~WindowMenu()
{
    delete ui;
}

/**
 *  @brief WindowMenu::on_pushButtonDeconnexion_clicked
 *
 *  Permet de se déconnecter,
 *  Renvoie à la fenêtre d'authentification, ferme le menu.
 */

void WindowMenu::on_pushButtonDeconnexion_clicked()
{
    MainWindow *allerAuthentification = new MainWindow();
    allerAuthentification->show();
    this->reject();
}

/**
 *  @brief WindowMenu::on_pushButtonRayon_clicked
 *
 *  Ouvre la fenêtre d'ajout des rayons, ferme le menu.
 */

void WindowMenu::on_pushButtonRayon_clicked()
{
    windowRayon *allerRayon = new windowRayon();
    allerRayon->setModal(true);
    allerRayon->show();
    this->reject();
}

/**
 *  @brief WindowMenu::on_pushButtonTypeProduit_clicked
 *
 *  Ouvre la fenêtre d'ajout des types de produits, ferme le menu.
 */

void WindowMenu::on_pushButtonTypeProduit_clicked()
{
    WindowTypeProduit *allerTypeProduit = new WindowTypeProduit();
    allerTypeProduit->setModal(true);
    allerTypeProduit->show();
    this->reject();
}

/**
 *  @brief WindowMenu::on_pushButtonProduit_clicked
 *
 *  Ouvre la fenêtre d'ajout des produits, ferme le menu.
 */

void WindowMenu::on_pushButtonProduit_clicked()
{
    WindowProduit *allerProduit = new WindowProduit();
    allerProduit->setModal(true);
    allerProduit->show();
    this->reject();
}

/**
 *  @brief WindowMenu::on_pushButtonModeration_clicked
 *
 *  Ouvre la fenêtre de modération, ferme le menu.
 */

void WindowMenu::on_pushButtonModeration_clicked()
{
    WindowModeration *allerModeration = new WindowModeration();
    allerModeration->setModal(true);
    allerModeration->show();
    this->reject();
}

/**
 *  @brief WindowMenu::on_pushButtonApercu_clicked
 *
 *  Ouvre la fenêtre d'aperçu, ferme le menu.
 */

void WindowMenu::on_pushButtonApercu_clicked()
{
    WindowApercu *allerApercu = new WindowApercu();
    allerApercu->setModal(true);
    allerApercu->show();
    this->reject();
}
