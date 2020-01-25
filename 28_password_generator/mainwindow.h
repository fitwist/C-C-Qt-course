#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QWidget>
#include <QApplication>
#include <QLineEdit>
#include <QTextStream>
#include <QClipboard>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void generate();
    void copy();

private:
    QGridLayout *gl_main;

    QVBoxLayout *vbl_settings;

    QGroupBox *gb_settings;

    QPushButton *pb_generate;
    QPushButton *pb_clipboard;

    QSpinBox *sb_length;
    QLineEdit *sb_passname;

    QCheckBox *cb_withLowers;
    QCheckBox *cb_withUppers;
    QCheckBox *cb_withNumbers;
    QCheckBox *cb_withSpecials;

    QLabel *ll_password;
    QLabel *ll_passwordLength;
};

#endif // MAINWINDOW_H
