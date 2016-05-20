/**
 *  @file windowmoderation.cpp
 *  @brief Fenêtre de modération
 *  @author tromanin
 *  @date vendredi 4 septembre 2015, 09:00:00
 *  @todo Fenêtre à faire, permettre de valider les ajouts et une fois validés les mettre dans la BDD.
 *
 *  Fenêtre de modération.
 */

#include "windowmoderation.h"
#include "ui_windowmoderation.h"
#include <windowmenu.h>

/**
 *  @brief WindowMenu::WindowMenu
 *  @param parent
 *
 *  Initialisation de l'interface utilisateur.
 */

WindowModeration::WindowModeration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowModeration)
{
    ui->setupUi(this);
}

/**
 *  @brief WindowModeration::~WindowModeration
 *
 *  Suppression de l'interface utilisateur.
 */

WindowModeration::~WindowModeration()
{
    delete ui;
}

/**
 *  @brief WindowModeration::on_pushButtonRetour_clicked
 *
 *  Bouton de retour au menu et de fermeture de la fenêtre.
 */

void WindowModeration::on_pushButtonRetour_clicked()
{
    WindowMenu *allerMenu = new WindowMenu();
    allerMenu->setModal(true);
    allerMenu->show();
    this->reject();
}
