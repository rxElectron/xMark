#include "calculate_disk_usage.h"
#include <QMessageBox>
#include <QProcess>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void CalculateDiskUsage::execute() {
    Sleep::msleep(10);

    QProcess df;
    df.start("df -h");
    df.waitForFinished();
    QString diskUsage = df.readAllStandardOutput();

    QMessageBox::information(nullptr, "Disk Usage", QString("Disk usage:
%1").arg(diskUsage));
}
