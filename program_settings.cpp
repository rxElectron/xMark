#include "program_settings.h"
#include <QMessageBox>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void ProgramSettings::execute() {
    Sleep::msleep(10);

    QMessageBox::information(nullptr, "Program Settings", "This is a placeholder function.");
}
