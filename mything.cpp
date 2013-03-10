#include "mything.h"

MyThing::MyThing(QObject *parent) :
    QObject(parent)
{

}
void MyThing::beGood(bool good) {
    this->m_good=good;
    emit goodChanged(good);
}
