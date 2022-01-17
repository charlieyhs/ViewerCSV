#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QStandardItemModel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNuevo_triggered();
    void on_actionAbrir_triggered();
    void on_actionGuardar_triggered();
    void on_actionSalir_triggered();

private:
    void setValueAt(int ix, int jx, const QString &value);
    QString getValueAt(int ix, int jx);
    Ui::MainWindow *ui;
    QStandardItemModel *mModel;
};
#endif // MAINWINDOW_H
