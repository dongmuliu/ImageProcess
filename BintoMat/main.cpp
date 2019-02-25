#include "BintoMat.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BintoMat w;
	w.show();
	return a.exec();
}
