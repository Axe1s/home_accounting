#include "homeaccounting.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//	QSqlDatabase dbase1 = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
//	dbase1.setDatabaseName ("data/db1.sqlite");

	QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE"); //Создание подключения базы данных
	dbase.setDatabaseName ("data/db.sqlite"); //Путь к базе данных

	if (!dbase.open())  //Проверка соединения с базой данных
	{
		qDebug() << "No connect";
	}
	else
	{
		qDebug() << "Connected";
	}


	QApplication a(argc, argv);
    CHomeAccounting w;
    w.show();

    return a.exec();

	dbase.close();
}
