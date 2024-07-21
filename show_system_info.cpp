#include "show_system_info.h"
#include <QMessageBox>
#include <QProcess>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void ShowSystemInfo::execute() {
    Sleep::msleep(10);

    QProcess uname;
    uname.start("uname -a");
    uname.waitForFinished();
    QString sysInfo = uname.readAllStandardOutput();

    QMessageBox::information(nullptr, "System Info", QString("System information:
%1").arg(sysInfo));
}
