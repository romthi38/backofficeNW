/**
 *  @file windowmoderation.h
 *  @brief Classe de WindowModeration
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowModeration
 */

#ifndef WINDOWMODERATION_H
#define WINDOWMODERATION_H

#include <QDialog>

namespace Ui {
class WindowModeration;
}

class WindowModeration : public QDialog
{
    Q_OBJECT
    
public:
    explicit WindowModeration(QWidget *parent = 0);
    ~WindowModeration();
    
private slots:
    void on_pushButtonRetour_clicked();

private:
    Ui::WindowModeration *ui;
};

#endif // WINDOWMODERATION_H
