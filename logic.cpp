#include<iostream>
int main()
{

}
/* Ellipse 1 */

position: absolute;
width: 31px;
height: 31px;
left: 55px;
top: 19px;

background: #EE0F6C;

 QPixmap pixmap1("C:/Users/HP/Documents/att/pic3.png");  // Load the image
  int newWidthheight = 636; // Desired width // Desired height
  QPixmap scaledPixmap1 = pixmap1.scaled(newWidthheight, newWidthheight, Qt::KeepAspectRatio);  // Scale the pixmap
  imageLabel1->setPixmap(scaledPixmap1);  // Set the scaled pixmap on the label
  imageLabel1->setGeometry(350, 50,newWidthheight , newWidthheight ); // Position and size the label
