#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <thirdwindow.h>
#include <QDate>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void set_data(QDate, int, QMap<int, int>);
    void generate_widgets();

private slots:
    void on_pushButtonNext_clicked();

private:
    Ui::SecondWindow *ui;
    QDate date;
    int count;
    QMap<int, int> map;
    ThirdWindow* third_window;
};

#endif // SECONDWINDOW_H
