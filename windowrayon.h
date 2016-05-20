/**
 *  @file windowrayon.h
 *  @brief Classe de WindowRayon
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowRayon
 */

#ifndef WINDOWRAYON_H
#define WINDOWRAYON_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

namespace Ui {
class windowRayon;
}

class windowRayon : public QDialog
{
    Q_OBJECT
    
public:
    explicit windowRayon(QWidget *parent = 0);
    ~windowRayon();
    
private slots:
    void on_pushButtonRetour_clicked();

    void on_pushButtonAjouterRayon_clicked();

    void on_pushButtonSupprimerRayon_clicked();

private:
    Ui::windowRayon *ui;
    QSqlDatabase * maBase;
    QSqlTableModel * modelRayon;
};

#endif // WINDOWRAYON_H
