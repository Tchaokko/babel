#ifndef IGRAPHIQUE
# define IGRAPHIQUE

class IGraphique
{
public:
	virtual void	show() = 0;
protected:
	virtual void	setStyleSheet() = 0;
	virtual void	getInfo() = 0;

};

#endif /*IGRAPH*/