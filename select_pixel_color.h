#ifndef SELECT_PIXEL_COLOR_H
#define SELECT_PIXEL_COLOR_H

#include <QObject>

class SelectPixelColor : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // SELECT_PIXEL_COLOR_H
