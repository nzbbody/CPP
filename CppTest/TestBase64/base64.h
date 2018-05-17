#ifndef ___BASE64_H___
#define ___BASE64_H___

#include <string>

namespace Base64
{
	void Encode(std::string& outStr, const unsigned char* inData,int inSize);

	void Decode(const std::string& inStr, unsigned char*& outData,int& outSize);
}

#endif