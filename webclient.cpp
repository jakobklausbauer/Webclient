#include "webclient.h"
#include <thread>

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(u_address, &QLineEdit::returnPressed, this, &Webclient::on_u_goButton_clicked); //Pressing enter when entering URL starts the process as well

    m_socket = new QTcpSocket(this);
    connect(m_socket, &QTcpSocket::connected, this, &Webclient::onSocketConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &Webclient::onSocketReadyRead);
}

void Webclient::printMessage(QString message, QColor color)
{
    u_textOutp->clear();
    u_textOutp->setTextColor(color);
    u_textOutp->setText(message);
}

void Webclient::onSocketConnected()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_address + "\r\n\r\n").toLocal8Bit());
}

void Webclient::onSocketReadyRead()
{
    printMessage(m_socket->readAll());
    m_socket->disconnectFromHost();
}

void Webclient::on_u_goButton_clicked()
{
    if(!u_address->text().isEmpty())
    {
        m_address = u_address->text();

        m_socket->connectToHost(m_address, m_port);
        if(!m_socket->waitForConnected(5000))
        {
            printMessage(m_address + " - Timed out!", QColor::fromRgb(255, 0, 0));
            m_socket->reset();
        }
    }
    else
        printMessage("Please enter an address!", QColor::fromRgb(255, 0, 0));
}
