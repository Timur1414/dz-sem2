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

