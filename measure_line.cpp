#include "measure_line.h"
#include <QMessageBox>
#include <QProcess>
#include <QGuiApplication>
#include <QScreen>
#include <cmath>

class Sleep : public QThread {
public:
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
};

void MeasureLine::execute() {
    if (QSysInfo::productType() == "windows" || QSysInfo::productType() == "osx") {
        QMessageBox::information(nullptr, "Measure Line Length", "Feature not supported on this OS.");
        return;
    }

    Sleep::msleep(10);

    bool gromitInstalled = QProcess::execute("which gromit-mpx") == 0;
    if (gromitInstalled) {
        QProcess::startDetached("gromit-mpx");
    }

    QProcess xdpyinfo;
    xdpyinfo.start("xdpyinfo");
    xdpyinfo.waitForFinished();
    QString output = xdpyinfo.readAllStandardOutput();
    QString resolution = output.split("resolution:").last().split("
").first().split("x").first().trimmed();
    int DPI = resolution.toInt();

    if (QMessageBox::question(nullptr, "Measure Line", "Please select a line on your screen by clicking and dragging the mouse. Press OK to start.") == QMessageBox::No) {
        return;
    }

    Sleep::msleep(10);

    QProcess::execute("xdotool selectwindow");
    QProcess getStartCoords;
    getStartCoords.start("xdotool getmouselocation --shell");
    getStartCoords.waitForFinished();
    QString startCoords = getStartCoords.readAllStandardOutput();
    QStringList startXY = startCoords.split("
");
    int startX = startXY[0].split("=").last().toInt();
    int startY = startXY[1].split("=").last().toInt();

    Sleep::msleep(10);

    QProcess::execute("xdotool selectwindow");
    QProcess getEndCoords;
    getEndCoords.start("xdotool getmouselocation --shell");
    getEndCoords.waitForFinished();
    QString endCoords = getEndCoords.readAllStandardOutput();
    QStringList endXY = endCoords.split("
");
    int endX = endXY[0].split("=").last().toInt();
    int endY = endXY[1].split("=").last().toInt();

    int deltaX = endX - startX;
    int deltaY = endY - startY;
    double lineLengthPixels = std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
    double lineLengthInch = lineLengthPixels / DPI;
    double lineLengthCm = lineLengthInch * 2.54;

    QScreen *screen = QGuiApplication::primaryScreen();
    int screenWidth = screen->geometry().width();
    double lineLengthPercent = (lineLengthPixels / screenWidth) * 100;

    QMessageBox::information(nullptr, "Line Length Results",
                             QString("Line Length:
- Pixels: %1 px
- Inches: %2 in
- Centimeters: %3 cm
- Percentage of screen width: %4 %")
                             .arg(lineLengthPixels).arg(lineLengthInch).arg(lineLengthCm).arg(lineLengthPercent));

    if (gromitInstalled) {
        QProcess::execute("pkill gromit-mpx");
    }
}
