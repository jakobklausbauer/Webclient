#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"
#include <QDebug>
#include <QAbstractSocket>
#include <QTcpSocket>

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);

private slots:
    void on_u_goButton_clicked();

private:
    void printMessage(QString message, QColor color = QColor::fromRgb(0, 0, 0));

private:
    QTcpSocket* m_socket = nullptr;
    QString m_address;
    const unsigned char m_port = 80;
};

#endif // WEBCLIENT_H
