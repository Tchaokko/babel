#ifndef IGRAPHIQUE
# define IGRAPHIQUE
# include "Babel.h"

class IGraphique : public Babel
{
public:
	virtual void	show() = 0;
protected:
	virtual void	setStyleSheet() = 0;
	virtual void	getInfo() = 0;

};

#endif /*IGRAPH*/