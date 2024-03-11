#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include <fourthwindow.h>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_pushButtonNext_clicked();

private:
    Ui::ThirdWindow *ui;
    FourthWindow* fourth_window;
};

#endif // THIRDWINDOW_H
