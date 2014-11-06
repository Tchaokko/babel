#ifndef HASH_H_
# define HASH_H_

class Hash
{
public:
	Hash();
	~Hash();
	int	hashing(const char*);

private:
	

private:
	int offset_basis;
	int	FNV_prime;
};

#endif /* HASH_H_*/