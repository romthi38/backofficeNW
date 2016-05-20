/**
 *  @file windowtypeproduit.h
 *  @brief Classe de WindowTypeProduit
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowTypeProduit
 */

#ifndef WINDOWTYPEPRODUIT_H
#define WINDOWTYPEPRODUIT_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRelationalTableModel>

namespace Ui {
class WindowTypeProduit;
}

class WindowTypeProduit : public QDialog
{
    Q_OBJECT
    
public:
    explicit WindowTypeProduit(QWidget *parent = 0);
    ~WindowTypeProduit();
    
private slots:
    void on_pushButtonRetour_clicked();

    void on_pushButtonSupprimerTypeProduit_clicked();

    void on_pushButtonAjouterTypeProduit_clicked();

private:
    Ui::WindowTypeProduit *ui;
    QSqlDatabase * maBase;
    QSqlRelationalTableModel * modelTypeProduit;
};

#endif // WINDOWTYPEPRODUIT_H
