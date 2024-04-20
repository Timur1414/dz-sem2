#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::SecondWindow) {
    ui->setupUi(this);
    date = QDate::currentDate();
    count = 0;
    widgets = nullptr;
    count_complete_text_edit = 0;
    third_window = new ThirdWindow();
}

SecondWindow::~SecondWindow() {
    delete[] widgets;
    delete third_window;
    delete ui;
}

void SecondWindow::set_data(QDate date, int count, QMap<int, double> map) {
    this->date = date;
    this->count = count;
    this->map = map;
    widgets = new WidgetSubtask[count];
    generate_widgets();
}

void SecondWindow::generate_widgets() {
    for (int i = 0; i < count; i++) {
        widgets[i].set(i, this);
        widgets[i].move(30, 10 + i * 80);
        widgets[i].setParent(ui->frame);
        ui->frame->setMinimumHeight(10 + i * 90);

        QLineEdit* line_edit = findChild<QLineEdit*>("lineEdit" + QString::number(i));
        connect(line_edit, line_edit->textChanged, this, enable_button);
        if (i == 0)
            line_edit->setFocus();
    }
}

void SecondWindow::on_pushButton_clicked() {
    QVector<QString> names;
    QVector<double> times;
    for (int i = 0; i < count; i++) {
        QLineEdit* line_edit = findChild<QLineEdit*>("lineEdit" + QString::number(i));
        QSpinBox* spin_box = findChild<QSpinBox*>("spinBox" + QString::number(i));
        names.push_back(line_edit->text());
        times.push_back(spin_box->value());
    }

    bool res = calculate(times);

    QPoint pos = this->pos();
    this->close();
    third_window->set_date(res, map, date, count, times);
    third_window->show();
    third_window->move(pos);
}

void SecondWindow::keyPressEvent(QKeyEvent* event) {
    if (!ui->pushButton->isEnabled())
        return;
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        on_pushButton_clicked();
}

void SecondWindow::enable_button() {
    count_complete_text_edit = 0;
    for (int i = 0; i < count; i++) {
        QLineEdit* line_edit = findChild<QLineEdit*>("lineEdit" + QString::number(i));
        auto check_string = [](const QString& text) {
            if (std::all_of(text.begin(), text.end(), [](const QChar& c) {
                    return c == ' ';
                }))
                return 0;
            return int(!text.isEmpty());
        };
        count_complete_text_edit += check_string(line_edit->text());
    }

    if (count_complete_text_edit < count)
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}

bool SecondWindow::calculate(QVector<double> times) {
    int i = 0;
    int cur_task = 0;
    for (auto cur_date = QDate::currentDate(); cur_date <= date; cur_date = QDate::currentDate().addDays(i), i++) {
        int time = map[cur_date.dayOfWeek()];
        while (time >= 0) {
            times[cur_task] -= time;
            time = -times[cur_task];
            if (times[cur_task] <= 0) {
                cur_task++;
            }
            if (cur_task >= count) {
                return true;
            }
        }
    }
    return (cur_task >= count);
    // int i = 1;
    // int cur_task = 0;
    // bool flag = false;
    // free_time = 0;
    // for (auto cur_date = QDate::currentDate(); cur_date <= date; cur_date = QDate::currentDate().addDays(i), i++) {
    //     int time = map[cur_date.dayOfWeek()];
    //     if (!flag) {
    //         while (time >= 0) {
    //             times[cur_task] -= time;
    //             time = -times[cur_task];
    //             if (times[cur_task] <= 0) {
    //                 subtasks_dates.push_back(cur_date);
    //                 cur_task++;
    //             }
    //             if (cur_task >= count) {
    //                 flag = true;
    //                 free_time = time;
    //                 break;
    //             }
    //         }
    //     } else {
    //         free_time += time;
    //     }
    // }
    // return (cur_task >= count);
}
