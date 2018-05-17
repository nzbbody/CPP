// TestRapidXml.cpp : Defines the entry point for the console application.

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

#include <stdio.h>
#include <string>
#include <map>
using namespace std;
using namespace rapidxml;

bool ParseXml2Map(map<string,string>& outMap,const string& inXml)
{
	try
	{
		xml_document<char> doc;
		doc.parse<0>(doc.allocate_string(inXml.c_str()));
		xml_node<char>* root = doc.first_node("root");

		for(xml_node<char>* node = root->first_node(); node != NULL; node = node->next_sibling())
		{
			outMap[node->name()] = node->value();
		}
	}
	catch(parse_error& e)
	{
		printf("Parse Xml Err[%s] Where[%s]", 
			e.what(),
			e.where<char>());
		return false;
	}
	return true;
}

bool PacketMap2Xml(string& outXml,const map<string,string>& inMap)
{
	try
	{
		xml_document<char> doc;
		xml_node<char>* root = doc.allocate_node(node_element, "root");
		doc.append_node(root);

		for(map<string,string>::const_iterator iter = inMap.begin(); iter != inMap.end(); ++iter)
		{
			xml_node<char>* ele = doc.allocate_node(node_element,iter->first.c_str(),iter->second.c_str());
			root->append_node(ele);
		}
		print(back_inserter(outXml), doc, 0);
	}
	catch (...)
	{
		return false;
	}
	return true;
}






void TestRapidXml()
{
	char* xmlContent = new char[1024];
	sprintf(xmlContent,"<root><head>aaa</head><body x=\"10\">bbb</body></root>");

	xml_document<> xmlDoc;
	xmlDoc.parse<0>(xmlContent);
	//xmlDoc.parse<parse_non_destructive>(xmlContent);

	xml_node<>* root = xmlDoc.first_node();

	string xmlStr = "";
	rapidxml::print(std::back_inserter(xmlStr),xmlDoc,0); 
	
	delete []xmlContent;
}

/*
int main(int argc, char* argv[])
{
	char* aaa = new char[4];
	sprintf(aaa,"1111111111111111");


	string outXml;
	try
	{
		xml_document<char> doc;
		xml_node<char>* root = doc.allocate_node(node_element, "root");
		doc.append_node(root);

		xml_node<char>* aaa = doc.allocate_node(node_element,
			doc.allocate_string("aaa"));
		root->append_node(aaa);

		aaa->append_attribute(doc.allocate_attribute("name","sufeng"));

		xml_node<char>* bbb = doc.allocate_node(node_element,
			doc.allocate_string("bbb"),doc.allocate_string("222"));
		aaa->append_node(bbb);

		print(back_inserter(outXml), doc, 0);

		FILE* pFile = fopen("qqqqqq.xml", "wb+"); // Ð´ÎÄ¼þ
		fwrite(outXml.c_str(), outXml.size(), 1, pFile);
		fclose(pFile);

		int hh =0;
	}
	catch (...)
	{
		return false;
	}
	



	map<string,string> inMap;
	inMap["111"] = "aaa";
	inMap["222"] = "bbb";
	inMap["333"] = "ccc";


	//string outXml;
	PacketMap2Xml(outXml,inMap);


	string inXml = outXml;
	map<string,string> outMap;
	ParseXml2Map(outMap,inXml);


	TestRapidXml();

	//getchar();
	return 0;
}
*/




int main(int argc, char* argv[])
{
	using namespace std;
	string aaa = "20170117T165514Z";

	string bbb = aaa.substr(0,4)+"-"+aaa.substr(4,2)+"-"+aaa.substr(6,2)+" "
		+aaa.substr(9,2)+":"+aaa.substr(11,2)+":"+aaa.substr(13,2);




	char* xmlContent = new char[1024];
	sprintf(xmlContent,"<root><aaa>1</aaa><bbb>hhh&kkk</bbb></root>");

	xml_document<> xmlDoc;
	xmlDoc.parse<0>(xmlContent);
	
	xml_node<>* root = xmlDoc.first_node();

	xml_node<>* ccc = root->first_node("ccc");
	if(ccc == NULL)
	{
		xml_node<char>* ele = xmlDoc.allocate_node(node_element,"ccc","xxx&yyy");
		root->append_node(ele);
	}

	string xmlStr = "";
	rapidxml::print(std::back_inserter(xmlStr),xmlDoc,0); 

	return 0;
}