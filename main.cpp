#include <QApplication>
#include "MainWindow.h"
#include "AddStudentWindow.h"
#include "LoginWindow.h"
#include "AdminWindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
   //  AdminWindow addstwin;
   // addstwin.show();

    return app.exec();
}
