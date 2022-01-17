#ifndef NUEVODIALOG_H
#define NUEVODIALOG_H

#include <QDialog>

namespace Ui {
class NuevoDialog;
}

class NuevoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoDialog(QWidget *parent = nullptr);
    ~NuevoDialog();
    int getRowCount()const;
    int getColCount()const;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::NuevoDialog *ui;
};

#endif // NUEVODIALOG_H
