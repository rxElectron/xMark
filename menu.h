#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

class Menu : public QMainWindow {
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
};

#endif // MENU_H
