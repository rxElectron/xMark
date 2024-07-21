#ifndef SHOW_SYSTEM_INFO_H
#define SHOW_SYSTEM_INFO_H

#include <QObject>

class ShowSystemInfo : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // SHOW_SYSTEM_INFO_H
