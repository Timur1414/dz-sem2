#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include <fourthwindow.h>
#include <QDate>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

    void set_date(QDate, int, QMap<int, int>, QVector<QString>, QVector<int>);
    void generate_widgets();

private slots:
    void on_pushButtonNext_clicked();

private:
    Ui::ThirdWindow *ui;
    QVector<QDate> dates;
    QVector<QString> names;
    QVector<int> times;
    QDate date;
    int count;
    QMap<int, int> map;
    FourthWindow* fourth_window;
};

#endif // THIRDWINDOW_H
