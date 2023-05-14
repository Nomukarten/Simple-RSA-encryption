#include "KeysGenerator.h"


void KeysGenerator::generateKeys(PubKey& public_key, PrivKey& private_key)
{
	getPrimes();
	getPublicKey();
	public_key = pub_key;
	getPrivateKey(public_key);
	private_key = priv_key;
}

void KeysGenerator::getPrimes()
{
	gmp_randclass	rand(gmp_randinit_default);
	mpz_class				sd, mp_rand;
	mpz_class				tmp_time;

	tmp_time = static_cast <unsigned int> (time(NULL));
	sd = tmp_time * tmp_time;
	rand.seed(sd);

	mp_rand = rand.get_z_bits(1024);
	mpz_nextprime(val.p.get_mpz_t(), mp_rand.get_mpz_t()); 
	//cant use normal prime number finding because of large value

	mp_rand = rand.get_z_bits(1024);
	mpz_nextprime(val.q.get_mpz_t(), mp_rand.get_mpz_t());

	val.n = val.p * val.q;
	val.phi = (val.p - 1) * (val.q - 1);
}

void KeysGenerator::getPublicKey()
{
	mpz_class m(val.phi);
	unsigned long	i;

	//find prime number for val.n
	for (i = 65538; i < ULONG_MAX; i++)
	{
		//mpz_gcd_ui finds the common diviser between two elements
		if (mpz_gcd_ui(NULL, m.get_mpz_t(), i) == 1)
			break;
	}

	// Set public exponent and modulus
	pub_key.exp = i;
	pub_key.mod = val.n;
	
}

void KeysGenerator::getPrivateKey(PubKey key)
{

	mpz_class	e(key.exp);
	mpz_class	m(val.phi);

	// d = d^-1 (mod m) 
	if (!mpz_invert(priv_key.exp.get_mpz_t(), e.get_mpz_t(), m.get_mpz_t()))
		return;

	priv_key.mod = key.mod;
}
