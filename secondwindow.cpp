#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::SecondWindow) {
    ui->setupUi(this);
    third_window = new ThirdWindow();
}

SecondWindow::~SecondWindow() {
    delete ui;
    delete third_window;
}

void SecondWindow::on_pushButtonNext_clicked() {
    this->close();
    third_window->show();
}

