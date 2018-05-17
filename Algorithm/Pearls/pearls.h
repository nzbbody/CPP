#ifndef PEARLS_H_
#define PEARLS_H_

#include <string>
#include <vector>
#include <map>


using namespace std;

typedef unsigned char uint_8;

namespace Pearls
{
	template <typename T>
	void Swap(T& lhs,T& rhs)
	{
		T tmp(lhs);
		lhs = rhs;
		rhs = tmp;
	}

	/*
		1、考虑下面的需求，对文件中的1亿个32位整数排序，这些整数不重复。
			使用new int[1亿]，从文件中读取所有的整数，放入数组，排序。这种方法不可以行，因为需要的内存太大。
			怎么解决这个问题？
		2、使用位向量表示整数，也就是第n个bit，表示整数n，bit的取值为整数出现的次数，0没有出现,1出现。
			而上面的方法，整数需要4个字节，32bit表示。因此，位向量只用到原来的32分之1。
			注意：如果重复次数不超过3，使用两个bit表示一个整数。也就是第2n-1和第2n个bit表示整数n，
			这两个bit的取值表示出现次数。
		3、为了简化问题，考虑30个整数，使用位向量排序。
			new出32bit的内存，也就是4个字节。从文件中遍历读取整数，在对应的第n个bit，把bit置为1
			遍历位向量，输出bit值为1的位置。
		4、位向量也就是，第n个bit表示整数n，bit的取值为整数n出现的次数。
		5、考虑，如果文件中的数字更多，比如说有40亿，怎么处理？
			多趟处理，第一趟遍历40亿整数，过滤出大于等于0,小于1亿[0,1亿)，排序输出到目标文件,
			第二趟遍历40亿整数，过滤出大于等于1亿,小于2亿[1亿,2亿)，排序输出到目标文件。
	*/
	void SetBitValue(uint_8* start,int index,int value);
	int  GetBitValue(uint_8* start,int index);
	void ReadFileAndSetBitVec(uint_8* bitVec);
	void PrintBitVec(uint_8* bitVec);



	/*
		1、考虑下面的需求，给出包含单词的文档，找出其中的变位词。所谓的变位词，比如dog，god互为变位词。
		2、最笨的办法是，dog不动，对god，cat进行排列组合，看看是否存在于dog相同的情况，存在就是变位词。
		3、上面的办法效率太差，很长的单词，排列组合很多，cpu开销太大。怎么解决？
		4、变位词的特点是，大家所包含的字符相同，只不过排列组合不同。包含的字符，可以认为是单词的标识符，
			标识符按字符顺序排列好，互为变位词，也就是说标识符相同。因此，解决思路是，对每个单词求标识符，
			比较标识符，相同就是变位词。
		5、使用map，key是标识符（可能是一个无效的单词），value是vector，保存互为变位词的单词集合。
		6、更广泛的用处，比如使用搜狗输入法输入 ty，就会提示 统一，同意，同义等等。这种情况也类似，对
			统一，同意，同义求标识符，放入map的key，value保存这些词。
	*/
	string GetIdentifier(const string& word);
	int    CharCmp(const void* a,const void* b);
	bool   IsSeparator(char ch);
	void   GetWord(vector<string>& wordVec,char* buf);
	void   ReadWordFromFile(vector<string>& wordVec);


	/*
		1、循环移位，对于abcdefgh，向左循环移动3位，成为defghabc，给出一个字符数组和需要移动的位数n，输出结果。
		2、一场考虑，字符指针为NULL，对于8个字符，左移11位等价于左移3位。
		3、方法一：从头部取出一个字符，后面的依次左移，取出的字符放入尾部，执行n次。
		4、方法一的cpu开销大，方法二是：分配n个字节的缓冲区，从头部取出n个字节，后面的字符左移n位，取出的n字节
			字符放入尾部。
		5、方法二的内存开销大，需要多分配n字节字符。方法三，利用循环左移的特点，循环左移3位等价于前面3个反转，
			后面的字符反转，然后整个字符串反转。如下：abcdefgh-->cbadefgh-->cbahgfed-->defghabc
	*/

	void LoopMove(char* pc,int moveSize);
	void Reverse(char* first,char* last);


	/*
		1、考虑字符串1234，输出全排列，如下：1234,1243,1324,1342,1423,1432，.....
		2、思路一,初始左边为"",右边为1234，递归结束条件是右边只有一个字符，输出左边，和右边的一个字符。
		3、思路二，全排列，最小是1234，最大是4321，从1234开始，找出下一个比1234大，且差值最小的排列，
			一直找到4321结束。
	*/
	void PrintTotalOrder(const string& str);
	void PrintOrder(const string& prefix,const string& other);
	void PrintOrder_2(const string& str);
	bool Next(string& str);
	void ReverseString(string& str,int left,int right);

	
	// 统计字符个数
	void GetCharCountByMap(const string& str);
	void GetCharCountByHashTable(const string& str);



	/*
		1、产生随机数[0,5)，也就是说得到数字0,1,2,3,4的概率都是1/5，现在考虑，已有方法Random_7
			根据这个方法，构造方法Random_5_By_Random_7，怎么办？
		2、这是一个大范围的随机数，像小范围映射，解决办法很简单，就是对5取模。但是仔细想想，就发现不对，
			Random_7产生[0,7)每个数字的概率都是1/7，如果直接对5取模，导致0,1的概率是2/7,而2,3,4的概率
			是1/7，这显然不满足随机数的要求。
		3、怎么解决上面的问题？
			原因是：大范围向小范围映射，由于不能整除，导致部分数字的概率增加，解决办法就是，去掉超出的部分，
			比如Random_5_By_Random_7，如果Random_7产生的随机数>=5，重新再产生，一直循环下去，直到产生的数字
			满足要求。
		4、那这样产生[0,5)每个数字的概率是多少呢？是1/7吗？
			错，还是1/5, 为什么？从数学角度来看，以0为例，概率为：
			第1次产生0：1/7 
			第2次产生0：2/7*(1/7)		//前面1次产生的是5,6，再试第2次
			第3次产生0：(2/7)^2*(1/7)	//前面2次产生的是5,6，再试第3次
			....
			总概率 1/7+2/7*(1/7)+(2/7)^2*(1/7)... = 1/7*((2/7)^0+(2/7)^1+(2/7)^2+...)
			等比数列求和，设y=1+n+n^2+n^3+....
			则ny=n+n^2+n^3+n^4.... 相减，得到
			(1-n)y=1-n^m，其中n小于1，m为无穷大，则y = 1/(1-n),n为2/7,则y为7/5
			产生0的概率为 1/7*(7/5) = 1/5
		5、那接着思考，Random_7_By_Random_5，该怎么实现呢？
			先考虑Random_10_By_Random_5，当然不能直接映射。如果直接映射，[0,5)都是1/5，[5,10)都是0
			容易想到的办法是 2*Random_5,这个也不对，这样的话，1的概率是0,2的概率是1/5
			那么Random_5+Random_5，不对，0的概率是1/5*(1/5)=1/25
			而我们期望的是[1,10)每个数字的概率都是1/10
		6、怎么解决上面的问题？
			必须是从大范围向小范围映射值，同时裁剪掉不满足条件的数字，继续下去。怎么扩大Random_5呢？
			连续产生两次，范围就是5*5=25，对7取余，去掉21,22,23,24			
	*/
	int Random_5();
	int Random_7();
	int Random_5_By_Random_7();
	int Random_7_By_Random_5();

	/*
		1、从[0,7)中随机产生两个数，解决办法是调用两次 Random_7，共有49种组合。
		2、考虑，从[0,7)中随机选择两个不重复的数字，这与上面的情况完全不同。这种情况要保证：
			每个数字被选中的概率是2/7
		3、怎么办？
			容易想到的办法是，遍历[0,7), 每次产生一个随机数，随机数对7取模，小于2【概率是2/7】,
			表示当前数字被选中。如下：
			int Select_2_From_7(vector<int>& intVec)
			{
				intVec.clear();
				for(int i=0;i<7;++i)
				{
					if(Random_7()%7 <2)
					{
						intVec.push_back(i);
					}
				}
				return 0;
			}
		4、这个做法有问题，我们要保证intVec的size为2，上面的做法会导致intVec的size不确定。
			因为上面遍历的时候，把每个数字被选的事件当成了互不关联的独立事件，这个是错误的。
			考虑，1被选的情况，跟0是否被选有关系：
			0被选[2/7]，1被选的概率为1/6
			0没有被选[5/7]，1被选的概率为2/6
			1被选的总概率为 2/7*(1/6)+5/7*(2/6)=2/7
		5、思路是：对于0，是从7个里面选，对于1，是从6个里面选，对于2是从5个里面选，也就是说，
			遍历过程中，分母是一直减小的。每次选中一个，分子减少1
	*/
	int Select_2_From_7(vector<int>& intVec);
	
	/*
		1、
	*/
	//void n_queen;
}


#endif