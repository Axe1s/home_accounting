#ifndef CMEDICINEEDIT_H
#define CMEDICINEEDIT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CMedicineEdit;
}

class CMedicineEdit : public QDialog
{
    Q_OBJECT

public:
    explicit CMedicineEdit(QWidget *parent = 0);
    ~CMedicineEdit();

private slots:
    void on_pushButtonMedSave_clicked();

private:
    Ui::CMedicineEdit *ui;
    QSqlTableModel m_medModel;
};

#endif // CMEDICINEEDIT_H
