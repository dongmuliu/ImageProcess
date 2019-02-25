#pragma once


#include <QtWidgets/QMainWindow>
#include "ui_BintoMat.h"
#include<qfiledialog.h>
#include<qmessagebox.h>
#include<qimage.h>
#include <opencv2\opencv.hpp>
#include<QGraphicsScene>  
#include<QGraphicsView>                   //graphicsview��
#include<opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>  //opencv����
#include <qfiledialog.h>                //getopenfilename ������
#include <qlabel.h>                     //label��


#define   Img_height  (240)
class BintoMat : public QMainWindow
{
	Q_OBJECT

public:
	BintoMat(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::BintoMatClass ui;

	QLabel *label;
private slots:
	void openFileSlot();
	void colorFileSlot();
	void saveFileSlot();
};
