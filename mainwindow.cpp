#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cuerpo.h>
#include <moneda.h>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,540,600);
    personaje = new cuerpo(20,20,20);
    scene->setBackgroundBrush(Qt::black);
    //lado Izquierd0
    {
    paredes.append(new pared(20,220,20,20));//left up
    paredes.append(new pared(20,240,20,-360));//left down

    paredes.append(new pared(100,20,0,-180));  // -
    paredes.append(new pared(20,60,-80,-200)); // |
    paredes.append(new pared(120,20,20,-240)); // -

    paredes.append(new pared(140,20,40,-300)); // -
    paredes.append(new pared(20,60,-80,-320)); // |
    paredes.append(new pared(80,20,0,-360));   // -
    //fin izquierda
    //cajas de la derecha
    paredes.append(new pared(20,220,-540,20));//right up
    paredes.append(new pared(20,240,-540,-360));//left down

    paredes.append(new pared(100,20,-440,-180));  // -
    paredes.append(new pared(20,60,-440,-200)); // |
    paredes.append(new pared(120,20,-460,-240)); // -

    paredes.append(new pared(140,20,-440,-300)); // -
    paredes.append(new pared(20,60,-440,-320)); // |
    paredes.append(new pared(80,20,-460,-360));   // -

    paredes.append(new pared(580,20,20,20));//up
    paredes.append(new pared(580,20,20,-600));//up
    //fin derecha
    paredes.append(new pared(20,100,-260,20));//up center
    //cajas superiores
    paredes.append(new pared(60,40,-40,-40));//left box up
    paredes.append(new pared(60,20,-40,-120));//sub left

    paredes.append(new pared(80,40,-140,-40));//left box up_2
    paredes.append(new pared(80,40,-140,-40));//middle

    paredes.append(new pared(60,40,-440,-40));//right box up
    paredes.append(new pared(80,40,-320,-40));//right box up_2
    paredes.append(new pared(60,20,-440,-120));//sub right

    paredes.append(new pared(140,20,-200,-120));//up center
    paredes.append(new pared(20,80,-260,-120));//up center
    //T laterales up
    paredes.append(new pared(20,140,-140,-120));//T left vertical
    paredes.append(new pared(80,20,-140,-180));//T left horizontal

    paredes.append(new pared(20,140,-380,-120));//T right vertical
    paredes.append(new pared(80,20,-320,-180));//T right horizontal
    //fin de la t up

    //Parte Inferior izquierda
    paredes.append(new pared(60,20,-40,-420));
    paredes.append(new pared(20,60,-80,-440));

    paredes.append(new pared(40,20,0,-480));

    paredes.append(new pared(180,20,-40,-540));
    paredes.append(new pared(20,60,-140,-480));

    paredes.append(new pared(80,20,-140,-420));

    //laterales tunel y T
    paredes.append(new pared(20,80,-140,-300));// lateral left
    paredes.append(new pared(20,80,-380,-300));//lateral right

    paredes.append(new pared(140,20,-200,-360));//middle
    paredes.append(new pared(20,80,-260,-360));//up center

    paredes.append(new pared(140,20,-200,-480));//middle
    paredes.append(new pared(20,80,-260,-480));//up center
    //fin de t y lateral

    //Parte inferior derecha
    paredes.append(new pared(60,20,-440,-420));
    paredes.append(new pared(20,60,-440,-440));

    paredes.append(new pared(40,20,-500,-480));

    paredes.append(new pared(180,20,-320,-540));
    paredes.append(new pared(20,60,-380,-480));

    paredes.append(new pared(80,20,-320,-420));
    //fin parte inf der

    //jaula fantasmas
    paredes.append(new pared(140,20,-200,-300));
    paredes.append(new pared(20,80,-200,-240));
    paredes.append(new pared(20,80,-320,-240));
    paredes.append(new pared(50,20,-200,-240));
    paredes.append(new pared(50,20,-290,-240));
    //paredes.append(new pared(20,80,-260,-480));//up center
    }
    for(int i=20;i<540;i=i+20)
    {
        for(int j=20;j<600;j=j+20)
        {
            galleta.append(new moneda(5,i,j));
        }
    }


//    for(auto it=galleta.begin();it!=galleta.end();it++)
//    {
//        scene->addItem(*it);
//    }

    QFile inputFile("Monedas.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
          QTextStream in(&inputFile);
          while (!in.atEnd())
          {
             QString line = in.readLine();
             qDebug()<<"linea: "<<line;
          }
          inputFile.close();
    }

    for(auto it=paredes.begin();it!=paredes.end();it++)
    {
        scene->addItem(*it);
    }



    scene->addItem(personaje);
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_A){
        personaje->left();
        qDebug()<<"posicion en x "<<personaje->x();
        if(personaje->x()==-30 && personaje->y()==280)
        {
            personaje->setPosx(560);
            personaje->setPosy(280);
        }
        for(auto it=paredes.begin();it!=paredes.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->right();
            }
        }
        for(auto it=galleta.begin();it!=galleta.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                scene->removeItem(*it);

            }
        }
    }
    else if(evento->key() == Qt::Key_D){
        personaje->right();
        qDebug()<<"posicion en x "<<personaje->x();
        if(personaje->x()==570 && personaje->y()==280)
        {
            personaje->setPosx(-20);
            personaje->setPosy(280);
        }
        for(auto it=paredes.begin();it!=paredes.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->left();
            }
        }
        for(auto it=galleta.begin();it!=galleta.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                scene->removeItem(*it);

            }
        }
    }
    else if(evento->key() == Qt::Key_W){
        personaje->up();
        qDebug()<<"posicion en y "<<personaje->y();
        for(auto it=paredes.begin();it!=paredes.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->down();
            }
        }

        for(int i=0;i<galleta.size();i++)
        {
            if(personaje->collidesWithItem(galleta[i])){
                scene->removeItem(galleta[i]);
            }
        }

    }
    else if(evento->key() == Qt::Key_S){
        personaje->down();
        qDebug()<<"posicion en y "<<personaje->y();
        for(auto it=paredes.begin();it!=paredes.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                personaje->up();
            }
        }
        for(auto it=galleta.begin();it!=galleta.end();it++)
        {
            if(personaje->collidesWithItem(*it)){
                scene->removeItem(*it);

            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

