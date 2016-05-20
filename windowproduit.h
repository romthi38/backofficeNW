/**
 *  @file windowproduit.h
 *  @brief Classe de WindowProduit
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowProduit
 */

#ifndef WINDOWPRODUIT_H
#define WINDOWPRODUIT_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>

namespace Ui {
class WindowProduit;
}

class WindowProduit : public QDialog
{
    Q_OBJECT
    
public:
    explicit WindowProduit(QWidget *parent = 0);
    ~WindowProduit();
    
private slots:
    void on_pushButtonRetour_clicked();

    void on_pushButtonSupprimerProduit_clicked();

    void on_pushButtonAjouterProduit_clicked();

private:
    Ui::WindowProduit *ui;
    QSqlDatabase * maBase;
    QSqlRelationalTableModel * modelProduit;
};

#endif // WINDOWPRODUIT_H
