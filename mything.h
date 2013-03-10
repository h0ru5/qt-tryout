#ifndef MYTHING_H
#define MYTHING_H

#include <QObject>

class MyThing : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool good READ isGood WRITE setGood)

public:
    explicit MyThing(QObject *parent = 0);

    bool isGood() {
        return m_good;
    }

    void setGood(bool good) {
        m_good=good;
        emit goodChanged(good);
    }
    
signals:
    void goodChanged(bool);
public slots:
    void beGood(bool);
private:
    bool m_good;
};

#endif // MYTHING_H
