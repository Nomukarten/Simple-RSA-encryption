#pragma once
#include "KeysGenerator.h"

class RSA
{
	public:
		static mpz_class encrypt(PubKey key, mpz_class message);
		static mpz_class decrypt(PrivKey key, mpz_class code);
};

