#ifndef TAKE_AREA_SCREENSHOT_H
#define TAKE_AREA_SCREENSHOT_H

#include <QObject>

class TakeAreaScreenshot : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // TAKE_AREA_SCREENSHOT_H
