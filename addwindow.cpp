#include "addwindow.h"
#include "ui_addwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

addwindow::addwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addwindow)
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

addwindow::~addwindow()
{
    delete ui;
    db.close();
}

void addwindow::on_backbutton_clicked()
{
    this->close();
    db.close();
}

void addwindow::on_addButton_2_clicked()
{
    if (control)
    {
        QSqlQuery add_query;
        if( ui->comboBox->currentIndex() == 0)
        {
            add_query.prepare("INSERT INTO house(price, house_type, city, address) "
                              "VALUES (?, ?, ?, ?)");
            add_query.addBindValue(ui->lineEdit->text());
            add_query.addBindValue(ui->lineEdit_2->text());
            add_query.addBindValue(ui->lineEdit_3->text());
            add_query.addBindValue(ui->lineEdit_4->text());

            if(add_query.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Данные добавлены");
                msgBox.exec();
            }
            else {
                QMessageBox msgBox;
                msgBox.setText("Ошибка добавления данных");
                msgBox.exec();
            }
        }
        if( ui->comboBox->currentIndex() == 1)
        {
            add_query.prepare("INSERT INTO customer(name, surname, patronymic, telephone_number) "
            "VALUES (?, ?, ?, ?)");
            add_query.addBindValue(ui->lineEdit->text());
            add_query.addBindValue(ui->lineEdit_2->text());
            add_query.addBindValue(ui->lineEdit_3->text());
            add_query.addBindValue(ui->lineEdit_4->text());

            if(add_query.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Данные добавлены");
                msgBox.exec();
            }
            else {
                QMessageBox msgBox;
                msgBox.setText("Ошибка добавления данных");
                msgBox.exec();
            }
        }
        if( ui->comboBox->currentIndex() == 2)
        {
            QSqlQuery sec_query;
            sec_query.prepare("select booking_id from booking where (hi = " + ui->lineEdit->text() + ") and (ci = " + ui->lineEdit_2->text() + ") and (  ( (start_date <= :sdn) and (finish_date >= :sdn) ) or ( (start_date <= :fdn) and (finish_date >= :fdn) ) or ( (start_date >= :sdn) and (finish_date <= :fdn) )  )");
            sec_query.bindValue(":sdn", ui->lineEdit_3->text());
            sec_query.bindValue(":fdn", ui->lineEdit_4->text());
            sec_query.exec();
            if  (sec_query.next())
            {
                QMessageBox msgBox;
                msgBox.setText("Недоступная дата");
                msgBox.exec();
            }
            else {
                add_query.prepare("INSERT INTO booking(hi, ci, start_date, finish_date) "
                                  "VALUES (?, ?, ?, ?)");
                add_query.addBindValue(ui->lineEdit->text());
                add_query.addBindValue(ui->lineEdit_2->text());
                add_query.addBindValue(ui->lineEdit_3->text());
                add_query.addBindValue(ui->lineEdit_4->text());
                if(add_query.exec())
                {
                    QSqlQuery th_query;
                    th_query.prepare("select * FROM booking WHERE start_date > finish_date");
                    th_query.exec();
                    if(th_query.next())
                    {
                        th_query.prepare("delete FROM booking WHERE start_date > finish_date");
                        th_query.exec();
                        QMessageBox msgBox;
                        msgBox.setText("Неверная дата");
                        msgBox.exec();
                    }
                    else
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Данные добавлены");
                        msgBox.exec();
                    }
                }
                else {
                    QMessageBox msgBox;
                    msgBox.setText("Ошибка добавления данных");
                    msgBox.exec();
                }
            }
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Сначала выберите таблицу");
        msgBox.exec();
    }
}
void addwindow::on_comboBox_activated(int index)
{
    control = true;
    QString text_1;
    QString text_2;
    QString text_3;
    QString text_4;
    if( ui->comboBox->currentIndex() == 0)
    {
        text_1="СТОИМОСТЬ:";
        text_2="ТИП ДОМА:";
        text_3="ГОРОД:";
        text_4="АДРЕС:";
    }
    if( ui->comboBox->currentIndex() == 1)
    {
        text_1="ИМЯ:";
        text_2="ФАМИЛИЯ:";
        text_3="ОТЧЕТВО:";
        text_4="НОМЕР ТЕЛЕФОНА:";
    }
    if( ui->comboBox->currentIndex() == 2)
    {
        text_1="ID ДОМА:";
        text_2="ID ПОКУПАТЕЛЯ:";
        text_3="ДАТА НАЧАЛА АРЕНДЫ";
        text_4="ДАТА КОНЦА АРЕНДЫ";
    }
    ui->box_1->setText(text_1);
    ui->box_2->setText(text_2);
    ui->box_3->setText(text_3);
    ui->box_4->setText(text_4);
}

