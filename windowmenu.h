/**
 *  @file windowmenu.h
 *  @brief Classe de WindowMenu
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class WindowMenu
 */

#ifndef WINDOWMENU_H
#define WINDOWMENU_H

#include <QDialog>

namespace Ui {
class WindowMenu;
}

class WindowMenu : public QDialog
{
    Q_OBJECT
    
public:
    explicit WindowMenu(QWidget *parent = 0);
    ~WindowMenu();
    
private slots:
    void on_pushButtonDeconnexion_clicked();

    void on_pushButtonRayon_clicked();

    void on_pushButtonTypeProduit_clicked();

    void on_pushButtonProduit_clicked();

    void on_pushButtonModeration_clicked();

    void on_pushButtonApercu_clicked();

private:
    Ui::WindowMenu *ui;
};

#endif // WINDOWMENU_H
