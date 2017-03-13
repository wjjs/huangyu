//Remove Duplicates from Sorted Array

#include "stdafx.h"
#include <iostream>
#define N 5
using namespace std;
int RemoveDulplicate(int a[], int len)
{
	int index = 0;
	int i = 1;
	for (; i < len; i++)
	{
		if ( a[index] != a[i] )
		{
			index++;
			a[index] = a[i];
		}
	}
	return index + 1;
}

int main()
{
	int a[N] = { 1, 1, 2, 2, 3 };
	int len = RemoveDulplicate(a, N);
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
    return 0;
}

//Remove Duplicates from Sorted Array II
#include "stdafx.h"
#include <iostream>
#define N 5
#define OCCUR 2
using namespace std;
int RemoveDulplicate(int a[], int len)
{
	int index = 0;
	int i = 1;
	int num = 1;
	for (; i < len; i++)
	{
		if ( a[index] != a[i] )
		{
			index++;
			a[index] = a[i];
			num = 1;
		}
		else
		{
			num++;
			if (num <= OCCUR)
			{
				index++;
			}
		}
	}
	return index + 1;
}

int main()
{
	int a[N] = { 1, 1, 2, 2, 2 };
	int len = RemoveDulplicate(a, N);
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
    return 0;
}

//Search in Rotated Sorted Array
#include "stdafx.h"
#include <iostream>
#define N 6
using namespace std;

/*
 * function:looking for d from a[first] to a[last] including a[first] and a[last] 
 * return: if got it,return the index of d in a,if not,return -1
 */
int BinarySearch(int d, int a[], int first, int last)
{
	int mid;
	while (first <= last)
	{
		mid = first + (last - first) / 2;
		/*
		cout << "first is " << first << " ,";
		cout << "last is " << last << " ,";
		cout << "d is " << d << " ,";
		cout << "mid is " << mid << endl;
		*/
		if (d == a[mid])
		{
			return mid;
		}
		if (d > a[mid])
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
		/*
		cout << "first is " << first << " ,";
		cout << "last is " << last << " ,";
		cout << "mid is " << mid << endl;
		*/
	}
	return -1;
}

int Search(int d, int a[], int lenth)
{
	int first = 0;
	int last = lenth - 1;
	int mid;
	while (first <= last)
	{
		mid = first + (last - first) / 2;
		if (a[mid] == d)
		{
			return mid;
		}
		if (a[mid] >= a[first])
		{
			if (d >= a[first] && d <= a[mid])
			{
				int ret = BinarySearch(d, a, first, mid);
				return ret;
			}
			else
			{
				first = mid + 1;
			}
		}
		else
		{
			if (d >= a[mid] && d <= a[last])
			{
				int ret = BinarySearch(d, a, mid, last);
				return ret;
			}
			else
			{
				last = mid - 1;
			}	
		}
		if (a[last] >= a[first])
		{
			int ret = BinarySearch(d, a, first, last);
			return ret;
		}
	}
	return -1;
}

int main()
{
	int a[N] = {7, 8, 9, 1, 2, 3};
	int ret = Search(0, a, N);
	cout << "return value is " << ret << endl;
    return 0;
}

// leetcode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define N 6
#define K 5
using namespace std;
/*
 * functioin:search the kth minimum number among sorted arrays a and b
 * ret:if got it,return the kth minumum number,else return -1
 *
*/
int SearchKthMin(int k, int a[], int aStart, int aEnd, int b[], int bStart, int bEnd)
{
	int i = aStart;
	int j = bStart;
	int c = 0;
	while ( i <= aEnd && j<= bEnd)
	{
		if (a[i] < b[j])
		{
			c++;
			if (c == k)
			{
				return a[i];
			}
			i++;
		}
		else
		{
			c++;
			if (c == k)
			{
				return b[j];
			}
			j++;
		}
	}
	if (i == aEnd + 1)  //now b[j] is the (c+1)th min 
	{
		c++; 
		if (c == k)
		{
			return b[j];
		}
		else
		{
			j = j + (k - c);
			if (j > bEnd)
			{
				return -1;
			}
			else
			{
				return b[j];
			}
		}
	}
	else
	{
		c++;
		if (c == k)
		{
			return a[i];
		}
		else
		{
			i = i + (k - c);
			if (i > aEnd)
			{
				return -1;
			}
			else
			{
				return a[i];
			}
		}
	}
}

int main()
{
	int a[N] = {7, 8, 9, 10, 11, 12};
	int b[] = {1, 2, 3, 4, 5};
	int KthMin = SearchKthMin(K, a, 0, 5, b, 0, 4);
	cout << "the " << K << "th min is " << KthMin <<endl;
    return 0;
}


/* function: Search the Kth minimun among the sorted arrays a and b
 * ret: if got it , return the Kth minumum number,otherwise return -1
 * note: compared with the last algorithm,this one is better in time 
 *       complexity which is O(log(m+n))
*/
#include "stdafx.h"
#include <iostream>
#define N 6
#define K 7
using namespace std;
int SearchKthMin(int k, int a[], int aStart, int aEnd, int b[], int bStart, int bEnd)
{
	int i = aStart;
	int j = bStart;
	int c = 0;
	while (i <= aEnd && j <= bEnd)
	{
		if (a[i] < b[j])
		{
			c++;
			if (c == k)
			{
				return a[i];
			}
			i++;
		}
		else
		{
			c++;
			if (c == k)
			{
				return b[j];
			}
			j++;
		}
	}
	if (i == aEnd + 1)  //now b[j] is the (c+1)th min
	{
		c++;
		if (c == k)
		{
			return b[j];
		}
		else
		{
			j = j + (k - c);
			if (j > bEnd)
			{
				return -1;
			}
			else
			{
				return b[j];
			}
		}
	}
	else
	{
		c++;
		if (c == k)
		{
			return a[i];
		}
		else
		{
			i = i + (k - c);
			if (i > aEnd)
			{
				return -1;
			}
			else
			{
				return a[i];
			}
		}
	}
}

int Min(int a, int b)
{
	return (a > b)? b :a;
}

int FastSearchKthMin(int k, int a[], int aStart, int aEnd, int b[], int bStart, int bEnd)
{
	while (((aEnd - aStart + 1) >= k / 2) && ((bEnd - bStart + 1) >= k / 2) && (k / 2 >= 1))
	{
		if (a[aStart + k / 2 - 1] > b[bStart + k / 2 - 1])
		{
			bStart = bStart + k / 2;
			k = k - k / 2;
		}
		else if (a[aStart + k / 2 - 1] < b[bStart + k / 2 - 1])
		{
			aStart = aStart + k / 2;
			k = k - k / 2;
		}
		else
		{
			if (k % 2 == 0)
			{
				return a[aStart + k / 2 - 1];
			}
			else
			{
				return Min(a[aStart + k / 2], b[bStart + k / 2]);
			}
		}
	}
	return SearchKthMin(k, a, aStart, aEnd, b, bStart, bEnd);

}

int main()
{
	int a[N] = {7, 8, 9, 10, 11, 12};
	int b[] = {1, 2, 3, 4, 5};
	int KthMin = FastSearchKthMin(K, a, 0, 5, b, 0, 4);
	cout << "the " << K << "th min is " << KthMin <<endl;
    return 0;
}

/* Longest Consecutive Sequence
 * time complexity:same as the sort alogithm
*/
#include "stdafx.h"
#include <iostream>
#define N 6
using namespace std;
void BubbleSort(int a[], int first, int last)
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = first; i <= last - 1; i++)
		{
			if (a[i] > a[i+1])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				flag = 1;
			}
		}
	}
}

int SearchCS(int a[], int first, int last)
{
	int lenth = 1;
	int i = first;
	while ((a[i] == a[i + 1] - 1) && (i <= last - 1))
	{
		lenth++;
		i++;
	}
	return lenth;
}

int SearchLCS(int a[], int first, int last)
{
	BubbleSort(a, first, last);
	int maxLng = SearchCS(a, first, last);
	int maxLngStartIndex = first;
	int i = first + maxLng;
	while (i <= last)
	{
		int tempLng = SearchCS(a, i , last);
		if (tempLng >= maxLng)
		{
			maxLng = tempLng;
			maxLngStartIndex = i;
		}
		i = i + tempLng;
	}
	return maxLng;
}

int PrintIntArray(int a[], int first, int last)
{
	for (int i = 0; i <= last - 1; i++)
	{
		cout << a[i] << " ,";
	}
	cout << a[last] << endl;
	return 0;
}

int main()
{
	int a[N] = {7, 10, 0, 15, 12, 0};
	int maxLen = SearchLCS(a, 0, N - 1);
	cout << "max lenth consecutive sequence is " << maxLen << endl;
    return 0;
}

/* add string
 * function: add two number whose format is string
*/
#include "stdafx.h"
#include <iostream>
#define N 6
using namespace std;

int Max(int i, int j)
{
	return (i > j ? i : j);
}
char * AddString(char num1[], char num2[])
{
	int i = 0;
	int j = 0;
	if (num1[0] == '\0' || num2[0] == '\0' 
		|| num1 == NULL || num2 == NULL)
	{
		return NULL;
	}
	for (; num1[i + 1] != '\0'; i++)
	{
		;
	}
	for (; num2[j + 1] != '\0'; j++)
	{
		;
	}
	int k = Max(i, j);
	char * result = (char *)(malloc((k + 2)* sizeof(char)));
	result[k + 1] = '\0';
	int carry = 0;
	int sum;
	while (i >= 0 && j >= 0)
	{
		sum = (num1[i] - '0') + (num2[j] - '0') + carry;
		result[k] = sum % 10 + '0';
		carry = sum / 10;
		i--;
		j--;
		k--;
	}
	if (i == -1)
	{
		while (j >= 0)
		{
			sum = num2[j] - '0' + carry;
			result[k] = sum % 10 + '0';
			carry = sum / 10;
			j--;
			k--;
		}
	}
	else
	{
		while (i >= 0)
		{
			sum = num1[i] - '0' + carry;
			result[k] = sum % 10 + '0';
			carry = sum / 10;
			i--;
			k--;
		}
	}
	return result;
}

int PrintIntArray(int a[], int first, int last)
{
	for (int i = 0; i <= last - 1; i++)
	{
		cout << a[i] << " ,";
	}
	cout << a[last] << endl;
	return 0;
}

int main()
{
	char num1[] = "12345";
	char num2[] = "2345";
	char * resu = AddString(num1, num2);
	cout << resu << endl;
    return 0;
}

/*get sum of every digit of a given number
 * example: if given number is 96,then 9+6=15,1+5=6,so return 6
*/
int GetSumOfEveryDigits(int n)
{
	int ret = n % 9;
	if (ret == 0)
	{
		ret = 9;
		return ret;
	}
	else
	{
		return ret;
	}
}

/* transform a number to hex
 * transform the number to a binary before
 * transforming it to hex
 */
#include "stdafx.h"
#include "math.h"
#include <iostream>
#include "stdlib.h"
using namespace std;

//the default start index is 0
typedef struct 
{
	int * a;
	int last;
}IntArray;

int Max(int i, int j)
{
	return (i > j ? i : j);
}

void ReverseString(char * s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	i--;
	int last = i;
	char temp;
	for (i = 0; i <= last / 2; i++)
	{
		temp = s[i];
		s[i] = s[last - i];
		s[last - i] = temp;
	}
}

int iPow(int x, int y)
{
	double ret = pow((double)x, (double)y);
	return (int)ret;
}

IntArray * TransformToBinary(int n)
{
	int i = 0;
	for (; iPow(2, i) <= n; i++)
	{
		;
	}
	i--;  //i stores the max pow of the transformed binary
	int last = i;
	int * result = (int *)malloc((i + 1)* sizeof(int));
	while (i >= 0)
	{
		if (n >= iPow(2, i))
		{
			result[i] = 1;
			n = n - iPow(2, i);
		}
		else
		{
			result[i] = 0;
		}
		i--;
	}
	IntArray * binary = (IntArray *)malloc(sizeof(IntArray));
	binary->a = result;
	binary->last = last;

	/*
	for (i = 0; i <= last; i++)
	{
		cout << result[i];
	}
	cout << endl;
    */	

	return binary;
}

char * TransformToHex(int n)
{
	IntArray * binary = TransformToBinary(n);
	int lenth;
	if ((binary->last + 1) % 4 == 0)
	{
		lenth = (binary->last + 1) / 4;
	}
	else
	{
		lenth = (binary->last + 1) / 4 + 1;
	}
	char * hex = (char *)malloc((lenth + 1) * sizeof(char));
	int i = 0;
	int tempSum = 0;
	int * binArr = binary->a;
	while (i + 3 <= binary->last)
	{
		tempSum = binArr[i] + binArr[i + 1] * 2 + binArr[i + 2] * 4 + binArr[i + 3] * 8;
		if (tempSum < 10)
		{
			hex[i / 4] = '0' + tempSum;
		}
		else
		{
			hex[i / 4] = 'a' + (tempSum - 10);
 		}
		i += 4;
		tempSum = 0;
	}
	int j = 1;
	while (i <= binary->last)
	{
		tempSum += binArr[i] * j;
		i++;
		j *= 2;
	}
	if (tempSum < 10)
	{
		hex[i / 4] = '0' + tempSum;
	}
	else
	{
		hex[i / 4] = 'a' + (tempSum - 10);
	}
	hex[lenth] = '\0';
	ReverseString(hex);
	return hex;
}

int main()
{
	int n = 89;
	char * hex = TransformToHex(n);
	cout << hex << endl;
    return 0;
}

/*
 * TwoSum in BruteForce
 * function:find two numbers in an array
            whose sum is a given number
 * assume:there is exactly one couple which
          satisfies the need
*/
#include "stdafx.h"
#include "math.h"
#include <iostream>
#include "stdlib.h"
#define TARGET 9
#define N 4
using namespace std;

int TwoSum(int a[], int lenth, int &index1, int &index2)
{
	for (int i = 0; i < lenth; i++)
	{
		for (int j = i+1; j < lenth; j++)
		{
			if (a[i] + a[j] == TARGET)
			{
				index1 = i + 1;
				index2 = j + 1;
				return 0;
			}
		}
	}
}

int main()
{
	int a[N] = {15, 2, 11, 7};
	int index1 = 0;
	int index2 = 0;
	TwoSum(a, N, index1, index2);
	cout << "index1 is " << index1 << ", index2 is " << index2 << endl;
    return 0;
}


/*
 * function: get the missing number
 * precondition: an array whose size is
                 n,then the element of 
                 the array was took from
                 0 to n,find the missing 
                 number
 */
int MissingNumber(int a[], int numSize)
{
	int i;
	int arraySum = 0;
	for (i = 0; i < numSize; i++)
	{
		arraySum += a[i];
	}
	int totalSum = 0;
	for (i = 1; i <= numSize; i++)
	{
		totalSum += i;
	}
	return totalSum - arraySum;
}

/* 35 Search Insert Position
 * 
*/
int searchInsert(int * nums, int numSize, int target)
{
	int i;
	for (i = 0; nums[i] <= target && i < numSize; i++)
	{
		;
	}
	if (i == 0)
	{
		return i;
	}

	if (nums[i - 1] == target)
	{
		return i - 1;
	}
	else
	{
		return i;
	}
}

/* 189 Rotate Array
 * thought: use reverse method three times
*/
#include "stdafx.h"
#include "math.h"
#include <iostream>
#include "stdlib.h"
#define N 8
using namespace std;

int PrintIntArray(int a[], int first, int last)
{
	for (int i = 0; i <= last - 1; i++)
	{
		cout << a[i] << " ,";
	}
	cout << a[last] << endl;
	return 0;
}

void ireverse(int * nums, int first, int last)
{
	int i = first;
	int temp;
	for (; i <= first + (last - first + 1) / 2 - 1; i++)
	{
		temp = nums[i];
		nums[i] = nums[first + last - i];
		nums[first + last - i] = temp;
	}
}

void rotate(int * nums, int numSize, int k)
{
	ireverse(nums, 0, numSize - 1);
	ireverse(nums, 0, k - 1);
	ireverse(nums, k, numSize - 1);
}

int main()
{
	int a[N] = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << "Before reverse, array is:" << endl;
	PrintIntArray(a, 0, N-1);
	rotate(a, N, 3);
	PrintIntArray(a, 0, N - 1);
    return 0;
}

448. Find All Numbers Disappeared in an Array 
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    int i = 0;
    int j = 0;
    int * returnlist = (int *)malloc((numsSize + 1) * sizeof(int));
    for (; i <= numsSize; i++)
    {
        returnlist[i] = 0;
    }
    for (i = 0; i < numsSize; i++)
    {
        returnlist[nums[i]]++;
    }
    
    i = 0;
    j = 1;
    while (j <= numsSize)
    {
        if (returnlist[j] == 0)
        {
            returnlist[i] = j;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    (*returnSize) = i;  //error: returnlist[i] to returnlist[numsSize] not freed!!
    return returnlist;
}

448. Find All Numbers Disappeared in an Array 
//other's method 
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    int i;
    int index;
    for (i = 0; i < numsSize; i++)
    {
        index = iabs(nums[i]) - 1;
        nums[index] = (nums[index] > 0 ?-nums[index]:nums[index]); //mark
    }
    int c = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            c++;
        }
    }
    *returnSize = c;
    int * result = (int *)malloc(c * sizeof(int));
    int j = 0;
    for(i = 0, j = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            result[j] = i+1;
            j++;
        }
    }
    return result;
}

int iabs(int i)
{
    return (i >= 0? i: -i);
     
}




#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
char* Decode(char* in) 
{
    int len = strlen(in);
    int 

    //将输入的字符串转换为整数
    int num = 0;  //存储转换的结果
    int i = 0;
    for(; i < len; i++)
    {
        num += (in[i] - '0') * pow(10, len-1-i);
    }
   
    //然后判断该数字在哪个范围之内
    if (num > 65536)


}

int main() {
    char* res;

    char* _in;
    _in = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",_in);
    
    res = Decode(_in);
    printf("%s\n", res);
    
    return 0;
}

typedef struct node
{
	int data;
	struct node * next;
};

node * findMiddle(node * head)
{
	int c = 0;
	int m = 0;
	node * current = head -> next;
	node * middle = head -> next;
	while (current != NULL)
	{
		if (c / 2 > m)
		{
			middle = middle->next;
			m++;
		}
		c++;
		current = current->next;
	}
	return middle;
}

bool IsLoop(node * head)
{
	if (head == NULL || head->next == NULL)
	{
		return false;
	}
	node * p1 = head->next;
	node * p2 = head->next->next;
	while (p2 && (p2->next) && (p1 != p2))
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if (p1 == p2)
	{
		return true;
	}
	else
	{
		return false;
	}
}


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	vector<int> data;
	ifstream in("c:/users/jamesbond/desktop/test.txt");
	if (!in)
	{
		cout << "file does not exit!" << endl;
	}
	int temp;
	while (!in.eof())
	{
		in >> temp;
		data.push_back(temp);
	}
	in.close();
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}
    return 0;
}


//runnable
#include "stdafx.h"  
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
int main()
{
	Mat src, gray;
	src = imread("C:/Users/JamesBond/Desktop/1920x1200.jpg");
	cvtColor(src, gray, CV_RGB2GRAY);
	int bins = 256;
	int hist_size[] = { bins };
	float range[] = { 0, 256 };
	const float* ranges[] = { range };
	MatND hist;
	int channels[] = { 0 };

	calcHist(&gray, 1, channels, Mat(), // do not use mask  
		hist, 1, hist_size, ranges,
		true, // the histogram is uniform  
		false);

	double max_val;
	minMaxLoc(hist, 0, &max_val, 0, 0);
	int scale = 2;
	int hist_height = 256;
	Mat hist_img = Mat::zeros(hist_height, bins*scale, CV_8UC3);
	for (int i = 0; i<bins; i++)
	{
		float bin_val = hist.at<float>(i);
		int intensity = cvRound(bin_val*hist_height / max_val);  //要绘制的高度  
		rectangle(hist_img, Point(i*scale, hist_height - 1),
			Point((i + 1)*scale - 1, hist_height - intensity),
			CV_RGB(255, 255, 255));
	}
	imshow("Source", src);
	imshow("Gray Histogram", hist_img);
	waitKey(10000000000);
	return 0;
}

//exp1
#include "stdafx.h"  
#include <iostream>  
#include <math.h>
#include <opencv2/core/core.hpp>   
#include <opencv2/highgui/highgui.hpp>  
using namespace cv;
using namespace std;

int max(uchar i,uchar j, uchar  k)
{
	int bigger = (i > j) ? i : j;
	return (bigger > k ? bigger : k);
}

int min(uchar i, uchar j, uchar k)
{
	int little = (i < j) ? i : j;
	return (little < k ? little : k);
}

int main()
{
	Mat img = imread("C:/Users/JamesBond/Desktop/1920x1200.jpg");
	if (img.empty())
	{
		cout << "error";
		return -1;
	}

	//显示原始图像
	namedWindow("iwindow");
	imshow("iwindow", img);
	waitKey();
	destroyWindow("iwindow");

	//补色变换
	Mat comImage = img.clone();
	for (int i = 0; i < comImage.rows; i++)
	{
		for (int j = 0; j < comImage.cols; j++)
		{
			int sum = max(comImage.at<Vec3b>(i, j)[0], comImage.at<Vec3b>(i, j)[1] , comImage.at<Vec3b>(i, j)[2]) + 
				      min(comImage.at<Vec3b>(i, j)[0], comImage.at<Vec3b>(i, j)[1], comImage.at<Vec3b>(i, j)[2]);
			comImage.at<Vec3b>(i, j)[0] = sum - comImage.at<Vec3b>(i, j)[0] ;
			comImage.at<Vec3b>(i, j)[1] = sum - comImage.at<Vec3b>(i, j)[1];
			comImage.at<Vec3b>(i, j)[2] = sum - comImage.at<Vec3b>(i, j)[2];
		}
	}

	namedWindow("iwindow");
	imshow("iwindow", comImage);
	waitKey();
	destroyWindow("iwindow");

	//灰度化
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			
			img.at<Vec3b>(i, j)[0] = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1]
				                      + img.at<Vec3b>(i, j)[2]) / 3;
			img.at<Vec3b>(i, j)[1] = img.at<Vec3b>(i, j)[0];
			img.at<Vec3b>(i, j)[2] = img.at<Vec3b>(i, j)[0];
		}
	}

	//二值化
	int threshold = 0;
	Mat binaryImage;
	while (1)
	{
		binaryImage = img.clone();
		cout << "请输入二值化的阈值：(输入-1结束)    ";
		cin >> threshold;

		if (threshold == -1)
		{
			break;
		}
		if (threshold < 0 || threshold > 255)
		{
			cout << "请输入0到255范围内的数！！" << endl;
			continue;
		}
		for (int i = 0; i < binaryImage.rows; i++)
		{
			for (int j = 0; j < binaryImage.cols; j++)
			{
				binaryImage.at<Vec3b>(i, j)[0] = (binaryImage.at<Vec3b>(i, j)[0] >= threshold) ? 255 : 0;
				binaryImage.at<Vec3b>(i, j)[1] = binaryImage.at<Vec3b>(i, j)[0];
				binaryImage.at<Vec3b>(i, j)[2] = binaryImage.at<Vec3b>(i, j)[0];
			}
		}
		namedWindow("iwindow");
		imshow("iwindow", binaryImage);
		waitKey();
		destroyWindow("iwindow");
	}

	// 对数变换
	double r;
	double c;
	Mat logImage;
	while (1)
	{
		logImage = img.clone();
		cout << "请输入对数变换的底数：(输入-1结束)    ";
		cin >> r;
		if (r == -1)
		{
			break;
		}
		if (r <= 0)
		{
			cout << "请输入一个正数！！" << endl;
			continue;
		}
		c = 255.0 / (  log10(256) / log10(r)  );
		//cout << " c i s " <<c << endl;
		for (int i = 0; i < logImage.rows; i++)
		{
			for (int j = 0; j < logImage.cols; j++)
			{
				//cout << logImage.at<Vec3b>(i, j) << "->";
				logImage.at<Vec3b>(i, j)[0] = c * (log10(logImage.at<Vec3b>(i, j)[0] + 1) / log10(r));
				logImage.at<Vec3b>(i, j)[1] = logImage.at<Vec3b>(i, j)[0];
				logImage.at<Vec3b>(i, j)[2] = logImage.at<Vec3b>(i, j)[0];
				//cout << logImage.at<Vec3b>(i, j) << endl;
			}
		}
		namedWindow("iwindow");
		imshow("iwindow", logImage);
		waitKey();
		destroyWindow("iwindow");
	}
	
	//gama变换
	double gama;
	Mat gamaImage;
	double gamaCons;
	while (1)
	{
		gamaImage = img.clone();
		cout << "请输入gama变换的指数：(输入-1结束)    ";
		cin >> gama;

		if (gama == -1)
		{
			break;
		}
		if (gama <= 0)
		{
			cout << "请输入一个正数！！" << endl;
			continue;
		}
		gamaCons = 255 / pow(256, gama);
		for (int i = 0; i < gamaImage.rows; i++)
		{
			for (int j = 0; j < gamaImage.cols; j++)
			{
				gamaImage.at<Vec3b>(i, j)[0] = gamaCons * pow(gamaImage.at<Vec3b>(i, j)[0], gama);
				gamaImage.at<Vec3b>(i, j)[1] = gamaImage.at<Vec3b>(i, j)[0];
				gamaImage.at<Vec3b>(i, j)[2] = gamaImage.at<Vec3b>(i, j)[0];
			}
		}
		namedWindow("iwindow");
		imshow("iwindow", gamaImage);
		waitKey();
		destroyWindow("iwindow");
	}

	return 0;
}

#include "stdafx.h"  
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#define GRAYLEVEL 256
using namespace std;
using namespace cv;

void disImg(const Mat & img);
void igray(Mat & img);
void getHist(const Mat & img, double hist[]);
void equalizeImg(Mat & img);
Mat & disHist(const Mat & img);
void getColorHist(const Mat & img, double histB[], double histG[], double histR[]);
void equalizeColorImg(Mat & img);

Mat equalizedColorImage;
int main()
{
	Mat img = imread("C:/Users/JamesBond/Desktop/1920x1200.jpg");
	if (img.empty())
	{
		cout << "error";
		return -1;
	}
	disImg(img);
	equalizeColorImg(img);
	disImg(equalizedColorImage);
	igray(img);
	disImg(img);
	disHist(img);
	equalizeImg(img);
	disImg(img);
	disHist(img);
	return 0;
}

inline void disImg(const Mat & img)
{
	namedWindow("iwindow");
	imshow("iwindow", img);
	waitKey();
	destroyWindow("iwindow");
}

void igray(Mat & img)
{
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			uchar temp = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1]
				+ img.at<Vec3b>(i, j)[2]) / 3;
			img.at<Vec3b>(i, j)[0] = temp;
			img.at<Vec3b>(i, j)[1] = temp;
			img.at<Vec3b>(i, j)[2] = temp;
		}
	}
}

/*
* 前提条件：img为灰度图
* hist[]为返回的归一化直方图，若 hist[i] == j,则说明灰度值
* 为i的像素点出现的概率为j，j的范围为 0=<j<=1,不会改变原始图像
*/
void getHist(const Mat & img, double hist[])
{
	for (int i = 0; i < GRAYLEVEL; i++)
	{
		hist[i] = 0;
	}

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			uchar temp = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1]
				+ img.at<Vec3b>(i, j)[2]) / 3;
			hist[temp]++;
		}
	}

	//归一化
	double max = 0;
	for (int i = 0; i < 256; i++)
	{
		hist[i] = (double)hist[i] / (img.rows*img.cols);
		if (hist[i] > max)
		{
			max = hist[i];
		}
	}
}

void getColorHist(const Mat & img, double histB[], double histG[], double histR[])
{
	for (int i = 0; i < GRAYLEVEL; i++)
	{
		histB[i] = 0;
		histG[i] = 0;
		histR[i] = 0;
	}

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			histB[img.at<Vec3b>(i, j)[0]]++;
			histG[img.at<Vec3b>(i, j)[1]]++;
			histR[img.at<Vec3b>(i, j)[2]]++;

		}
	}

	//归一化
	double max = 0;
	for (int i = 0; i < 256; i++)
	{
		histB[i] = (double)histB[i] / (img.rows*img.cols);
		histG[i] = (double)histG[i] / (img.rows*img.cols);
		histR[i] = (double)histR[i] / (img.rows*img.cols);

	}
}

/*
*直方图均衡函数
*会改变原始图像，并返回改变后的图像
*/
void equalizeImg(Mat & img)
{
	double hist[GRAYLEVEL];
	getHist(img, hist);

	//计算直方图均衡函数func
	double func[256] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			func[i] += hist[j];
		}
	}
	for (int i = 0; i < 256; i++)
	{
		func[i] = cvRound(255 * func[i]);
	}

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			uchar temp = func[img.at<Vec3b>(i, j)[0]];
			img.at<Vec3b>(i, j)[0] = temp;
			img.at<Vec3b>(i, j)[1] = temp;
			img.at<Vec3b>(i, j)[2] = temp;
		}
	}
}

void equalizeColorImg(Mat & src)
{
	Mat img = src.clone();
	double histB[GRAYLEVEL];
	double histG[GRAYLEVEL];
	double histR[GRAYLEVEL];
	getColorHist(img, histB, histG, histR);

	//计算直方图均衡函数func
	double funcB[256] = { 0 };
	double funcG[256] = { 0 };
	double funcR[256] = { 0 };
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			funcB[i] += histB[j];
			funcG[i] += histG[j];
			funcR[i] += histR[j];
		}
	}

	for (int i = 0; i < 256; i++)
	{
		funcB[i] = cvRound(255 * funcB[i]);
		funcG[i] = cvRound(255 * funcG[i]);
		funcR[i] = cvRound(255 * funcR[i]);
	}

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			img.at<Vec3b>(i, j)[0] = funcB[img.at<Vec3b>(i, j)[0]];
			img.at<Vec3b>(i, j)[1] = funcB[img.at<Vec3b>(i, j)[1]];
			img.at<Vec3b>(i, j)[2] = funcB[img.at<Vec3b>(i, j)[2]];
		}
	}
	equalizedColorImage = img;
}

Mat & disHist(const Mat & img)
{
	double hist[GRAYLEVEL];
	getHist(img, hist);

	double max = 0;
	for (int i = 0; i < GRAYLEVEL; i++)
	{
		if (hist[i] > max)
		{
			max = hist[i];
		}
	}
	int histHeight = 300; //直方图的高度
	int bins = 256;   //直方图横坐标所划分的区间数目
	int binWid = 2;    //每个区间的长度为 2-1 = 1
	Mat histImage(histHeight, binWid * bins, CV_8UC3, Scalar(0, 0, 0));

	for (int i = 0; i < bins; i++)
	{
		int recheight = cvRound((hist[i] / max) * histHeight);  //矩形的高度

		/* 线宽默认为1，那在画图时，以 坐标点为中点，向内膨胀0.5
		* 向外膨胀0.5
		*/
		rectangle(histImage, Point(i*binWid, histHeight - 1),
			Point((i + 1) * binWid - 1, histHeight - recheight),
			CV_RGB(255, 255, 255));
	}
	disImg(histImage);
	return histImage;
}