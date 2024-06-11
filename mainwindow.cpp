#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deletewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    e->close();
    w->close();
    d->close();
    a->close();
}


void MainWindow::on_viewbutton_clicked()
{
    w = new viewwindow();
    w->show();
}


void MainWindow::on_editbutton_clicked()
{
    e = new editwindow();
    e->show();
}


void MainWindow::on_addbutton_clicked()
{
    a = new addwindow();
    a->show();
}


void MainWindow::on_deletebutton_clicked()
{
    d = new deletewindow();
    d->show();
}

