#ifndef SORT_H__
#define SORT_H__

#include <vector>
using namespace std;

namespace Niuzb
{
	namespace Algorithm
	{
		template <typename T>
		void Swap(T& lhs,T& rhs)
		{
			T tmp(lhs);
			lhs = rhs;
			rhs = tmp;
		}

		#pragma region 冒泡排序
		/*
			1、冒泡排序，外部循环，执行趟数，第一趟，对集合相邻两个比较，大的数向下沉，结束后，最大的数在最下面，
				第二趟，从头部开始，尾部减1，找出次大的数。			
			2、时间复杂度：
				平均情况【n*n】
				最好情况【n*n】
				最坏情况【n*n】
			4、辅助空间：
				1
			5、稳定的排序算法。
		*/
		template <typename T>
		void BubbleSort(std::vector<T>& vec)
		{
			for(int i=0;i<vec.size();++i)
			{
				for(int j=0;j<vec.size()-i-1;++j)
				{
					if(vec[j] > vec[j+1])
					{
						Swap(vec[j],vec[j+1]);
					}
				}
			}
		}

		/*
			1、上面的冒泡排序存在问题，比如已经有序的情况，0 1 2 3 4 5，每一趟都需要遍历两两比较。
			2、可以优化，如果这一趟没有执行swap，可以断定第二趟也不会执行swap，因此优化如下：
				
		*/
		template <typename T>
		void BubbleSort_2(std::vector<T>& vec)
		{
			bool isNeedContinue = true; // 初始化需要进行下一趟

			for(int i=0;i<vec.size()&&isNeedContinue;++i)
			{
				isNeedContinue = false; // 假定不需要下一趟

				for(int j=0;j<vec.size()-i-1;++j)
				{
					if(vec[j] > vec[j+1])
					{
						Swap(vec[j],vec[j+1]);
						isNeedContinue = true; // 存在交换，还要进行下一趟
					}
				}
			}
		}
		#pragma endregion 冒泡排序
		
		#pragma region 插入排序
		/*
			1、插入排序，前面的元素有序，当前元素进行插入。外部循环，记录当前下标，把当前元素挖走，留下一个坑，
				对于前面有序的子序列，从后向前，找出比它小的，比它大，从前面挖数，填后面的坑，直到头部或者找到位置，
				最后填上遗留的坑。
			2、时间复杂度：
				平均情况【n*n】
				最好情况【n  】，已经有序，每次都不需要从前面挖数，填后面的坑。
				最坏情况【n*n】，倒序排列，每次都要从前面挖数，填后面的坑，一直到最前面。
			3、辅助空间：
				1
			4、稳定的排序算法。
		*/
		template <typename T>
		void InsertSort(std::vector<T>& vec)
		{
			for(int i =1;i<vec.size();++i)
			{
				int curIndex = i; // 记录当前的下标
				T target(vec[i]); // 挖个数，留下一个坑

				while(curIndex >0 && target<vec[curIndex-1]) // 当前元素小，向前移动
				{
					vec[curIndex] = vec[curIndex -1]; // 从前面挖数，填后面的坑
					--curIndex; // 递进
				}

				vec[curIndex] = target; // 填上遗留的坑
			}
		}
		#pragma endregion 插入排序

		#pragma region 希尔排序
		/*
			1、对于插入排序，如果已经基本有序，算法效率很高。
			2、所谓基本有序，也就是对于整个序列，小的数在前面，中间的数在中间，大的数在后面。
				如何使它基本有序呢？分组，跳跃式的分组。考虑9个元素，分成3组，分别为：
				a[0],a[3],a[6]
				a[1],a[4],a[7]
				a[2],a[5],a[8]
				每一组插入排序，就使得基本有序。然后缩小间隔，直到为1
			3、也就是说，希尔排序有三层循环，外层循环缩小间隔，因为是插入排序，前面的一个元素有序，
				中间循环从每个分组的第二个元素开始，遍历a[3],a[4]...，内层循环记录当前下标和元素，和target比较，
				挖前面的数，填后面的坑。
				虽然希尔排序有三层循环，但是效率高。外层循环缩小，下降很快，中间是n，内层循环跳跃是 n/interval，
				interval不是常数，会变化。希尔排序的时间复杂度 小于 n*n
			4、时间复杂度：
				平均情况【nlogn到n*n】
				最好情况【n^1.3		】n的1.3次方
				最坏情况【n*n		】
			5、辅助空间：
				1
			6、不稳定的排序算法。

		*/
		void ShellSort(vector<int>& vec)
		{
			int interval = vec.size();
			do
			{
				interval = interval/3+1;

				for(int i = interval;i<vec.size();++i) // 从每个分组的第二个元素
				{
					int curIndex = i;   //记录当前下标
					int target = vec[i];//记录当前元素，挖数，留下一个坑
					// 没有走到分组的第一个元素，并且目标小
					while(curIndex>=interval && target<vec[curIndex-interval]) 
					{
						vec[curIndex]=vec[curIndex-interval]; // 挖前面的数，填后面的坑
						curIndex-=interval; //分组的前一个元素
					}
					vec[curIndex] = target; // 补平遗留的坑
				}

			}while(interval>1); // 缩小间隔，直到为1
		}
		#pragma endregion 希尔排序

		#pragma region 选择排序
		/*
			1、选择排序，外部循环，假定当前下标就是最小值的下标，内部循环从下一位开始遍历，找出一个最小值的下标。
			2、内部循环退出，和假定不一致，进行交换。
			3、时间复杂度：
				平均情况【n*n】
				最好情况【n*n】
				最坏情况【n*n】
				因为，假定当前下标的元素就是最小值，必须遍历内部循环才确定。
			4、辅助空间：
				1
			5、稳定的排序算法。
		*/
		template <typename T>
		void SelectSort(std::vector<T>& vec)
		{
			for(int i =0;i<vec.size();++i)
			{
				int minIndex = i; // 假定当前下标就是最小值的下标

				for(int j =i+1;j<vec.size();++j)
				{
					if(vec[minIndex]>vec[j])
					{
						minIndex = j; // 找出最小值的下标					
					}
				}

				if(minIndex != i) // 和假定不一致，交换元素
				{
					Swap(vec[minIndex],vec[i]);
				}
			}
		}
		#pragma endregion 选择排序

		#pragma region 快速排序
		template <typename T>
		void QSort(std::vector<T>& vec,int left,int right)
		{
			int i = left;   // 左边
			int j = right-1;// 右边

			if(i >= j) // 已经相遇，结束递归
			{
				return;
			}

			T target(vec[i]); // 从前面挖个数，留下一个坑

			while(i<j) // 前后夹击，直到相遇
			{				
				while(i<j && vec[j]>target) // 从后向前，找出一个小的
				{
					--j;
				}
				if(i<j) // 没有相遇
				{
					vec[i++] = vec[j]; //从后面挖个数，填上前面的坑
				}

				while(i<j && vec[i]<target) // 从前向后，找出一个大的
				{
					++i;
				}
				
				if(i<j) // 没有相遇
				{
					vec[j--]=vec[i]; //从前面挖个数，填上后面的坑
				}	
			}

			vec[i] = target; // 填上遗留的坑
			QSort(vec,left,i);
			QSort(vec,i+1,right);
		}

		/*
			1、快速排序，调用递归方法。因为是折半递归，效率并不差。如果是线性递归，比如斐波那契数列，效率很低。
			2、快速排序思路：递归调用，前后相遇，结束递归。没有相遇，先从前面挖个数，留下一个坑，然后循环，
				一个循环里，后面挖个数填前面的坑，然后前面挖个数，填后面的坑，循环直到相遇。
				相遇之后，跳出循环，填上遗留的坑，对前后两块递归调用。
			3、时间复杂度：
				平均情况【nlogn】
				最好情况【nlogn】，每次都刚好分成均匀的两块
				最坏情况【n*n  】，每次都分成极端不均衡的两块，1和n-1个
			4、辅助空间：
				递归造成的栈空间使用，递归的深度最好情况 logn，最坏情况n，因此辅助空间 logn到n
			5、比较和交换是跳跃式的，因此是不稳定的排序算法。
		*/
		template <typename T>
		void QuickSort(std::vector<T>& vec)
		{			
			QSort(vec,0,vec.size());
		}
		#pragma endregion 快速排序

		#pragma region 堆排序
		// curIndex 非叶子结点的下标，对它和子节点堆化
		// 堆化的长度
		void HeapAdjust(vector<int>& vec, int curIndex,int len)
		{
			while(curIndex<len)
			{
				int leftChildIndex  = 2*curIndex+1;
				int rightChildIndex = 2*curIndex+2;

				if(leftChildIndex < len) //左孩子存在
				{
					if(rightChildIndex < len) //右孩子存在
					{
						// 两个孩子中找到一个大的
						if(vec[leftChildIndex] >= vec[rightChildIndex]) // 左孩子大
						{
							// 和左孩子比较
							if(vec[curIndex] >= vec[leftChildIndex]) // 堆正确
							{
								break;
							}
							else // 把左孩子提拔上来
							{
								swap(vec[curIndex],vec[leftChildIndex]);
								curIndex = leftChildIndex;
							}
						}
						else
						{
							// 和右孩子比较
							if(vec[curIndex] >= vec[rightChildIndex]) // 堆正确
							{
								break;
							}
							else // 把右孩子提拔上来
							{
								swap(vec[curIndex],vec[rightChildIndex]);
								curIndex = rightChildIndex;
							}
						}
					}
					else
					{
						// 和左孩子比较
						if(vec[curIndex] >= vec[leftChildIndex]) // 堆正确
						{
							break;
						}
						else // 把左孩子提拔上来
						{
							swap(vec[curIndex],vec[leftChildIndex]);
							curIndex = leftChildIndex;
						}
					}
				}
				else
				{
					break;
				}	
			}
		}

		/*
			1、堆排序分为两步：构建堆和去掉头部，重新调整堆。
			2、堆排序的思路：堆是逻辑上的完全二叉树，通过下标确定父子关系，a[k]的两个孩子a[2k+1]和a[2k+2].
				堆化需要知道当前下标和集合的长度，对当前下标和子节点堆化。
			3、构建堆，从第一个非叶子结点，开始，向前递进。
				去除头部，重新调整堆，当前下标是0，长度是原来的长度减1。
			4、时间复杂度：
				平均情况【nlogn】
				最好情况【nlogn】
				最坏情况【nlogn】
			5、辅助空间：
				1
			6、不稳定的排序算法。
		*/
		void HeapSort(vector<int>& vec)
		{
			// 从最后一个非叶子节点，向前，堆化
			int start = vec.size()/2 -1; // 最后一个非叶子结点
			for(int i = start; i>=0; --i)
			{
				HeapAdjust(vec,i,vec.size());
			}

			// 头和尾交换，从头到尾部前一个堆化
			for(int i =0;i< vec.size()-1;++i) // 最后一个元素不需要堆化
			{
				swap(vec[0],vec[vec.size()-i-1]);
				HeapAdjust(vec,0,vec.size()-i-1);
			}
		}
		#pragma endregion 堆排序

		#pragma region 归并排序
		// 对于 aVec, 范围[first,mid)和范围[mid,last)都是有序的，将它们归并bVec[first,last)
		void Merge(vector<int>& aVec,vector<int>& bVec,int first,int mid,int last)
		{
			int i=first; // 前一段的开始下标
			int j=mid;   // 后一段的开始下标
			int k=first; // 目标集合的开始下标

			while(i<mid && j<last) // 两段都没有走到结尾
			{
				if(aVec[i]<aVec[j]) // 前面的小
				{
					bVec[k++] = aVec[i++]; // 从前一段取元素
				}
				else
				{
					bVec[k++] = aVec[j++]; // 从后一段取元素
				}
			}

			// while退出后，只有一段还有剩余元素，哪个段的最大值大，哪个段有剩余元素

			// 复制前一段的剩余元素
			while(i<mid)
			{
				bVec[k++] = aVec[i++];
			}

			// 复制后一段的剩余元素
			while(j<last)
			{
				bVec[k++] = aVec[j++];
			}
		}

		// vecRef和vec是同一个集合的引用，把vec的[first,last)归并到vecRef
		void MSort(vector<int>& srcVec,vector<int>& dstVec,int first,int last)
		{
			if(first == last-1)
			{
				dstVec[first]=srcVec[first];
			}
			else
			{
				int mid = (first+last)/2;

				// 栈上分配一个临时的集合
				vector<int> tmpVec;
				tmpVec.resize(dstVec.size());

				// vec的[first,mid) 归并到vecCpy的[first,mid)
				MSort(srcVec,tmpVec,first,mid);

				// vec的[mid,last) 归并到vecCpy的[mid,last)
				MSort(srcVec,tmpVec,mid,last);		
				
				// vecCpy的[first,mid)和[mid,last)有序，进行Merge到vecRef
				Merge(tmpVec,dstVec,first,mid,last);
			}
		}


		/*
			1、归并排序的思路：使用递归，调用MSort，MSort内部使用一个临时的集合，对前一段归并，对后一个归并，然后Merge
			2、时间复杂度：
				平均情况【nlogn】
				最好情况【nlogn】
				最坏情况【nlogn】
			3、辅助空间：
				n
			4、稳定的排序算法。			
		*/
		void MergeSort(vector<int>& vec)
		{
			MSort(vec,vec,0,vec.size());
		}

		void MergePass(vector<int>& srcVec,vector<int>& dstVec,int interval)
		{
			int i =0;
			int len = dstVec.size();
			while(i< len-2*interval+1)
			{
				Merge(srcVec,dstVec,i,i+interval,i+2*interval);
				i = i+2*interval;
			}

			if(i<len-interval) // 最后剩余2个序列,长度不同
			{
				Merge(srcVec,dstVec,i,i+interval,dstVec.size());
			}
			else // 最后剩余1个序列
			{
				for(int j = i;j<len;++j)
				{
					dstVec[j] = srcVec[j];
				}
			}
		}
		/*
			1、使用递归，导致空间上的浪费，每次都要一个临时对象。
			2、递归的思路是先自上而下，再自下而上。
			3、能不能直接自下而上，相邻合并，再相邻合并。
		*/

		void MergeSort_2(vector<int>& vec)
		{
			vector<int> tmpVec;
			tmpVec.resize(vec.size());
			
			int i = 1;
			while(i<vec.size())
			{
				MergePass(vec,tmpVec,i); // 把vec相邻，间隔为1的两块，归并到tmpVec

				i*=2;
				MergePass(tmpVec,vec,i); // 把tmpVec相邻，间隔为2的两块，归并到vec

				i*=2; // 为下一趟做准备
			}
		}
		#pragma endregion 归并排序



	}
}

#endif
