#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <widgetsubtask.h>
#include <QKeyEvent>
#include <thirdwindow.h>
#include <algorithm>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void set_data(QDate, int, QMap<int, double>);
    void generate_widgets();

    void enable_button();

private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent*);

private:
    Ui::SecondWindow *ui;
    QDate date;
    int count;
    QMap<int, double> map;
    WidgetSubtask* widgets;
    int count_complete_text_edit;
    ThirdWindow* third_window;

    bool calculate(QVector<double>);
};

#endif // SECONDWINDOW_H
