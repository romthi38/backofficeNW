/**
 *  @file windowrayon.cpp
 *  @brief Fenêtre d'ajout, d'affichage, de suppression des rayons
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *
 *  Fenêtre d'ajout, d'affichage, de suppression des rayons.
 */

#include "windowrayon.h"
#include "ui_windowrayon.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QtSql/QSqlRecord>
#include <QLineEdit>
#include <windowmenu.h>
#include <QSqlQuery>
#include <QCheckBox>

/**
 *  @brief windowRayon::windowRayon
 *  @param parent
 *
 *  C'est ici que sont affichés les rayons, on prend les données directement dans la BDD.
 */

windowRayon::windowRayon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowRayon)
{
    ui->setupUi(this);
    // Construction de la base
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase = new QSqlDatabase(db);
    maBase->setHostName("************");
    maBase->setDatabaseName("************");
    maBase->setUserName("***********");
    maBase->setPassword("*************");
    bool ok = maBase->open();
    if(!ok)
    {
        QMessageBox::warning(this,"New World BackOffice", "La connexion à la base de données a échouée\n Veuillez vérifier que le service mysql est lancé sur localhost", QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok);
    }
    else
    {
        modelRayon = new QSqlTableModel(this,*maBase);
        modelRayon->setTable("SurType");
        modelRayon->setHeaderData(0, Qt::Horizontal, trUtf8("Id du rayon"));
        modelRayon->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du rayon"));
        ui->tableViewRayon->setModel(modelRayon);
        modelRayon->select();
        modelRayon->setEditStrategy(QSqlTableModel::OnFieldChange);
        ui->tableViewRayon->hideColumn(0);
        ui->tableViewRayon->setColumnWidth(1,300);
    }
}

/**
 *  @brief windowRayon::~windowRayon
 *
 *  Suppression de l'interface utilisateur.
 */

windowRayon::~windowRayon()
{
    delete ui;
}

/**
 *  @brief windowRayon::on_pushButtonRetour_clicked
 *
 *  Bouton de retour au menu et de fermeture de la fenêtre.
 */

void windowRayon::on_pushButtonRetour_clicked()
{
    WindowMenu *allerMenu = new WindowMenu();
    allerMenu->setModal(true);
    allerMenu->show();
    this->reject();
}

/**
 *  @brief windowRayon::on_pushButtonAjouterRayon_clicked
 *
 *  Bouton d'ajout d'un rayon.
 */

void windowRayon::on_pushButtonAjouterRayon_clicked()
{
    QString nomRayon = ui->lineEditRayon->text();
    QSqlRecord record = modelRayon->record();
    // L'id n'est pas bon, un rayon doit avoir un nouvel id même quand on ajoute un rayon après avoir supprimé un précédent
    record.setValue(0,modelRayon->rowCount()+1);
    record.setValue(1,nomRayon);
    modelRayon->insertRecord(modelRayon->rowCount(), record);
    ui->lineEditRayon->clear();
}

/**
 *  @brief windowRayon::on_pushButtonSupprimerRayon_clicked
 *
 *  Bouton de suppression d'un rayon.
 */

void windowRayon::on_pushButtonSupprimerRayon_clicked()
{
    int ligne = ui->tableViewRayon->currentIndex().row();
    modelRayon->removeRows(ligne,1);
}
