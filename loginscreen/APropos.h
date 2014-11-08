#ifndef APROPOS_H_
# define APROPOS_H_
# include "IGraphique.h"

class						APropos : public IGraphique
{
	Q_OBJECT
public:
							APropos();
	virtual					~APropos();
	virtual QString const 	&getInfo();
	virtual void			show();

private:
	virtual void			setStyleSheet();
private slots:
void					closeAPropos();
};

#endif /* APROPOS_H_*/