#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>
#include <QLibrary>

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
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

    int ret = gAdd(1, 3);
    QMessageBox::information(NULL, "Title", "c++ call result:" + QString::number(ret));
    FreeLibrary(hTry);
#else
    #if defined(linux) || defined(__LYNX)
        void *handle = dlopen("libQtDll.so",RTLD_LAZY);
    #endif

    #if defined(TARGET_OS_MAC) || defined(TARGET_OS_IPHONE)
        void *handle = dlopen("libQtDll.dylib",RTLD_LAZY);
    #endif

    if(!handle)
    {
        QMessageBox::information(NULL, "Title", "dlopen can not find QtDll.dylib");
        return;
    }

    gAdd = (fnadd)dlsym(handle,"add");
    if(gAdd == nullptr) {
        QMessageBox::information(NULL, "Title", "empty");
        return;
    }

    int ret = gAdd(1, 2);
    QMessageBox::information(NULL, "Title", "c++ call result:" + QString::number(ret));
    dlclose(handle);
#endif
}

void MainWindow::on_pushButton_2_pressed()
{
    //qt:windows,linux,mac
    QLibrary libDll;

#if defined(_WIN32)
    libDll.setFileName("QtDll.dll");
#endif

#if defined(linux) || defined(__LYNX)
    libDll.setFileName("QtDll.so");
#endif

#if defined(TARGET_OS_MAC) || defined(TARGET_OS_IPHONE)
    libDll.setFileName("QtDll.dylib");
#endif

    if(!libDll.load())
    {
        QMessageBox::information(NULL, "Title", "can not find QtDll.dylib");
        return;
    }

    gAdd =(fnadd)libDll.resolve("add");

    if(gAdd == nullptr){
        QMessageBox::information(NULL, "Title", "empty");
        return;
    }

    int ret = gAdd(2, 3);
    QMessageBox::information(NULL, "Title", "qt call result:" + QString::number(ret));
    libDll.unload();
}
