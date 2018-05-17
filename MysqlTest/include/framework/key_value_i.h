

#ifndef _KEY_VALUE_I_H
#define _KEY_VALUE_I_H

#include <my_json/json.h>
#include <data_types.h>

class keyValueI : public myJson::Value
{
public:
	keyValueI(){}
	keyValueI(myJson::Value &v)
		: myJson::Value(v)
	{}
	keyValueI(t_int8* ptr) : myJson::Value(ptr)
	{}
private:
	
};


class keyValueStyledWriterI : public myJson::StyledWriter
{
};

class keyValueFastWriterI : public myJson::FastWriter
{
};


class keyValueReaderI : public myJson::Reader
{
public:

};

#endif

