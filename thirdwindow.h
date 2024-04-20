#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDate>
#include <QLabel>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

    void set_date(bool, QMap<int, double>, QDate, int, QVector<double>);
    void generate_widgets(QMap<int, double>, QVector<QDate>);

private slots:
    void keyPressEvent(QKeyEvent*);

private:
    Ui::ThirdWindow *ui;
    bool res;
    QMap<int, double> map;
    QDate date;
    QLabel* widgets;
    QLabel* widgets_tasks;
    QVector<QString> arr_days;
    int count;
    QVector<double> times;

    QMap<int, double> optimize();
    QVector<QDate> new_complete_dates(QMap<int, double>);
};

#endif // THIRDWINDOW_H
