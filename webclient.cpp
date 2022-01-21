#include "webclient.h"

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(u_address, &QLineEdit::returnPressed, this, &Webclient::on_u_goButton_clicked); //Pressing enter when entering URL starts the process as well
}

void Webclient::printMessage(QString message, QColor color)
{
    u_textOutp->clear();
    u_textOutp->setTextColor(color);
    u_textOutp->setText(message);
}

void Webclient::on_u_goButton_clicked()
{
    if(!u_address->text().isEmpty())
    {
        m_address = u_address->text();
        printMessage("Input: " + m_address, QColor::fromRgb(0, 255, 0));
    }
    else
        printMessage("Please enter an address!", QColor::fromRgb(255, 0, 0));
}
