#ifndef CENTRAL_WIDGET_H
#define CENTRAL_WIDGET_H

#include <QWidget>
#include <QPoint>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QLabel>

class CentralWidget : public QWidget {
    Q_OBJECT

public:
    CentralWidget(QWidget* parent);

};

#endif