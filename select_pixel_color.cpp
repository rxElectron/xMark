#include "select_pixel_color.h"
#include <QColorDialog>
#include <QMessageBox>
#include <QThread>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void SelectPixelColor::execute() {
    Sleep::msleep(10);

    QColor color = QColorDialog::getColor(Qt::white, nullptr, "Select Pixel Color");
    if (!color.isValid()) {
        QMessageBox::warning(nullptr, "Error", "No color selected.");
        return;
    }

    QMessageBox::information(nullptr, "Pixel Color", QString("The selected pixel color is %1.").arg(color.name()));
}
