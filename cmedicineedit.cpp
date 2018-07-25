#include "cmedicineedit.h"
#include "ui_cmedicineedit.h"
#include <QtSql>

CMedicineEdit::CMedicineEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CMedicineEdit)
{
    ui->setupUi(this);
}

CMedicineEdit::~CMedicineEdit()
{
    delete ui;
}

void CMedicineEdit::on_pushButtonMedSave_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO medicine (name, date, comment) "
                  "VALUES (:name, :date, :comment)");
    query.bindValue( ":name",     ui->lineEditMedName->text() );
    query.bindValue( ":date",    ui->dateEditMedDateBay->date() );
    query.bindValue( ":comment", ui->lineEditMedPlace->text() );
    query.exec();

    if ( query.lastError().type() != QSqlError::NoError )
    {
        qCritical() << query.lastError().text();
    }

    CMedicineEdit::accept();
}
