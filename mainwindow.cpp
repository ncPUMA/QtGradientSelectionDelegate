#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "cgradientselectionstyledelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int row = 0; row < ui->tw1->rowCount(); ++row)
    {
        for(int column = 0; column < ui->tw1->columnCount(); ++column)
        {
            QTableWidgetItem * const itm = new QTableWidgetItem(tr("Ячейка %1 %2").arg(row + 1).arg(column + 1));
            ui->tw1->setItem(row, column, itm);
        }
    }

    for(int row = 0; row < ui->tw2->rowCount(); ++row)
    {
        for(int column = 0; column < ui->tw2->columnCount(); ++column)
        {
            QTableWidgetItem * const itm = new QTableWidgetItem(tr("Ячейка %1 %2").arg(row + 1).arg(column + 1));
            ui->tw2->setItem(row, column, itm);
        }
    }

    CGradientSelectionStyleDelegate * const styleDelegate = new CGradientSelectionStyleDelegate(ui->tw1);
    ui->tw1->setItemDelegate(styleDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}
