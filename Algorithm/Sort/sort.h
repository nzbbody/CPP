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

		#pragma region ð������
		/*
			1��ð�������ⲿѭ����ִ����������һ�ˣ��Լ������������Ƚϣ���������³����������������������棬
				�ڶ��ˣ���ͷ����ʼ��β����1���ҳ��δ������			
			2��ʱ�临�Ӷȣ�
				ƽ�������n*n��
				��������n*n��
				������n*n��
			4�������ռ䣺
				1
			5���ȶ��������㷨��
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
			1�������ð������������⣬�����Ѿ�����������0 1 2 3 4 5��ÿһ�˶���Ҫ���������Ƚϡ�
			2�������Ż��������һ��û��ִ��swap�����Զ϶��ڶ���Ҳ����ִ��swap������Ż����£�
				
		*/
		template <typename T>
		void BubbleSort_2(std::vector<T>& vec)
		{
			bool isNeedContinue = true; // ��ʼ����Ҫ������һ��

			for(int i=0;i<vec.size()&&isNeedContinue;++i)
			{
				isNeedContinue = false; // �ٶ�����Ҫ��һ��

				for(int j=0;j<vec.size()-i-1;++j)
				{
					if(vec[j] > vec[j+1])
					{
						Swap(vec[j],vec[j+1]);
						isNeedContinue = true; // ���ڽ�������Ҫ������һ��
					}
				}
			}
		}
		#pragma endregion ð������
		
		#pragma region ��������
		/*
			1����������ǰ���Ԫ�����򣬵�ǰԪ�ؽ��в��롣�ⲿѭ������¼��ǰ�±꣬�ѵ�ǰԪ�����ߣ�����һ���ӣ�
				����ǰ������������У��Ӻ���ǰ���ҳ�����С�ģ������󣬴�ǰ�������������Ŀӣ�ֱ��ͷ�������ҵ�λ�ã�
				������������Ŀӡ�
			2��ʱ�临�Ӷȣ�
				ƽ�������n*n��
				��������n  �����Ѿ�����ÿ�ζ�����Ҫ��ǰ�������������Ŀӡ�
				������n*n�����������У�ÿ�ζ�Ҫ��ǰ�������������Ŀӣ�һֱ����ǰ�档
			3�������ռ䣺
				1
			4���ȶ��������㷨��
		*/
		template <typename T>
		void InsertSort(std::vector<T>& vec)
		{
			for(int i =1;i<vec.size();++i)
			{
				int curIndex = i; // ��¼��ǰ���±�
				T target(vec[i]); // �ڸ���������һ����

				while(curIndex >0 && target<vec[curIndex-1]) // ��ǰԪ��С����ǰ�ƶ�
				{
					vec[curIndex] = vec[curIndex -1]; // ��ǰ�������������Ŀ�
					--curIndex; // �ݽ�
				}

				vec[curIndex] = target; // ���������Ŀ�
			}
		}
		#pragma endregion ��������

		#pragma region ϣ������
		/*
			1�����ڲ�����������Ѿ����������㷨Ч�ʺܸߡ�
			2����ν��������Ҳ���Ƕ����������У�С������ǰ�棬�м�������м䣬������ں��档
				���ʹ�����������أ����飬��Ծʽ�ķ��顣����9��Ԫ�أ��ֳ�3�飬�ֱ�Ϊ��
				a[0],a[3],a[6]
				a[1],a[4],a[7]
				a[2],a[5],a[8]
				ÿһ��������򣬾�ʹ�û�������Ȼ����С�����ֱ��Ϊ1
			3��Ҳ����˵��ϣ������������ѭ�������ѭ����С�������Ϊ�ǲ�������ǰ���һ��Ԫ������
				�м�ѭ����ÿ������ĵڶ���Ԫ�ؿ�ʼ������a[3],a[4]...���ڲ�ѭ����¼��ǰ�±��Ԫ�أ���target�Ƚϣ�
				��ǰ������������Ŀӡ�
				��Ȼϣ������������ѭ��������Ч�ʸߡ����ѭ����С���½��ܿ죬�м���n���ڲ�ѭ����Ծ�� n/interval��
				interval���ǳ�������仯��ϣ�������ʱ�临�Ӷ� С�� n*n
			4��ʱ�临�Ӷȣ�
				ƽ�������nlogn��n*n��
				��������n^1.3		��n��1.3�η�
				������n*n		��
			5�������ռ䣺
				1
			6�����ȶ��������㷨��

		*/
		void ShellSort(vector<int>& vec)
		{
			int interval = vec.size();
			do
			{
				interval = interval/3+1;

				for(int i = interval;i<vec.size();++i) // ��ÿ������ĵڶ���Ԫ��
				{
					int curIndex = i;   //��¼��ǰ�±�
					int target = vec[i];//��¼��ǰԪ�أ�����������һ����
					// û���ߵ�����ĵ�һ��Ԫ�أ�����Ŀ��С
					while(curIndex>=interval && target<vec[curIndex-interval]) 
					{
						vec[curIndex]=vec[curIndex-interval]; // ��ǰ������������Ŀ�
						curIndex-=interval; //�����ǰһ��Ԫ��
					}
					vec[curIndex] = target; // ��ƽ�����Ŀ�
				}

			}while(interval>1); // ��С�����ֱ��Ϊ1
		}
		#pragma endregion ϣ������

		#pragma region ѡ������
		/*
			1��ѡ�������ⲿѭ�����ٶ���ǰ�±������Сֵ���±꣬�ڲ�ѭ������һλ��ʼ�������ҳ�һ����Сֵ���±ꡣ
			2���ڲ�ѭ���˳����ͼٶ���һ�£����н�����
			3��ʱ�临�Ӷȣ�
				ƽ�������n*n��
				��������n*n��
				������n*n��
				��Ϊ���ٶ���ǰ�±��Ԫ�ؾ�����Сֵ����������ڲ�ѭ����ȷ����
			4�������ռ䣺
				1
			5���ȶ��������㷨��
		*/
		template <typename T>
		void SelectSort(std::vector<T>& vec)
		{
			for(int i =0;i<vec.size();++i)
			{
				int minIndex = i; // �ٶ���ǰ�±������Сֵ���±�

				for(int j =i+1;j<vec.size();++j)
				{
					if(vec[minIndex]>vec[j])
					{
						minIndex = j; // �ҳ���Сֵ���±�					
					}
				}

				if(minIndex != i) // �ͼٶ���һ�£�����Ԫ��
				{
					Swap(vec[minIndex],vec[i]);
				}
			}
		}
		#pragma endregion ѡ������

		#pragma region ��������
		template <typename T>
		void QSort(std::vector<T>& vec,int left,int right)
		{
			int i = left;   // ���
			int j = right-1;// �ұ�

			if(i >= j) // �Ѿ������������ݹ�
			{
				return;
			}

			T target(vec[i]); // ��ǰ���ڸ���������һ����

			while(i<j) // ǰ��л���ֱ������
			{				
				while(i<j && vec[j]>target) // �Ӻ���ǰ���ҳ�һ��С��
				{
					--j;
				}
				if(i<j) // û������
				{
					vec[i++] = vec[j]; //�Ӻ����ڸ���������ǰ��Ŀ�
				}

				while(i<j && vec[i]<target) // ��ǰ����ҳ�һ�����
				{
					++i;
				}
				
				if(i<j) // û������
				{
					vec[j--]=vec[i]; //��ǰ���ڸ��������Ϻ���Ŀ�
				}	
			}

			vec[i] = target; // ���������Ŀ�
			QSort(vec,left,i);
			QSort(vec,i+1,right);
		}

		/*
			1���������򣬵��õݹ鷽������Ϊ���۰�ݹ飬Ч�ʲ������������Եݹ飬����쳲��������У�Ч�ʺܵ͡�
			2����������˼·���ݹ���ã�ǰ�������������ݹ顣û���������ȴ�ǰ���ڸ���������һ���ӣ�Ȼ��ѭ����
				һ��ѭ��������ڸ�����ǰ��Ŀӣ�Ȼ��ǰ���ڸ����������Ŀӣ�ѭ��ֱ��������
				����֮������ѭ�������������Ŀӣ���ǰ������ݹ���á�
			3��ʱ�临�Ӷȣ�
				ƽ�������nlogn��
				��������nlogn����ÿ�ζ��պ÷ֳɾ��ȵ�����
				������n*n  ����ÿ�ζ��ֳɼ��˲���������飬1��n-1��
			4�������ռ䣺
				�ݹ���ɵ�ջ�ռ�ʹ�ã��ݹ����������� logn������n����˸����ռ� logn��n
			5���ȽϺͽ�������Ծʽ�ģ�����ǲ��ȶ��������㷨��
		*/
		template <typename T>
		void QuickSort(std::vector<T>& vec)
		{			
			QSort(vec,0,vec.size());
		}
		#pragma endregion ��������

		#pragma region ������
		// curIndex ��Ҷ�ӽ����±꣬�������ӽڵ�ѻ�
		// �ѻ��ĳ���
		void HeapAdjust(vector<int>& vec, int curIndex,int len)
		{
			while(curIndex<len)
			{
				int leftChildIndex  = 2*curIndex+1;
				int rightChildIndex = 2*curIndex+2;

				if(leftChildIndex < len) //���Ӵ���
				{
					if(rightChildIndex < len) //�Һ��Ӵ���
					{
						// �����������ҵ�һ�����
						if(vec[leftChildIndex] >= vec[rightChildIndex]) // ���Ӵ�
						{
							// �����ӱȽ�
							if(vec[curIndex] >= vec[leftChildIndex]) // ����ȷ
							{
								break;
							}
							else // �������������
							{
								swap(vec[curIndex],vec[leftChildIndex]);
								curIndex = leftChildIndex;
							}
						}
						else
						{
							// ���Һ��ӱȽ�
							if(vec[curIndex] >= vec[rightChildIndex]) // ����ȷ
							{
								break;
							}
							else // ���Һ����������
							{
								swap(vec[curIndex],vec[rightChildIndex]);
								curIndex = rightChildIndex;
							}
						}
					}
					else
					{
						// �����ӱȽ�
						if(vec[curIndex] >= vec[leftChildIndex]) // ����ȷ
						{
							break;
						}
						else // �������������
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
			1���������Ϊ�����������Ѻ�ȥ��ͷ�������µ����ѡ�
			2���������˼·�������߼��ϵ���ȫ��������ͨ���±�ȷ�����ӹ�ϵ��a[k]����������a[2k+1]��a[2k+2].
				�ѻ���Ҫ֪����ǰ�±�ͼ��ϵĳ��ȣ��Ե�ǰ�±���ӽڵ�ѻ���
			3�������ѣ��ӵ�һ����Ҷ�ӽ�㣬��ʼ����ǰ�ݽ���
				ȥ��ͷ�������µ����ѣ���ǰ�±���0��������ԭ���ĳ��ȼ�1��
			4��ʱ�临�Ӷȣ�
				ƽ�������nlogn��
				��������nlogn��
				������nlogn��
			5�������ռ䣺
				1
			6�����ȶ��������㷨��
		*/
		void HeapSort(vector<int>& vec)
		{
			// �����һ����Ҷ�ӽڵ㣬��ǰ���ѻ�
			int start = vec.size()/2 -1; // ���һ����Ҷ�ӽ��
			for(int i = start; i>=0; --i)
			{
				HeapAdjust(vec,i,vec.size());
			}

			// ͷ��β��������ͷ��β��ǰһ���ѻ�
			for(int i =0;i< vec.size()-1;++i) // ���һ��Ԫ�ز���Ҫ�ѻ�
			{
				swap(vec[0],vec[vec.size()-i-1]);
				HeapAdjust(vec,0,vec.size()-i-1);
			}
		}
		#pragma endregion ������

		#pragma region �鲢����
		// ���� aVec, ��Χ[first,mid)�ͷ�Χ[mid,last)��������ģ������ǹ鲢bVec[first,last)
		void Merge(vector<int>& aVec,vector<int>& bVec,int first,int mid,int last)
		{
			int i=first; // ǰһ�εĿ�ʼ�±�
			int j=mid;   // ��һ�εĿ�ʼ�±�
			int k=first; // Ŀ�꼯�ϵĿ�ʼ�±�

			while(i<mid && j<last) // ���ζ�û���ߵ���β
			{
				if(aVec[i]<aVec[j]) // ǰ���С
				{
					bVec[k++] = aVec[i++]; // ��ǰһ��ȡԪ��
				}
				else
				{
					bVec[k++] = aVec[j++]; // �Ӻ�һ��ȡԪ��
				}
			}

			// while�˳���ֻ��һ�λ���ʣ��Ԫ�أ��ĸ��ε����ֵ���ĸ�����ʣ��Ԫ��

			// ����ǰһ�ε�ʣ��Ԫ��
			while(i<mid)
			{
				bVec[k++] = aVec[i++];
			}

			// ���ƺ�һ�ε�ʣ��Ԫ��
			while(j<last)
			{
				bVec[k++] = aVec[j++];
			}
		}

		// vecRef��vec��ͬһ�����ϵ����ã���vec��[first,last)�鲢��vecRef
		void MSort(vector<int>& srcVec,vector<int>& dstVec,int first,int last)
		{
			if(first == last-1)
			{
				dstVec[first]=srcVec[first];
			}
			else
			{
				int mid = (first+last)/2;

				// ջ�Ϸ���һ����ʱ�ļ���
				vector<int> tmpVec;
				tmpVec.resize(dstVec.size());

				// vec��[first,mid) �鲢��vecCpy��[first,mid)
				MSort(srcVec,tmpVec,first,mid);

				// vec��[mid,last) �鲢��vecCpy��[mid,last)
				MSort(srcVec,tmpVec,mid,last);		
				
				// vecCpy��[first,mid)��[mid,last)���򣬽���Merge��vecRef
				Merge(tmpVec,dstVec,first,mid,last);
			}
		}


		/*
			1���鲢�����˼·��ʹ�õݹ飬����MSort��MSort�ڲ�ʹ��һ����ʱ�ļ��ϣ���ǰһ�ι鲢���Ժ�һ���鲢��Ȼ��Merge
			2��ʱ�临�Ӷȣ�
				ƽ�������nlogn��
				��������nlogn��
				������nlogn��
			3�������ռ䣺
				n
			4���ȶ��������㷨��			
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

			if(i<len-interval) // ���ʣ��2������,���Ȳ�ͬ
			{
				Merge(srcVec,dstVec,i,i+interval,dstVec.size());
			}
			else // ���ʣ��1������
			{
				for(int j = i;j<len;++j)
				{
					dstVec[j] = srcVec[j];
				}
			}
		}
		/*
			1��ʹ�õݹ飬���¿ռ��ϵ��˷ѣ�ÿ�ζ�Ҫһ����ʱ����
			2���ݹ��˼·�������϶��£������¶��ϡ�
			3���ܲ���ֱ�����¶��ϣ����ںϲ��������ںϲ���
		*/

		void MergeSort_2(vector<int>& vec)
		{
			vector<int> tmpVec;
			tmpVec.resize(vec.size());
			
			int i = 1;
			while(i<vec.size())
			{
				MergePass(vec,tmpVec,i); // ��vec���ڣ����Ϊ1�����飬�鲢��tmpVec

				i*=2;
				MergePass(tmpVec,vec,i); // ��tmpVec���ڣ����Ϊ2�����飬�鲢��vec

				i*=2; // Ϊ��һ����׼��
			}
		}
		#pragma endregion �鲢����



	}
}

#endif
