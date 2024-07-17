 #include "style.h"
QString attbtn=R"(QPushButton{
                    background-color:#8852BE;
                    color:#FFFFFF;
                    font-size: 13px;
                    border-radius: 17px;}
                    QPushButton:hover{
                    background-color:#a170d2;}
                    QPushButton:pressed{
                    color:#EE0F6C;})";
QString loginbtn=R"(QPushButton{
                    background-color:#EE0F6C;
                    color:#FFFFFF;
                    font-size: 13px;
                    border-radius: 17px;}
                    QPushButton:hover{
                    background-color:#f25194;}
                    QPushButton:pressed{
                    color:#0048ff})";
QString admbtn=R"(QPushButton{
                    background-color:#8852BE;
                    color:#FFFFFF;
                    font-size: 10px;
                    border-radius: 14px;}
                    QPushButton:hover{
                    background-color:#a170d2;}
                    QPushButton:pressed{
                    color:#EE0F6C;})";
QString admbtn1=R"(QPushButton{
                    background-color:#EE0F6C;
                    color:#FFFFFF;
                    font-size: 10px;
                    border-radius: 14px;}
                    QPushButton:hover{
                    background-color:#f25194;}
                    QPushButton:pressed{
                    color:#0048ff})";
QString labelstyle="font-size: 11px; font-weight:600;color:#FFFFFF; background-color:transparent;";
QString inputstyle="background-color:#030E2C; border-radius:0px;padding: 5px;font-size: 12px; color: #FFFFF;";
QString removeback="background-color:transparent;";
QString winstyle=R"(QWidget{background-color:#051A50; color:#FFFFFF;}
 QMessageBox {
        background-color: #051A50;

    }

    QMessageBox QPushButton {
                    background-color:#8852BE;
                    color:#FFFFFF;
                    font-size: 13px;
                    border-radius: 10px;
 min-width: 100px; /* Adjust width */
        min-height: 25px; /* Adjust height */
    }

    QMessageBox QPushButton:hover {
        background-color:#a170d2;
    }

    QMessageBox QPushButton:pressed {
       color:#EE0F6C;
    }
    QMessageBox QLabel{
    background-color:transparent;
    font-size:14px;
    font-weight:500;}
)";
