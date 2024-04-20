#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    second_window = new SecondWindow();
    ui->dateEdit->setMinimumDate(QDate::currentDate());
    ui->lineEdit->setFocus();
}

MainWindow::~MainWindow() {
    delete second_window;
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    int count = ui->spinBoxCountTasks->value();
    int mon = ui->spinBoxMon->value();
    int tues = ui->spinBoxTues->value();
    int wed = ui->spinBoxWed->value();
    int thurs = ui->spinBoxThurs->value();
    int fri = ui->spinBoxFri->value();
    int sat = ui->spinBoxSat->value();
    int sun = ui->spinBoxSun->value();
    QDate date = ui->dateEdit->date();

    QMap<int, double> map;
    map.insert(1, mon);
    map.insert(2, tues);
    map.insert(3, wed);
    map.insert(4, thurs);
    map.insert(5, fri);
    map.insert(6, sat);
    map.insert(7, sun);
    second_window->set_data(date, count, map);
    QPoint pos = this->pos();
    this->close();
    second_window->show();
    second_window->move(pos);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        on_pushButton_clicked();
}
