#pragma once
class Hash
{
public:
	Hash();
	~Hash();
	int	hashing(char*);

private:
	

private:
	int offset_basis;
	int	FNV_prime;
};

