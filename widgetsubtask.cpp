#include "widgetsubtask.h"

WidgetSubtask::WidgetSubtask(QWidget *parent) : QFrame{parent} {
    form = nullptr;
    spin_box = nullptr;
    text_edit = nullptr;
}

WidgetSubtask::WidgetSubtask(int i, QWidget* parent) : QFrame(parent) {
    this->setStyleSheet("border-style: solid;\nborder-width: 1px;\nborder-color: black;");
    form = new QFormLayout(this);
    text_edit = new QLineEdit(this);
    text_edit->setObjectName("textEdit" + QString::number(i));
    text_edit->setFont(QFont("Segoe UI", 10));
    spin_box = new QSpinBox(this);
    spin_box->setObjectName("spinBox" + QString::number(i));
    spin_box->setFont(QFont("Segoe UI", 10));
}

WidgetSubtask::~WidgetSubtask() {
    delete form;
    delete spin_box;
    delete text_edit;
}

void WidgetSubtask::set(int i, QWidget* parent) {
    this->setStyleSheet("border-style: solid;\nborder-width: 2px;\nborder-color: black;\nbackground-color: rgb(235, 255, 255);");
    this->resize(390, 70);
    this->setParent(parent);
    form = new QFormLayout(this);
    text_edit = new QLineEdit(this);
    text_edit->setStyleSheet("background-color: rgb(255, 255, 255);");
    text_edit->setObjectName("lineEdit" + QString::number(i));
    text_edit->setMinimumWidth(300);
    text_edit->setFont(QFont("Segoe UI", 10));
    spin_box = new QSpinBox(this);
    spin_box->setStyleSheet("background-color: rgb(255, 255, 255);");
    spin_box->setObjectName("spinBox" + QString::number(i));
    spin_box->setFont(QFont("Segoe UI", 10));
    form->addRow(text_edit, spin_box);
}
