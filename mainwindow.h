#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cuerpo.h"
#include "pared.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <moneda.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    cuerpo *personaje;
    QList<pared *> paredes;
    QList<moneda *> galleta;
    QList<moneda *> monedas;
    QGraphicsScene *scene;

    void keyPressEvent(QKeyEvent * evento);

};
#endif // MAINWINDOW_H
