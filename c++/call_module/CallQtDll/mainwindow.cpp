#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>

#ifdef WIN32
#include <windows.h>
#else

#endif

typedef int (__cdecl *fnadd)(int a, int b);
fnadd gAdd = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{
#ifdef WIN32
    HMODULE hTry = LoadLibrary(L"QtDll.dll");
    if(hTry == nullptr)
    {
       QMessageBox::information(NULL, "Title", "can not find QtDll.dll");
       return;
    }

    gAdd = (fnadd)GetProcAddress(hTry, "add");

    if(gAdd == nullptr){
         QMessageBox::information(NULL, "Title", "empty");
        return;
    }

    int x = gAdd(1, 3);
    QMessageBox::information(NULL, "Title", QString::number(x));
    FreeLibrary(hTry);
#else

#endif
}
