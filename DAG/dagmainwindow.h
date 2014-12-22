#ifndef DAGMAINWINDOW_H
#define DAGMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class DAGMainWindow;
}

class DAGMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DAGMainWindow(QWidget *parent = 0);
    ~DAGMainWindow();

private:
    Ui::DAGMainWindow *ui;
};

#endif // DAGMAINWINDOW_H
