#include "myfirstwindow.h"
#include "ui_myfirstwindow.h"
#include <QtGui>

MyFirstWindow::MyFirstWindow(QWidget *parent) :QWidget(parent),
    ui(new Ui::MyFirstWindow),thing(new MyThing)
{
    //ui->setupUi(this);
    this->setWindowTitle(tr("Schlorrps"));
    QGridLayout *layout = new QGridLayout();

    bla = new QLabel(tr("Wahoo!"));
    blubb = new QLineEdit;
    blo = new QLabel(tr("Hier"));

    layout->addWidget(bla,0,0);
    layout->addWidget(blubb,0,1);
    layout->addWidget(blo,1,0);

     setLayout(layout);

     //connect(blubb,SIGNAL(textEdited(QString)),blo,SLOT(setText(QString)));
    connect(blubb,SIGNAL(textEdited(QString)),this,SLOT(on_textChanged(QString)));
    connect(this,SIGNAL(statusCheck(bool)),thing,SLOT(beGood(bool)));
    connect(thing,SIGNAL(goodChanged(bool)),this,SLOT(showStatus(bool)));


}

void MyFirstWindow::showStatus(bool ok) {
    QString s("the thing is ");
    if(ok)
        s.append("good");
    else
        s.append("bad");

    blo->setText(s);
}

void MyFirstWindow::on_textChanged(const QString &text) {
    //blo->setText(text);
    setWindowTitle(text);
    bool res = !text.compare(tr("ok"));
    qDebug() << "Checking " << text << " result " << res;

    emit statusCheck(res);
}

MyFirstWindow::~MyFirstWindow()
{
    delete bla;
    delete blubb;
    delete blo;
    delete ui;
}
