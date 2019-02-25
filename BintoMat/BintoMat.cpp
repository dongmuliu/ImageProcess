#include "BintoMat.h"
using namespace cv;
using namespace std;
#define   Img_width   (320)
#define   Img_height  (240)
#define   Max_distance 30000
#define   Min_distacne 0
#define IMG_B(img,y,x) img.at<Vec3b>(y,x)[0]
#define IMG_G(img,y,x) img.at<Vec3b>(y,x)[1]
#define IMG_R(img,y,x) img.at<Vec3b>(y,x)[2]
ushort  tmp;
Mat		img_color;
Mat outmat(Img_height, Img_width, CV_16UC1);
Mat zip;

bool flag = 1;

BintoMat::BintoMat(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.openAction, SIGNAL(triggered()), this, SLOT(openFileSlot()));  //打开文件并显示转换成0~255空间的图像
	QObject::connect(ui.colorAction, SIGNAL(triggered()), this, SLOT(colorFileSlot()));//伪彩色
	QObject::connect(ui.saveAction, SIGNAL(triggered()), this, SLOT(saveFileSlot()));//保存为
}
void BintoMat::openFileSlot()
{
	//读取bin文件
	QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("bin file"), qApp->applicationDirPath(),
		QString::fromLocal8Bit("bin File(*.bin)"));//新建文件打开窗口
	if (fileName.isEmpty())//如果未选择文件便确认，即返回
		return;
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(this, "Error Message", "Please Select a bin");
		return;  //文件打开错误显示错误信息
	}
	unsigned short * imagebuf = new unsigned short[Img_width*Img_height];
	
	file.read((char*)imagebuf, Img_width*Img_height*sizeof(unsigned short));
	file.close();
	//bin文件转mat文件
	for (int i = 0; i < Img_height; i++)
	{
		for (int j = 0; j < Img_width; j++)
		{
			if (imagebuf[j + i * Img_width] < 30000)
				outmat.at<ushort>(i, j) = imagebuf[j + i * Img_width];
			else
				outmat.at<ushort>(i, j) = 30000;
			// outmat.at<uchar>(i, j) = 255 - (imagebuf[j + i * Img_width]) * 255 /30000;


		}
	}

	delete[] imagebuf;
	
	outmat.convertTo(zip, CV_8U, 25.0 / 3000, 0);
	cv::resize(zip, zip, Size(320, 240));

	   //在QT界面显示
		QImage img = QImage((const unsigned char*)(zip.data), zip.cols, zip.rows, QImage::Format_Indexed8);
		label = new QLabel();
		label->setPixmap(QPixmap::fromImage(img));
		label->resize(QSize(img.width(), img.height()));
		ui.scrollArea->setWidget(label);

	
}
void BintoMat::colorFileSlot()
{
	double mindistance = Min_distacne*25.0 / 3000;
	double maxdistance = Max_distance*25.0 / 3000;
	img_color.create(Img_height, Img_width, CV_8UC3);//构造RGB图像
	//////利用Opecv进行伪彩色映射//////////////////
	//applyColorMap(zip, zip, COLORMAP_HSV);
	//applyColorMap(zip, zip, COLORMAP_RAINBOW);
	////////////////////////////////////
	for (int y = 0; y < Img_height; y++)
	{
		for (int x = 0; x < Img_width; x++)
		{
			tmp = zip.at<uchar>(y, x);
			if (tmp < mindistance)
			{
				tmp = mindistance;
			}
			else if (tmp >maxdistance)
			{
				tmp = maxdistance;
			}
			double intervaldistance = (maxdistance - mindistance) / 5;
			if (tmp < intervaldistance)
			{
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = tmp * 255 / intervaldistance;
				IMG_R(img_color, y, x) = 0;
			}
			else if (tmp < 2 * intervaldistance)
			{
				tmp -= intervaldistance;
				IMG_B(img_color, y, x) = 255 - tmp * 255 / intervaldistance;
				IMG_G(img_color, y, x) = 255;
				IMG_R(img_color, y, x) = 0;
			}
			else if (tmp < 3 * intervaldistance)
			{
				tmp -= 2 * intervaldistance;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 255;
				IMG_R(img_color, y, x) = tmp * 255 / intervaldistance;
			}
			else if (tmp <= 4 * intervaldistance)
			{
				tmp -= 3 * intervaldistance;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 255 - uchar(128.0*tmp / intervaldistance + 0.5);
				IMG_R(img_color, y, x) = 255;
			}
			else
			{
				tmp -= 4 * intervaldistance;
				IMG_B(img_color, y, x) = 0;
				IMG_G(img_color, y, x) = 127 - uchar(127.0*tmp / intervaldistance + 0.5);
				IMG_R(img_color, y, x) = 255;
			}
		}
	}

	   //在QT界面显示(伪彩色)
		QImage img = QImage((const unsigned char*)(img_color.data), img_color.cols, img_color.rows, QImage::Format_RGB888);
		label = new QLabel();
		label->setPixmap(QPixmap::fromImage(img));
		label->resize(QSize(img.width(), img.height()));
		ui.scrollArea->setWidget(label);
	
}
void BintoMat::saveFileSlot()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.bmp *.jpg)")); //选择路径
	string fileAsSave = filename.toStdString();
	imwrite(fileAsSave, zip);
}
