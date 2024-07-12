#include <QApplication>
#include "MainWindow.h"
#include "AddStudentWindow.h"
#include "LoginWindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    LoginWindow addstwin;
   addstwin.show();

    return app.exec();
}
