#ifndef MEDICINEEDIT_H
#define MEDICINEEDIT_H

#include <QWidget>
#include <QDialog>
#include <QtSql>

namespace Ui {
class medicineEdit;
}

class medicineEdit : public QWidget
{
    Q_OBJECT

public:
    explicit medicineEdit(QWidget *parent = 0);
    ~medicineEdit();


private:
    Ui::medicineEdit *ui;
};

#endif // MEDICINEEDIT_H
