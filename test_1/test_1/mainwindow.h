#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QAbstractButton>
#include <QFile>
#include <QApplication>

class CommonHelper
{
public:
    static void setStyle(const QString &style) {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
#if defined(qApp)
#undef qApp
#endif
#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateDateTime();
    void upLCDTime();
    void onButtonClicked(QAbstractButton *button);


private:
    Ui::MainWindow *ui;
    void setTimer();
    QLCDNumber *m_pLCD;
    void setLCD();
    void test();
    void addQButtonGroup();
    void addQMenu();

};

#endif // MAINWINDOW_H
