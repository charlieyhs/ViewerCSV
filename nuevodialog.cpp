#include "nuevodialog.h"
#include "ui_nuevodialog.h"

NuevoDialog::NuevoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevoDialog)
{
    ui->setupUi(this);
    setWindowTitle("Nuevo");
}

NuevoDialog::~NuevoDialog()
{
    delete ui;
}

int NuevoDialog::getRowCount() const
{
    return ui->rowCountSpinBox->value();
}

int NuevoDialog::getColCount() const
{
    return ui->colCountSpinBox->value();
}

void NuevoDialog::on_buttonBox_accepted()
{
    accept();
}

void NuevoDialog::on_buttonBox_rejected()
{
    reject();
}
