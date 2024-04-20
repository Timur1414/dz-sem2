#include "thirdwindow.h"
#include "ui_thirdwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::ThirdWindow) {
    ui->setupUi(this);
    arr_days = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
}

ThirdWindow::~ThirdWindow() {
    delete[] widgets;
    delete[] widgets_tasks;
    delete ui;
}

void ThirdWindow::set_date(bool res, QMap<int, double> map, QDate date, int count, QVector<double> times) {
    this->res = res;
    this->map = map;
    this->date = date;
    this->count = count;
    this->times = times;
    ui->labelResult->setText((res ? "Успеете" : "Не успеете"));
    if (res) {
        QMap<int, double> new_map = optimize();
        QVector<QDate> subtasks_dates = new_complete_dates(new_map);
        generate_widgets(new_map, subtasks_dates);
    } else {
        ui->frame2->setStyleSheet("");
        ui->frame->setStyleSheet("");
    }
    ui->labelResult->setStyleSheet((res ? "color: green" : "color: red;"));
}

void ThirdWindow::generate_widgets(QMap<int, double> new_map, QVector<QDate> subtasks_dates) {
    widgets = new QLabel[8];
    widgets[0].setParent(ui->frame);
    widgets[0].move(0, 0);
    widgets[0].setAlignment(Qt::AlignHCenter);
    widgets[0].setText("Оптимальное расписание");
    widgets[0].setFixedWidth(200);
    widgets[0].setFont(QFont("Segoe UI", 10));
    for (int i = 1; i < 8; i++) {
        widgets[i].setParent(ui->frame);
        widgets[i].move(0, 40 + 40 * i);
        widgets[i].setFixedWidth(200);
        widgets[i].setAlignment(Qt::AlignHCenter);
        QString day_of_week = arr_days[i - 1];
        QString tmp_number = QString::number(new_map[i]);
        tmp_number = tmp_number.left(tmp_number.indexOf(".") + 3);
        widgets[i].setText(day_of_week + " " + tmp_number);
        widgets[i].setFont(QFont("Segoe UI", 10));
    }

    widgets_tasks = new QLabel[count];
    for (int i = 0; i < count; i++) {
        widgets_tasks[i].setParent(ui->frame2);
        widgets_tasks[i].move(0, 30 * i);
        widgets_tasks[i].setMinimumWidth(245);
        widgets_tasks[i].setText("Задача " + QString::number(i + 1) + " завершится в " + subtasks_dates[i].toString("dd.MM.yyyy"));
        widgets_tasks[i].setAlignment(Qt::AlignHCenter);
        widgets_tasks[i].setFont(QFont("Segoe UI", 10));
        ui->frame2->setMinimumHeight(20 + 30 * i);
    }
}

void ThirdWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        this->close();
}

QMap<int, double> ThirdWindow::optimize() {
    int need_time = 0;
    std::for_each(times.begin(), times.end(), [&need_time](int item) {
        need_time += item;
    });
    int all_time = 0;
    int i = 1;
    for (auto cur_date = QDate::currentDate(); cur_date <= date; cur_date = QDate::currentDate().addDays(i), i++) {
        int index = cur_date.dayOfWeek();
        if (map[index] != 0)
            all_time++;
    }
    if (!all_time)
        return map;
    double hours_in_day = need_time * 1.0 / all_time;
    qDebug() << need_time << "/" << all_time << "=" <<  hours_in_day;
    for (auto i : map.keys()) {
        if (map[i] != 0)
            map[i] = hours_in_day;
    }
    return map;
    // int count_all_work_days = 0;
    // int i = 1;
    // for (auto cur_date = QDate::currentDate(); cur_date <= date; cur_date = QDate::currentDate().addDays(i), i++) {
    //     int index = cur_date.dayOfWeek();
    //     if (map[index] > 0)
    //         count_all_work_days++;
    // }
    // if (count_all_work_days == 0)
    //     return map;
    // int tmp = free_time / count_all_work_days;
    // // qDebug() << tmp;
    // for (auto i : map.keys()) {
    //     if (map[i] > tmp)
    //         map[i] -= tmp;
    // }
    // // qDebug() << map;
    // return map;
}

QVector<QDate> ThirdWindow::new_complete_dates(QMap<int, double> new_map) {
    QVector<QDate> res;
    int i = 1;
    int cur_task = 0;
    for (auto cur_date = QDate::currentDate(); cur_date <= date; cur_date = QDate::currentDate().addDays(i), i++) {
        double time = std::ceil(new_map[cur_date.dayOfWeek()] * 1000.0) / 1000.0;
        while (time >= 0) {
            times[cur_task] -= time;
            time = -times[cur_task];
            if (times[cur_task] <= 0) {
                cur_task++;
                res.push_back(cur_date);
            }
            if (cur_task >= count) {
                return res;
            }
        }
    }
    if (res.size() != count)
        res.push_back(date);
    return res;
}
