#ifndef MEASURE_LINE_H
#define MEASURE_LINE_H

#include <QObject>

class MeasureLine : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // MEASURE_LINE_H
