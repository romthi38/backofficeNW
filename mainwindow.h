/**
 *  @file mainwindow.h
 *  @brief Classe de MainWindow
 *  @author tromanin
 *  @date vendredi 11 septembre 2015, 08:12:00
 *  @class MainWindow
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButtonAuthentification_clicked();

    void on_action_Quitter_triggered();

    void on_action_propos_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
