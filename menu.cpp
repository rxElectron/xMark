#include "menu.h"
#include "measure_line.h"
#include "take_area_screenshot.h"
#include "take_full_screenshot.h"
#include "select_pixel_color.h"
#include "show_date_time.h"
#include "show_system_info.h"
#include "calculate_disk_usage.h"
#include "program_settings.h"
#include <QMenuBar>
#include <QAction>
#include <QApplication>

Menu::Menu(QWidget *parent) : QMainWindow(parent) {
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *measureAction = new QAction(tr("Measure Line Length"), this);
    connect(measureAction, &QAction::triggered, this, &MeasureLine::execute);
    fileMenu->addAction(measureAction);

    QAction *areaScreenshotAction = new QAction(tr("Take Area Screenshot"), this);
    connect(areaScreenshotAction, &QAction::triggered, this, &TakeAreaScreenshot::execute);
    fileMenu->addAction(areaScreenshotAction);

    QAction *fullScreenshotAction = new QAction(tr("Take Full Screenshot"), this);
    connect(fullScreenshotAction, &QAction::triggered, this, &TakeFullScreenshot::execute);
    fileMenu->addAction(fullScreenshotAction);

    QAction *pixelColorAction = new QAction(tr("Select Pixel Color"), this);
    connect(pixelColorAction, &QAction::triggered, this, &SelectPixelColor::execute);
    fileMenu->addAction(pixelColorAction);

    QAction *dateTimeAction = new QAction(tr("Show Date and Time"), this);
    connect(dateTimeAction, &QAction::triggered, this, &ShowDateTime::execute);
    fileMenu->addAction(dateTimeAction);

    QAction *systemInfoAction = new QAction(tr("Show System Info"), this);
    connect(systemInfoAction, &QAction::triggered, this, &ShowSystemInfo::execute);
    fileMenu->addAction(systemInfoAction);

    QAction *diskUsageAction = new QAction(tr("Calculate Disk Usage"), this);
    connect(diskUsageAction, &QAction::triggered, this, &CalculateDiskUsage::execute);
    fileMenu->addAction(diskUsageAction);

    QAction *settingsAction = new QAction(tr("Program Settings"), this);
    connect(settingsAction, &QAction::triggered, this, &ProgramSettings::execute);
    fileMenu->addAction(settingsAction);

    QAction *exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, &QAction::triggered, this, &QApplication::quit);
    fileMenu->addAction(exitAction);
}

Menu::~Menu() {}
