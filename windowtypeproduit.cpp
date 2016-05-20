/**
 *  @file windowproduit.cpp
 *  @brief Fenêtre d'ajout, d'affichage, de suppression des types de produits
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *
 *  Fenêtre d'ajout, d'affichage, de suppression des types de produits.
 */

#include "windowtypeproduit.h"
#include "ui_windowtypeproduit.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QtSql/QSqlRecord>
#include <windowmenu.h>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlRelation>
#include <QTableView>
#include <QSqlRelationalDelegate>
#include <QtSql/QSqlQuery>

/**
 *  @brief WindowTypeProduit::WindowTypeProduit
 *  @param parent
 *
 *  C'est ici que sont affichés les types de produits, on prend les données directement dans la BDD.
 */

WindowTypeProduit::WindowTypeProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowTypeProduit)
{
    ui->setupUi(this);
    // Construction de la base
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase = new QSqlDatabase(db);
    maBase->setHostName("**********");
    maBase->setDatabaseName("********");
    maBase->setUserName("**********");
    maBase->setPassword("*********");
    bool ok = maBase->open();
    if(!ok)
    {
        QMessageBox::warning(this,"New World BackOffice", "La connexion à la base de données a échouée\n Veuillez vérifier que le service mysql est lancé sur localhost", QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok);
    }
    else
    {
        modelTypeProduit = new QSqlRelationalTableModel(this,*maBase);
        modelTypeProduit->setTable("TypeProduit");
        ui->tableViewTypeProduit->setModel(modelTypeProduit);        
        modelTypeProduit->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        ui->tableViewTypeProduit->hideColumn(0);
        modelTypeProduit->setRelation(2,QSqlRelation("SurType","no","libelle"));
        modelTypeProduit->select();
        ui->tableViewTypeProduit->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewTypeProduit));
        ui->tableViewTypeProduit->setColumnWidth(1,300);
        ui->tableViewTypeProduit->setColumnWidth(2,300);
        modelTypeProduit->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du type de produit"));
        modelTypeProduit->setHeaderData(2, Qt::Horizontal, trUtf8("Libellé du rayon"));
    }
}

/**
 *  @brief WindowTypeProduit::~WindowTypeProduit
 *
 *  Suppression de l'interface utilisateur.
 */

WindowTypeProduit::~WindowTypeProduit()
{
    delete ui;
}

/**
 *  @brief WindowTypeProduit::on_pushButtonRetour_clicked
 *
 *  Bouton de retour au menu et de fermeture de la fenêtre.
 */

void WindowTypeProduit::on_pushButtonRetour_clicked()
{
    WindowMenu *allerMenu = new WindowMenu();
    allerMenu->setModal(true);
    allerMenu->show();
    this->reject();
}

/**
 *  @brief WindowTypeProduit::on_pushButtonSupprimerTypeProduit_clicked
 *
 *  Bouton de suppression d'un rayon.
 */

void WindowTypeProduit::on_pushButtonSupprimerTypeProduit_clicked()
{
    int ligneTypeProduit = ui->tableViewTypeProduit->currentIndex().row();
    modelTypeProduit->removeRows(ligneTypeProduit,1);
}

/**
 *  @brief WindowTypeProduit::on_pushButtonAjouterTypeProduit_clicked
 *
 *  Bouton d'ajout d'un type de produit.
 */

void WindowTypeProduit::on_pushButtonAjouterTypeProduit_clicked()
{
    QString nomTypeProduit = ui->lineEditTypeProduit->text();
    QSqlRecord recordTypeProduit = modelTypeProduit->record();
    recordTypeProduit.setValue(0,modelTypeProduit->rowCount()+1);
    recordTypeProduit.setValue(1,nomTypeProduit);
    modelTypeProduit->insertRecord(modelTypeProduit->rowCount(), recordTypeProduit);
    ui->lineEditTypeProduit->clear();
}
