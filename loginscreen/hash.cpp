#include "Hash.h"


int	Hash::hashing(const char *string)
{
	int		hashed;
	int		count = 0;

	hashed = this->offset_basis;
	while (string[count])
	{
		hashed = hashed ^ string[count];
		hashed = hashed * this->FNV_prime;
		count++;
	}
	return (hashed);
}

Hash::Hash()
{
	this->FNV_prime = 16777619;
	this->offset_basis = 2166136261;
}


Hash::~Hash()
{
}
