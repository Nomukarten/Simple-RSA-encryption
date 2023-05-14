#include "RSA.h"

mpz_class RSA::encrypt(PubKey key, mpz_class message)
{
	mpz_class c;
	if (message >= key.mod)
		return NULL;

	mpz_powm(c.get_mpz_t(), message.get_mpz_t(),
		key.exp.get_mpz_t(), key.mod.get_mpz_t());
	return c;
}

mpz_class RSA::decrypt(PrivKey key, mpz_class code)
{
	mpz_class m;
	if (code >= key.mod)
		return NULL;

	mpz_powm(m.get_mpz_t(), code.get_mpz_t(),
		key.exp.get_mpz_t(), key.mod.get_mpz_t());
	return m;
}
