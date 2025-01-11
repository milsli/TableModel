#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemModel>

class SortModel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSourceData(QAbstractItemModel* model);

private:
    Ui::MainWindow *ui;

    SortModel *m_sortModel;
};
#endif // MAINWINDOW_H
