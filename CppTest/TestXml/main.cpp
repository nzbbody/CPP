#include "xml_utils.h"
#include <windows.h>

using namespace rapidxml;

#define XML_HEAD	"xml version='1.0' encoding='utf-8'"

typedef unsigned long DWORD;

inline void addNode(xml_document<>& doc,xml_node<>* node,const string& name,const string& value)
{
	node->append_node(doc.allocate_node(node_element, 
		doc.allocate_string(name.c_str()), doc.allocate_string(value.c_str())));
}

inline void addNode(xml_document<>& doc,xml_node<>* node,const string& name)
{
	node->append_node(doc.allocate_node(node_element, 
		doc.allocate_string(name.c_str()), NULL));
}

inline void addAttri(xml_document<>& doc,xml_node<>* node,const string& name,const string& value)
{
	node->append_attribute(doc.allocate_attribute(doc.allocate_string(name.c_str()),
		doc.allocate_string(value.c_str())));
}

void testBool(int a)
{
	printf("%d",a);
}

void WriteXml()
{
	xml_document<> xmlDoc;
	xml_node<>* xmlHead = xmlDoc.allocate_node(node_pi, xmlDoc.allocate_string(XML_HEAD)); 
	xmlDoc.append_node(xmlHead);


	xml_node<>* root = xmlDoc.allocate_node(node_element, "root",NULL); 
	xmlDoc.append_node(root);

	xml_attribute<>* hhh = xmlDoc.allocate_attribute("name","ggg"); 
	root->append_attribute(hhh);

	root->remove_attribute(hhh);
	xml_attribute<>* ddd = xmlDoc.allocate_attribute("name","tyuio");
	root->append_attribute(ddd);

	

	//addAttri(xmlDoc,root,"name","hjk");



	addNode(xmlDoc,root,"head");

	xml_node<>* body = xmlDoc.allocate_node(node_element, "body", NULL);
	addAttri(xmlDoc,body,"name","Andy");
	root->append_node(body);

	//char buf[1024] = "<aa><bb>1111</bb></aa>";
	//xml_document<> doc;
	//doc.parse<0>(buf);
	//xml_node<>* aa = doc.first_node();
	////xml_node<>* aaCpy = xmlDoc.allocate_node(node_element, "aa",aa->value()); 

	//root->append_node(xmlDoc.clone_node(aa));

	string xmlContent = ""; 
	rapidxml::print(std::back_inserter(xmlContent), xmlDoc, 0);	

	//XmlUtils::StringReplace(xmlContent,"&lt;","<");
	//XmlUtils::StringReplace(xmlContent,"&gt;",">");

	//internal::print_element_node(std::back_inserter(xmlContent), body, 0,0);
	//int aa = sizeof(DWORD);


	testBool(true);
	testBool(false);
}


void TestXml()
{
	char buf[1024] = "<?xml version='1.0' encoding='utf-8' ?><root><head>123</head><body>abc</body></root>";
	xml_document<> doc;
	doc.parse<0>(buf);
	xml_node<>* root = doc.first_node();

	for(xml_node<>* node = root->first_node(); node != NULL; node = node->next_sibling())
	{
		printf("%s:%s",node->name(),node->value());
	}

	int dd =0;
}



int  main(int argc,char* argv[])
{
	//int size =66;
	//char* aa = new char[size];

	//memset(aa,'\0',size);

	//aa[12] = 'a';

	//delete []aa;

	//int dd =0;


	//TestXml();

	//CFG_THERMO_GRAPHY_INFO info;
	//XmlUtils::ParseXml(info);


	CFG_RADIOMETRY_RULE_INFO* info1 = new CFG_RADIOMETRY_RULE_INFO;
	XmlUtils::ParseXml(*info1);

	//CFG_TEMP_STATISTICS_INFO info2;
	//XmlUtils::ParseXml(info2);

	//CFG_THERMOMETRY_INFO info3;
	//XmlUtils::ParseXml(info3);

	WriteXml();


	//vector<IisPoint> vecIisPoint;
	//XmlUtils::ParseXml(vecIisPoint);

	//vector<IisTask> vecIisTask;
	//XmlUtils::ParseXml(vecIisTask);


	//vector<IisPlan> vecIisPlan;
	//XmlUtils::ParseXml(vecIisPlan);

	//vector<IrArea> vecIrArea;
	//XmlUtils::ParseXml(vecIrArea);

	//vector<IisPlanTimeTemplate> vecPlanTime;
	//XmlUtils::ParseXml(vecPlanTime);


	system("pause");
}