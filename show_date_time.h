#ifndef SHOW_DATE_TIME_H
#define SHOW_DATE_TIME_H

#include <QObject>

class ShowDateTime : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // SHOW_DATE_TIME_H
