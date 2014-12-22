#include "dagmainwindow.h"
#include "ui_dagmainwindow.h"

DAGMainWindow::DAGMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DAGMainWindow)
{
    ui->setupUi(this);
}

DAGMainWindow::~DAGMainWindow()
{
    delete ui;
}
