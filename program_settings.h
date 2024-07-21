#ifndef PROGRAM_SETTINGS_H
#define PROGRAM_SETTINGS_H

#include <QObject>

class ProgramSettings : public QObject {
    Q_OBJECT

public:
    static void execute();
};

#endif // PROGRAM_SETTINGS_H
