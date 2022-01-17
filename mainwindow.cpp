#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nuevodialog.h"

#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    setCentralWidget(ui->tableView);
    setWindowTitle("Du CSV Viewer");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNuevo_triggered()
{
    NuevoDialog d(this);
    if(d.exec()==QDialog::Rejected){
        return;
    }
    const int rowCount = d.getRowCount();
    const int colCount = d.getColCount();
    mModel->setRowCount(rowCount);
    mModel->setColumnCount(colCount);

}

void MainWindow::on_actionAbrir_triggered()
{
    auto filename = QFileDialog::getOpenFileName(this,"Abrir",QDir::rootPath(),"CSV File (*.csv)");
    if(filename.isEmpty()){
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream xin(&file);
    int ix = 0;
    while(!xin.atEnd()){
        mModel->setRowCount(ix);
        auto line = xin.readLine();
        auto values = line.split(",");
        const int colCount = values.size();
        mModel->setColumnCount(colCount);
        for(int jx = 0;jx<colCount;jx++){
           setValueAt(ix,jx,values.at(jx));
        }
        ++ix;
    }
    file.close();
}

void MainWindow::on_actionGuardar_triggered()
{
    auto filename = QFileDialog::getSaveFileName(this,"Guardar",QDir::rootPath(),"CSV file (*.csv)");
    if(filename.isEmpty()){
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream xout(&file);
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    for(int ix=0;ix<rowCount;ix++){
        xout << getValueAt(ix,0);
        for(int jx=0;jx<colCount;jx++){
            xout <<", "<< getValueAt(ix,jx);
        }
        xout << "\n";
    }
    file.flush();
    file.close();
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::setValueAt(int ix, int jx, const QString &value)
{
    if(!mModel->item(ix,jx)){
        mModel->setItem(ix,jx,new QStandardItem(value));
    }else{
        mModel->item(ix,jx)->setText(value);
    }
}

QString MainWindow::getValueAt(int ix, int jx)
{
    if(!mModel->item(ix,jx)){
        return "";
    }
    return mModel->item(ix,jx)->text();
}
