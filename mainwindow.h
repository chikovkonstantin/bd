#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "viewwindow.h"
#include "deletewindow.h"
#include "addwindow.h"
#include "editwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_viewbutton_clicked();

    void on_editbutton_clicked();

    void on_addbutton_clicked();

    void on_deletebutton_clicked();

private:
    Ui::MainWindow *ui;
    viewwindow *w;
    deletewindow *d;
    addwindow *a;
    editwindow *e;
};
#endif // MAINWINDOW_H
