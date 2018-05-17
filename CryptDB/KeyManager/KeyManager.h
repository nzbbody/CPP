#ifndef _KEY_MANAGER_
#define _KEY_MANAGER_

#include <string>

using namespace std;

class __declspec(dllexport) KeyManager
{
public:
	static void Init(const string& masterKey);
	static string GetSeedKey();
	static string EncSerialObject(const string& plainText);
	static string DecSerialObject(const string& cipherText);

private:
	static AES_KEY* m_aesKey;
};

#endif