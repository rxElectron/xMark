#ifndef TAKE_FULL_SCREENSHOT_H
#define TAKE_FULL_SCREENSHOT_H

#include <QObject>

class TakeFullScreenshot : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // TAKE_FULL_SCREENSHOT_H
