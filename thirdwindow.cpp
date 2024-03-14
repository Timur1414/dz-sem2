#include "thirdwindow.h"
#include "ui_thirdwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::ThirdWindow) {
    ui->setupUi(this);
    fourth_window = new FourthWindow();
}

ThirdWindow::~ThirdWindow() {
    delete ui;
    delete fourth_window;
}

void ThirdWindow::on_pushButtonNext_clicked() {
    this->close();
    fourth_window->show();
}

void ThirdWindow::set_date(QDate date, int count, QMap<int, int> map, QVector<QString> names, QVector<int> times) {
    this->date = date;
    this->count = count;
    this->map = map;
    this->names = names;
    this->times = times;
}
