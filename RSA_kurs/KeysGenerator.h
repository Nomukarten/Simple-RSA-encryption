#pragma once
#include <gmpxx.h>
#include <ctime>

struct Values
{
	mpz_class p;
	mpz_class q;

	mpz_class n;
	mpz_class phi;
};
struct PubKey
{
	mpz_class exp;
	mpz_class mod;
};
struct PrivKey:PubKey
{
};
class KeysGenerator
{
	public:
		void generateKeys(PubKey& public_key, PrivKey& private_key);

	private:
		Values val;
		PubKey pub_key;
		PrivKey priv_key;

		void getPrimes();
		void getPublicKey();
		void getPrivateKey(PubKey key);
};

