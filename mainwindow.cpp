#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "sortmodel.h"
#include <iostream>
#include "sourcemodel.h"
#include <QModelIndex>
#include <string>

#include <algorithm>
#include <random>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    SourceModel *sourceModel = new SourceModel(this);

    setSourceData(sourceModel);


    m_sortModel = new SortModel(this);



    m_sortModel->setSourceModel(sourceModel);


    ui->setupUi(this);
    ui->tabela->setModel(m_sortModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSourceData(QAbstractItemModel *model)
{
    QString wzorzec("ToJestNiezwykleDlugiStringNieMajacySobieRownegoLancucha");
    auto rng = std::default_random_engine {};


    for(int i = 0; i < 40000; ++i) {
        int currrentRowNumber = model->rowCount();
        model->insertRows(currrentRowNumber, 1, QModelIndex());

        QModelIndex idx = model->index(currrentRowNumber, 0);
        model->setData(idx, QString("id%1").arg(i, 6, 10, QChar('0')), Qt::DisplayRole);

        std::shuffle(wzorzec.begin(), wzorzec.end(), rng);

        idx = model->index(currrentRowNumber, 1);
        model->setData(idx, wzorzec.mid(0, 7), Qt::DisplayRole);

        idx = model->index(currrentRowNumber, 2);
        model->setData(idx, wzorzec.mid(9, 7), Qt::DisplayRole);

        idx = model->index(currrentRowNumber, 3);
        model->setData(idx, wzorzec.mid(18, 7), Qt::DisplayRole);
    }
}
