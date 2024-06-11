#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class editwindow;
}

class editwindow : public QWidget
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr);
    ~editwindow();

private slots:
    void on_confirmbutton_clicked();

    void on_backbutton_clicked();

    void on_editbutton_2_clicked();

    void on_editbutton_clicked();

private:
    Ui::editwindow *ui;
    QSqlDatabase db;
    bool control=false;
};

#endif // EDITWINDOW_H
