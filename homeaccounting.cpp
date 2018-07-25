#include "homeaccounting.h"
#include "ui_homeaccounting.h"
#include "counteredit.h"
#include "cmedicineedit.h"
#include "QtSql"
#include "QDebug"
#include "QMessageBox"

CHomeAccounting::CHomeAccounting(QWidget *parent) :
    QMainWindow(parent),
	ui(new Ui::HomeAccounting),
    m_countModel(this),
	m_medModel(this)
{
	ui->setupUi(this);//Запуск основого окна программы
	ui->counterEditBox->setVisible(false);//Скрыть панель редактирования счётчиков
	ui->medicineEditBox->setVisible(false);//Скрыть панель редактирования лекарств


//qDebug() << QSqlDatabase::database( "my_connection", false ); //Запрос в таблицу
//    QSqlQuery q;
//    q.prepare("select * from medicine");
//    q.exec();
//    while ( q.next() )
//    {
//        qDebug() << q.value("name").toString();
//    }

    ui->countTableView->setModel(&m_countModel); //Вывод таблицы в поле счётчиков
    ui->countTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//Запред редактирования в напрямую в таблице
	ui->countTableView->setSelectionBehavior(QAbstractItemView::SelectRows);//	Выделение данных строкой
	m_countModel.setTable("counters");//Показать таблицу счётчиков
	m_countModel.select();


    ui->medicineTableView->setModel(&m_medModel); //Вывод таблицы в поле лекарств
    ui->medicineTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//Запред редактирования в напрямую в таблице
    m_medModel.setTable("medicine");
	m_medModel.select();

    if ( m_countModel.lastError().type() != QSqlError::NoError )//Вывод ошибок в консоль
		qCritical() << m_countModel.lastError().text();
}

CHomeAccounting::~CHomeAccounting()
{
    delete ui;
}


void CHomeAccounting::on_counterHide_clicked()//Кнопка "Показать-Скрыть" редактирование счётсиков
{
static bool open = true;
ui -> counterEditBox -> setVisible(open);
open =!open;
}

void CHomeAccounting::on_medicineHid_clicked()//Кнопка "Показать-Скрыть" редактирование лекарств
{
	static bool open = true;
	ui -> medicineEditBox -> setVisible(open);
	open =!open;
}

void CHomeAccounting::on_counterAdd_clicked() //Кнопка вызова окна добавления счётчиков
{
	CCounterEdit * pDlgCounter = new CCounterEdit ( this );
	pDlgCounter->exec();
	delete pDlgCounter;
	m_countModel.select();
}


void CHomeAccounting::on_medicineAdd_clicked()//Вызов окна редактирования лекарств
{
    CMedicineEdit * pDlgMedicine = new CMedicineEdit ( this );
    pDlgMedicine->exec();
    delete pDlgMedicine;
    m_medModel.select();
}


void CHomeAccounting::on_counterPrint_clicked()
{

}


void CHomeAccounting::on_counterRemove_clicked()//Кнопка удаления записи в счётчиках
{
	// Удаление трок счётчиков
			// Создание окна с выбором вариантов действий
			// Создание переменной ответа
			QMessageBox::StandardButton stButtonYes;
			// Присвоение значений для выбора пользователя: "Yes" или "No"
			stButtonYes = QMessageBox::question(this, "Подтверждение удаления",
                                        "Вы действительно хотите удалить запись?",
										 QMessageBox::Yes | QMessageBox::No);
			// Проверка нажатия кнопки "Yes"
			if(stButtonYes == QMessageBox::Yes)
			{
				// Если нажата, то удаляем выбранную строку
				m_countModel.removeRow(ui->countTableView->currentIndex().row());
				//обновление модели
				m_countModel.select();
			}
}

void CHomeAccounting::on_medicineRemove_clicked()//Кнопка удаления записи в лекарствах
{
	// Удаление строк лекарств
			// Создание окна с выбором вариантов действий
			// Создание переменной ответа
			QMessageBox::StandardButton stButtonYes;
			// Присвоение значений для выбора пользователя: "Yes" или "No"
			stButtonYes = QMessageBox::question(this, "Подтверждение удаления",
                                        "Вы действительно хотите удалить запись?",
										 QMessageBox::Yes | QMessageBox::No);
			// Проверка нажатия кнопки "Yes"
			if(stButtonYes == QMessageBox::Yes)
			{
				// Если нажата, то удаляем выбранную строку
                m_medModel.removeRow(ui->medicineTableView->currentIndex().row());
				//обновление модели
				m_medModel.select();
			}
}




