#include "show_date_time.h"
#include <QMessageBox>
#include <QDateTime>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void ShowDateTime::execute() {
    Sleep::msleep(10);

    QString dateTime = QDateTime::currentDateTime().toString();
    QMessageBox::information(nullptr, "Date and Time", QString("Current date and time:
%1").arg(dateTime));
}
