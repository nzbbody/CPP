#include "KeyManager.h"





AES_KEY* KeyManager::m_aesKey = NULL;

void KeyManager::Init(const string& masterKey)
{
	// init AES_KEY by masterKey
	   // AES_KEY * resKey = new AES_KEY();
    //string mkey = key;

    //// PAD KEY to be AES_KEY_BYTES bytes long
    //if (mkey.size() < AES_KEY_BYTES) {
    //  char buf[AES_KEY_BYTES];
    //  memset(buf, 0, sizeof(buf));
    //  memcpy(buf, mkey.data(), mkey.size());
    //  mkey = string(buf, sizeof(buf));
    //}

    //AES_set_encrypt_key(
    //        (const uint8_t *) mkey.data(), AES_KEY_BYTES*8, resKey);

    //LOG(all) << "cryptdb key transfrom [" << key <<"] --> AES_KEY point [" << hex << resKey <<"]";




}

string KeyManager::GetSeedKey()
{
	// get SeedKey By AES_KEY
	return "";
}

string KeyManager::EncSerialObject(const string& plainText)
{
	return plainText;
}

string KeyManager::DecSerialObject(const string& cipherText)
{
	return cipherText;
}