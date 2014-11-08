#ifndef IGRAPHIQUE
# define IGRAPHIQUE
#include <qobject.h>
#include <qlistwidget.h>
#include <HandleSocket.h>
#include <HandleProtocol.h>
#include <InterfaceProtocol.h>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qpushbutton.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qgridlayout.h>
#include <QtWidgets\qmenu.h>
#include <QtWidgets\qmenubar.h>
#include "InternalProtocol.h"
#include <sstream>

class IGraphique : public QObject
{
public:
	virtual void	show() = 0;
	virtual QString	const getInfo() = 0;
protected:
	virtual void	setStyleSheet() = 0;
	QWidget			*widget;
	QGridLayout		*layout;
	QLineEdit		*field1;
	QLineEdit		*field2;
	QLineEdit		*field3;
	QLabel			*label1;
	QLabel			*label2;
	QLabel			*label3;
	QPushButton		*button1;
	QPushButton		*button2;
};

#endif /*IGRAPH*/