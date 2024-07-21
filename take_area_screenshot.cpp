#include "take_area_screenshot.h"
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

void TakeAreaScreenshot::execute() {
    Sleep::msleep(10);

    QString fileName = QFileDialog::getSaveFileName(nullptr, "Save Screenshot As", "", "PNG Image (*.png);;All Files (*)");
    if (fileName.isEmpty()) {
        QMessageBox::warning(nullptr, "Error", "No file selected.");
        return;
    }

    Sleep::msleep(10);

    QMessageBox::information(nullptr, "Screenshot", "Select the area to capture.");
    QProcess::execute(QString("import %1").arg(fileName));

    QMessageBox::information(nullptr, "Screenshot", QString("Screenshot saved as %1").arg(fileName));
}
