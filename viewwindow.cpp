#include "viewwindow.h"
#include "ui_viewwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

viewwindow::viewwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewwindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");

    db.setDatabaseName("kursach");

    db.setUserName("postgres");

    db.setPassword("as2483561");

    if (db.open())
    {
        qDebug() << "ok";
    }
    else {
        qDebug() << "nou";
    }
    db.open();
}

viewwindow::~viewwindow()
{
    delete ui;
    db.close();
}


void viewwindow::on_confirmbutton_clicked()
{
    QString column1;
    QString column2;
    QString column3;
    QString column4;
    QString column5;
    if( ui->comboBox->currentIndex() == 0)
    {
        QList <QString> labels_1;
        labels_1.append("house_id");
        labels_1.append("price");
        labels_1.append("house_type");
        labels_1.append("city");
        labels_1.append("address");
        column1="house_id";
        column2="price";
        column3="house_type";
        column4="city";
        column5="address";
        ui->tableWidget->setHorizontalHeaderLabels(labels_1);
    }
    if( ui->comboBox->currentIndex() == 1)
    {
        QList <QString> labels_2;
        labels_2.append("customer_id");
        labels_2.append("name");
        labels_2.append("surname");
        labels_2.append("patronymic");
        labels_2.append("telephone_number");
        column1="customer_id";
        column2="name";
        column3="surname";
        column4="patronymic";
        column5="telephone_number";
        ui->tableWidget->setHorizontalHeaderLabels(labels_2);
    }
    if( ui->comboBox->currentIndex() == 2)
    {
        QList <QString> labels_3;
        labels_3.append("booking_id");
        labels_3.append("house_id");
        labels_3.append("customer_id");
        labels_3.append("start_date");
        labels_3.append("finish_date");
        column1="booking_id";
        column2="hi";
        column3="ci";
        column4="start_date";
        column5="finish_date";
        ui->tableWidget->setHorizontalHeaderLabels(labels_3);
    }
    QSqlQuery query;
    if(ui->comboBox_2->currentIndex()==0)
    {
        query.prepare("SELECT * FROM "+ ui->comboBox->currentText() + " ");
    }
    else
    {
        query.prepare("SELECT * FROM "+ ui->comboBox->currentText() + " WHERE " + ui->comboBox_2->currentText() + " = " + ui->lineEdit->text() + "");
    }
    if(query.exec())
    {
        int Row_Number=0;
        ui->tableWidget->setRowCount(query.size());
        while(query.next())
        {
            ui->tableWidget->setItem(Row_Number,0,new QTableWidgetItem(QString(query.value(""+ column1 +"").toString())));
            ui->tableWidget->setItem(Row_Number,1,new QTableWidgetItem(QString(query.value(""+ column2 +"").toString())));
            ui->tableWidget->setItem(Row_Number,2,new QTableWidgetItem(QString(query.value(""+ column3 +"").toString())));
            ui->tableWidget->setItem(Row_Number,3,new QTableWidgetItem(QString(query.value(""+ column4 +"").toString())));
            ui->tableWidget->setItem(Row_Number,4,new QTableWidgetItem(QString(query.value(""+ column5 +"").toString())));
            Row_Number++;
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Ошибка просмотра данных");
        msgBox.exec();
    }

}


void viewwindow::on_backbutton_clicked()
{
    this->close();
    db.close();
}








void viewwindow::on_comboBox_activated(int index)
{
    ui->comboBox_2->clear();
    if( ui->comboBox->currentIndex() == 0)
    {
        QList <QString> labels_1;
        labels_1.append("нет");
        labels_1.append("house_id");
        labels_1.append("price");
        labels_1.append("house_type");
        labels_1.append("city");
        labels_1.append("address");
        ui->comboBox_2->addItems(labels_1);
    }
    if( ui->comboBox->currentIndex() == 1)
    {
        QList <QString> labels_2;
        labels_2.append("нет");
        labels_2.append("customer_id");
        labels_2.append("name");
        labels_2.append("surname");
        labels_2.append("patronymic");
        labels_2.append("telephone_number");
        ui->comboBox_2->addItems(labels_2);
    }
    if( ui->comboBox->currentIndex() == 2)
    {
        QList <QString> labels_3;
        labels_3.append("нет");
        labels_3.append("booking_id");
        labels_3.append("house_id");
        labels_3.append("customer_id");
        labels_3.append("start_date");
        labels_3.append("finish_date");
        ui->tableWidget->setHorizontalHeaderLabels(labels_3);ui->comboBox_2->addItems(labels_3);
    }
}

