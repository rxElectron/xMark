#include "take_full_screenshot.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void TakeFullScreenshot::execute() {
    Sleep::msleep(10);

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save Screenshot As", "", "PNG Image (*.png);;All Files (*)");
    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "Error", "No file selected.");
        return;
    }

    Sleep::msleep(10);

    QProcess::execute(QString("import -window root %1").arg(fileName));

    QMessageBox::information(nullptr, "Screenshot", QString("Full screenshot saved as %1").arg(fileName));
}
