#include "editwindow.h"
#include "ui_editwindow.h"
#include <QMessageBox>
#include <QSqlQuery>

editwindow::editwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editwindow)
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

editwindow::~editwindow()
{
    delete ui;
    db.close();
}




void editwindow::on_backbutton_clicked()
{
    this->close();
    db.close();
}


void editwindow::on_editbutton_2_clicked()
{
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
    ui->tag_1->setText(text_1);
    ui->tag_2->setText(text_2);
    ui->tag_3->setText(text_3);
    ui->tag_4->setText(text_4);
    control=true;
}


void editwindow::on_editbutton_clicked()
{
    if (control)
    {
        QString value =QString::number(ui->spinBox->value());
        QSqlQuery edit_query;
        if( ui->comboBox->currentIndex() == 0)
        {
            edit_query.prepare("UPDATE house SET price=:price, house_type=:house_type, city=:city, address=:address WHERE house_id= " + value + " ");
            edit_query.bindValue(":price",ui->lineEdit->text());
            edit_query.bindValue(":house_type",ui->lineEdit_2->text());
            edit_query.bindValue(":city",ui->lineEdit_3->text());
            edit_query.bindValue(":address",ui->lineEdit_4->text());

            if(edit_query.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Данные отредактированы");
                msgBox.exec();
            }
            else {
                QMessageBox msgBox;
                msgBox.setText("Ошибка редактирования данных");
                msgBox.exec();
            }
        }
        if( ui->comboBox->currentIndex() == 1)
        {
            edit_query.prepare("UPDATE customer SET name=:name, surname=:surname, patronymic=:patronymic, telephone_number=:telephone_number WHERE customer_id= " + value + " ");
            edit_query.bindValue(":name",ui->lineEdit->text());
            edit_query.bindValue(":surname",ui->lineEdit_2->text());
            edit_query.bindValue(":patronymic",ui->lineEdit_3->text());
            edit_query.bindValue(":telephone_number",ui->lineEdit_4->text());

            if(edit_query.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Данные отредактированы");
                msgBox.exec();
            }
            else {
                QMessageBox msgBox;
                msgBox.setText("Ошибка редактирования данных");
                msgBox.exec();
            }
        }
        if( ui->comboBox->currentIndex() == 2)
        {
            edit_query.prepare("UPDATE booking SET hi=:hi, ci=:ci, start_date=:start_date, finish_date=:finish_date WHERE booking_id= " + value + " ");
            edit_query.bindValue(":hi",ui->lineEdit->text());
            edit_query.bindValue(":ci",ui->lineEdit_2->text());
            edit_query.bindValue(":start_date",ui->lineEdit_3->text());
            edit_query.bindValue(":finish_date",ui->lineEdit_4->text());
            if(edit_query.exec())
            {
                QMessageBox msgBox;
                msgBox.setText("Данные отредактированы");
                msgBox.exec();
            }
            else {
                QMessageBox msgBox;
                msgBox.setText("Ошибка редактирования данных");
                msgBox.exec();
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

