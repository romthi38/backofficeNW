/**
 *  @file windowproduit.cpp
 *  @brief Fenêtre d'ajout, d'affichage, de suppression des produits
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *
 *  Fenêtre d'ajout, d'affichage, de suppression des produits.
 */

#include "windowproduit.h"
#include "ui_windowproduit.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QtSql/QSqlRecord>
#include <windowmenu.h>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlRelation>
#include <QTableView>
#include <QSqlRelationalDelegate>

/**
 *  @brief WindowProduit::WindowProduit
 *  @param parent
 *
 *  C'est ici que sont affichés les produits, on prend les données directement dans la BDD.
 */

WindowProduit::WindowProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowProduit)
{
    ui->setupUi(this);
    // Construction de la base
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase = new QSqlDatabase(db);
    maBase->setHostName("***********");
    maBase->setDatabaseName("**********");
    maBase->setUserName("***********");
    maBase->setPassword("***********");
    bool ok = maBase->open();
    if(!ok)
    {
        QMessageBox::warning(this,"New World BackOffice", "La connexion à la base de données a échouée\n Veuillez vérifier que le service mysql est lancé sur localhost", QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Ok);
    }
    else
    {
        modelProduit = new QSqlRelationalTableModel(this,*maBase);
        modelProduit->setTable("Produit");
        ui->tableViewProduit->setModel(modelProduit);
        modelProduit->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        ui->tableViewProduit->hideColumn(0);
        modelProduit->setRelation(2,QSqlRelation("TypeProduit","no","libelle"));
        modelProduit->select();
        ui->tableViewProduit->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewProduit));
        ui->tableViewProduit->setColumnWidth(1,300);
        ui->tableViewProduit->setColumnWidth(2,300);
        modelProduit->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du produit"));
        modelProduit->setHeaderData(2, Qt::Horizontal, trUtf8("Libellé du type de produit"));
    }
}

/**
 *  @brief WindowProduit::~WindowProduit
 *
 *  Suppression de l'interface utilisateur.
 */

WindowProduit::~WindowProduit()
{
    delete ui;
}

/**
 *  @brief WindowProduit::on_pushButtonRetour_clicked
 *
 *  Bouton de retour au menu et de fermeture de la fenêtre.
 */

void WindowProduit::on_pushButtonRetour_clicked()
{
    WindowMenu *allerMenu = new WindowMenu();
    allerMenu->setModal(true);
    allerMenu->show();
    this->reject();
}

/**
 *  @brief WindowProduit::on_pushButtonSupprimerProduit_clicked
 *
 *  Bouton de suppression d'un produit.
 */

void WindowProduit::on_pushButtonSupprimerProduit_clicked()
{
    int ligneProduit = ui->tableViewProduit->currentIndex().row();
    modelProduit->removeRows(ligneProduit,1);
}

/**
 *  @brief WindowProduit::on_pushButtonAjouterProduit_clicked
 *
 *  Bouton d'ajout d'un produit.
 */

void WindowProduit::on_pushButtonAjouterProduit_clicked()
{
    QString nomProduit = ui->lineEditProduit->text();
    QSqlRecord recordProduit = modelProduit->record();
    recordProduit.setValue(0,modelProduit->rowCount()+1);
    recordProduit.setValue(1,nomProduit);
    modelProduit->insertRecord(modelProduit->rowCount(), recordProduit);
    ui->lineEditProduit->clear();
}
