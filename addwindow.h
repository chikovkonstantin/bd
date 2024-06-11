#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class addwindow;
}

class addwindow : public QWidget
{
    Q_OBJECT

public:
    explicit addwindow(QWidget *parent = nullptr);
    ~addwindow();

private slots:
    void on_backbutton_clicked();

    void on_addbutton_clicked();

    void on_addButton_2_clicked();

private:
    Ui::addwindow *ui;
    QSqlDatabase db;
    bool control=false;
};

#endif // ADDWINDOW_H
