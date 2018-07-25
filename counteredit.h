#ifndef COUNTEREDIT_H
#define COUNTEREDIT_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class CounterEdit;
}

class CCounterEdit : public QDialog
{
    Q_OBJECT

public:
	explicit CCounterEdit(QWidget *parent = 0);
	~CCounterEdit();

private slots:
    void on_pushButtonCountCansel_clicked();

    void on_pushButtonCounterSave_clicked();

	void on_tbCountDate_clicked();

private:
    Ui::CounterEdit *ui;
    QSqlTableModel m_countModel;
};

#endif // COUNTEREDIT_H
