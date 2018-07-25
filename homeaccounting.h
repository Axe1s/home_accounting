#ifndef HOMEACCOUNTING_H
#define HOMEACCOUNTING_H


#include <QMainWindow>
#include <QtSql>
#include <QDebug>


namespace Ui {
class HomeAccounting;
}

class CHomeAccounting : public QMainWindow
{
    Q_OBJECT

public:
	explicit CHomeAccounting(QWidget *parent = 0);
	~CHomeAccounting();





private slots:
    void on_counterHide_clicked();

    void on_counterAdd_clicked();


	void on_counterPrint_clicked();

	void on_medicineHid_clicked();

	void on_medicineRemove_clicked();

	void on_counterRemove_clicked();

    void on_medicineAdd_clicked();

private:
	Ui::HomeAccounting *ui;

//    QSqlDatabase dbase;
	QSqlTableModel m_countModel;
	QSqlTableModel m_medModel;




};

#endif // HOMEACCOUNTING_H
