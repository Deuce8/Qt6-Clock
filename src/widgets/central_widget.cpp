#include "widgets/central_widget.hpp"

// ------------------------------------------------
// |                 Constructor                  |
// ------------------------------------------------

CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent) {
    setObjectName("central_widget");
    setAttribute(Qt::WA_StyledBackground, true);
    resize(512, 48);

    QLabel* time_label = new QLabel(this);
    QLabel* date_label = new QLabel(this);
    QVBoxLayout* layout = new QVBoxLayout(this);

    time_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
    date_label->setAlignment(Qt::AlignmentFlag::AlignCenter);

    date_label->setText(QDate::currentDate().toString("MMMM dd"));
    time_label->setText(QTime::currentTime().toString("hh:mm:ss AP"));

    layout->addWidget(time_label);
    layout->addWidget(date_label);

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, [time_label]() {
        time_label->setText(QTime::currentTime().toString("hh:mm:ss AP"));
    });

    timer->start(1000);
}