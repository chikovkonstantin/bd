#include "deletewindow.h"
#include "ui_deletewindow.h"
#include <QSqlQuery>
#include <QMessageBox>

deletewindow::deletewindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletewindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");

    db.setDatabaseName("kursach");

    db.setUserName("postgres");

    db.setPassword("as2483561");

    db.open();
    if (db.open())
    {
        qDebug() << "connected";
    }
    else {
        qDebug() << "bad_connection";
    }
}

deletewindow::~deletewindow()
{
    delete ui;
    db.close();
}

void deletewindow::on_backButton_clicked()
{
    this->close();
    db.close();
}


void deletewindow::on_delbutton_clicked()
{
    QString value =QString::number(ui->spinBox->value());
    QString id;
    if( ui->comboBox->currentIndex() == 0)
    {
        id="house_id";
    }
    if( ui->comboBox->currentIndex() == 1)
    {
        id="customer_id";
    }
    if( ui->comboBox->currentIndex() == 2)
    {
        id="booking_id";
    }
    QSqlQuery del_query;
    del_query.prepare("DELETE FROM "+ ui->comboBox->currentText() + " WHERE " + id + " = " + value + " ");
    if(del_query.exec())
    {
        QMessageBox msgBox;
        msgBox.setText("Данные удалены");
        msgBox.exec();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Ошибка удаления данных");
        msgBox.exec();
    }
    db.close();
}

