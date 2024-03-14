#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QMainWindow>

namespace Ui {
class FourthWindow;
}

class FourthWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FourthWindow(QWidget *parent = nullptr);
    ~FourthWindow();

    void set_data(QString);

private:
    Ui::FourthWindow *ui;
    QString result;
};

#endif // FOURTHWINDOW_H
