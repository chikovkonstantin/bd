#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class viewwindow;
}

class viewwindow : public QWidget
{
    Q_OBJECT

public:
    explicit viewwindow(QWidget *parent = nullptr);
    ~viewwindow();

private slots:
    void on_confirmbutton_clicked();

    void on_backbutton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_activated(int index);

private:
    Ui::viewwindow *ui;
    QSqlDatabase db;
};

#endif // VIEWWINDOW_H
