#include <QApplication>
#include "MainWindow.h"
#include "AddStudentWindow.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();
    AddStudentWindow addstwin;
    addstwin.show();

    return app.exec();
}
