/**
 *  @file windowapercu.cpp
 *  @brief Fenêtre d'aperçu
 *  @author tromanin
 *  @date vendredi 4 septembre 2015, 09:00:00
 *
 *  Fenêtre d'aperçu des rayons, des types de produits et des produits présents dans la BDD.
 */

#include "windowapercu.h"
#include "ui_windowapercu.h"
#include <windowmenu.h>
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
 *  @brief WindowApercu::WindowApercu
 *  @param parent
 *
 *  Connexion à la base de données,
 *  si la connexion échoue, un message d'erreur est renvoyé,
 *  sinon on éxecute le SQL.
 *  Il y a donc la récupération des champs, des noms des colonnes.
 *  Tout est mis sous forme de 3 tableaux pour chaque table.
 */

WindowApercu::WindowApercu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WindowApercu)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase = new QSqlDatabase(db);
    maBase->setHostName("**********");
    maBase->setDatabaseName("**********");
    maBase->setUserName("************");
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
        modelTypeProduit = new QSqlRelationalTableModel(this,*maBase);
        modelTypeProduit->setTable("TypeProduit");
        ui->tableViewTypeProduit->setModel(modelTypeProduit);
        modelTypeProduit->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        ui->tableViewTypeProduit->hideColumn(0);
        modelTypeProduit->setRelation(2,QSqlRelation("SurType","no","libelle"));
        modelTypeProduit->select();
        ui->tableViewTypeProduit->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewTypeProduit));
        modelRayon = new QSqlTableModel(this,*maBase);
        modelRayon->setTable("SurType");
        modelRayon->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du rayon"));
        modelProduit->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du produit"));
        modelProduit->setHeaderData(2, Qt::Horizontal, trUtf8("Libellé du type de produit"));
        modelTypeProduit->setHeaderData(1, Qt::Horizontal, trUtf8("Libellé du type de produit"));
        modelTypeProduit->setHeaderData(2, Qt::Horizontal, trUtf8("Libellé du rayon"));
        ui->tableViewProduit->setColumnWidth(1,300);
        ui->tableViewProduit->setColumnWidth(2,300);
        ui->tableViewTypeProduit->setColumnWidth(1,300);
        ui->tableViewTypeProduit->setColumnWidth(2,300);
        ui->tableViewRayon->setModel(modelRayon);
        modelRayon->select();
        modelRayon->setEditStrategy(QSqlTableModel::OnFieldChange);
        ui->tableViewRayon->hideColumn(0);
        ui->tableViewRayon->setColumnWidth(1,300);
    }
}

/**
 *  @brief WindowApercu::~WindowApercu
 *
 *  Suppression de l'interface utilisateur.
 */

WindowApercu::~WindowApercu()
{
    delete ui;
}

/**
 *  @brief WindowApercu::on_pushButtonRetour_clicked
 *
 *  Bouton de retour au menu et de fermeture de la fenêtre.
 */

void WindowApercu::on_pushButtonRetour_clicked()
{
    WindowMenu *allerMenu = new WindowMenu();
    allerMenu->setModal(true);
    allerMenu->show();
    this->close();
}
