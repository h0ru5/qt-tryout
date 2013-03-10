#ifndef MYFIRSTWINDOW_H
#define MYFIRSTWINDOW_H

#include "mything.h"
#include <QtGui>

namespace Ui {
class MyFirstWindow;
}

class MyFirstWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MyFirstWindow(QWidget *parent = 0);
    ~MyFirstWindow();
    
private:
    Ui::MyFirstWindow *ui;
    QLabel *bla ;
    QLabel *blo ;
    QLineEdit *blubb;
    MyThing *thing;

private slots:
    void on_textChanged(const QString & text);
    void showStatus(bool);

signals:
    void statusCheck(bool);
};

#endif // MYFIRSTWINDOW_H
