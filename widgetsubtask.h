#ifndef WIDGETSUBTASK_H
#define WIDGETSUBTASK_H

#include <QFrame>
#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>

class WidgetSubtask : public QFrame
{
    Q_OBJECT
private:
    QFormLayout* form;
    QSpinBox* spin_box;
    QLineEdit* text_edit;
public:
    explicit WidgetSubtask(QWidget *parent = nullptr);
    WidgetSubtask(int, QWidget* parent = nullptr);
    ~WidgetSubtask();

    void set(int, QWidget* parent = nullptr);

signals:
};

#endif // WIDGETSUBTASK_H
