#include "counteredit.h"
#include "ui_counteredit.h"
#include <QtSql>
#include <QDate>

CCounterEdit::CCounterEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CounterEdit)
	{
    ui->setupUi(this);
	ui->dateEditCount->setDate(QDate::currentDate());//Установка даты по умолчанию
	}

CCounterEdit::~CCounterEdit()
{
	delete ui;
}

void CCounterEdit::on_pushButtonCountCansel_clicked()
{

}

void CCounterEdit::on_pushButtonCounterSave_clicked()
{
    addCounterData();
}

void CCounterEdit::on_tbCountDate_clicked()
{

}

void CCounterEdit::addCounterData()
{
    QSqlQuery query;
    query.prepare("INSERT INTO counters (date, gas, electro, hotw, coldw) "
                  "VALUES (:date, :gas, :electro, :hotw, :coldw)");
    query.bindValue( ":date",    ui->dateEditCount->date() );
    query.bindValue( ":gas",     ui->lineEditGas->text().toInt() );
    query.bindValue( ":electro", ui->lineEditElectro->text().toInt() );
    query.bindValue( ":hotw",     ui->lineEditHot->text().toInt() );
    query.bindValue( ":coldw",    ui->lineEditCold->text().toInt() );
    query.exec();

    if ( query.lastError().type() != QSqlError::NoError )
    {
        qCritical() << query.lastError().text();
    }

    CCounterEdit::accept();
}

void CCounterEdit::editCounterData()
{

}
