#ifndef CALCULATE_DISK_USAGE_H
#define CALCULATE_DISK_USAGE_H

#include <QObject>

class CalculateDiskUsage : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // CALCULATE_DISK_USAGE_H
