#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    second_window = new SecondWindow();
}

MainWindow::~MainWindow() {
    delete ui;
    delete second_window;
}

void MainWindow::on_pushButtonNext_clicked() {
    this->close();
    second_window->show();
}

