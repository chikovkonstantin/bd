#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class deletewindow;
}

class deletewindow : public QWidget
{
    Q_OBJECT

public:
    explicit deletewindow(QWidget *parent = nullptr);
    ~deletewindow();

private slots:
    void on_backButton_clicked();

    void on_delbutton_clicked();

private:
    Ui::deletewindow *ui;
    QSqlDatabase db;
};

#endif // DELETEWINDOW_H
