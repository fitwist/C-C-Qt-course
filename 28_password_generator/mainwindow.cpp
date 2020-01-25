#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    srand((unsigned int) time(nullptr));

    setMinimumHeight(400);
    setMinimumWidth(500);

    setWindowTitle("Генератор паролей");

    gl_main = new QGridLayout;

    vbl_settings = new QVBoxLayout;

    gb_settings = new QGroupBox;
    gb_settings->setLayout(vbl_settings);
    gb_settings->setTitle("Параметры");
    gl_main->addWidget(gb_settings, 3, 0);

    pb_generate = new QPushButton;
    pb_generate->setText("Сгенерировать");
    QObject::connect(pb_generate, SIGNAL(clicked(bool)), this, SLOT(generate()));
    gl_main->addWidget(pb_generate, 2, 0);

    pb_clipboard = new QPushButton;
    pb_clipboard->setText("Экспортировать");
    pb_clipboard->setHidden(true);
    QObject::connect(pb_clipboard, SIGNAL(clicked(bool)), this, SLOT(copy()));
    gl_main->addWidget(pb_clipboard, 5, 0);

    ll_passwordLength = new QLabel;
    ll_passwordLength->setText("Сгенерированный пароль: ");
    vbl_settings->addWidget(ll_passwordLength);

    sb_length = new QSpinBox;
    sb_length->setValue(12);
    sb_length->setMinimum(3);
    sb_length->setMaximum(60);
    vbl_settings->addWidget(sb_length);

    sb_passname = new QLineEdit;
    sb_passname->setText("Название пароля");
    vbl_settings->addWidget(sb_passname);

    cb_withLowers = new QCheckBox;
    cb_withLowers->setText("Включить строчные буквы");
    cb_withLowers->setChecked(true);
    vbl_settings->addWidget(cb_withLowers);

    cb_withUppers = new QCheckBox;
    cb_withUppers->setText("Включить прописные буквы");
    cb_withUppers->setChecked(true);
    vbl_settings->addWidget(cb_withUppers);

    cb_withNumbers = new QCheckBox;
    cb_withNumbers->setText("Включить цифры");
    cb_withNumbers->setChecked(true);
    vbl_settings->addWidget(cb_withNumbers);

    cb_withSpecials = new QCheckBox;
    cb_withSpecials->setText("Включить спецсимволы");
    cb_withSpecials->setChecked(false);
    vbl_settings->addWidget(cb_withSpecials);

    ll_password = new QLabel;
    ll_password->setText("Пароль");
    ll_password->setHidden(true);
    gl_main->addWidget(ll_password, 4, 0);

    setLayout(gl_main);
}

MainWindow::~MainWindow()
{
    delete gl_main;
    delete vbl_settings;
    delete gb_settings;
    delete pb_generate;
    delete pb_clipboard;
    delete ll_password;
}

void MainWindow::generate()
{
    if (!cb_withLowers->isChecked() && !cb_withUppers->isChecked() && !cb_withNumbers->isChecked() && !cb_withSpecials->isChecked())
    {
        QMessageBox::critical(this, "Неверный ввод", "Отметьте хотя бы один чекбокс");
        return;
    }

    QString list = "";

    if (cb_withLowers->isChecked())
        list.append("abcdefghijklmnopqrstuvwxyz");
    if (cb_withUppers->isChecked())
        list.append("ABCDEFGHIFKLMNOPQRSTUVWXYZ");
    if (cb_withNumbers->isChecked())
        list.append("0123456789");
    if (cb_withSpecials->isChecked())
        list.append("@%ù$()[]><.,-;_");

    QString pass = "";
    for (int i = sb_length->value(); i > 0; i--)
    {
        pass.append(list.at(rand() % list.length()));
    }

    ll_password->setText(pass);
    ll_password->setHidden(false);
    pb_clipboard->setHidden(false);
}

void MainWindow::copy() {

//    QClipboard *myClipBoard = QApplication::clipboard();
//    myClipBoard->setText(ll_password->text());

    QFile file("/Users/helenkapatsa/Repositories/C-C-Qt-course/28_password_generator/password.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << sb_passname->text() << ": " << ll_password->text() << "\n";
}

