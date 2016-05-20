/**
 *  @file windowapercu.h
 *  @brief Classe de WindowApercu
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowApercu
 */

#ifndef WINDOWAPERCU_H
#define WINDOWAPERCU_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRelationalTableModel>

namespace Ui {
class WindowApercu;
}

class WindowApercu : public QDialog
{
    Q_OBJECT
    
public:
    explicit WindowApercu(QWidget *parent = 0);
    ~WindowApercu();
    
private slots:
    void on_pushButtonRetour_clicked();

private:
    Ui::WindowApercu *ui;
    QSqlDatabase * maBase;
    QSqlTableModel * modelRayon;
    QSqlRelationalTableModel * modelProduit;
    QSqlRelationalTableModel * modelTypeProduit;
};

#endif // WINDOWAPERCU_H
