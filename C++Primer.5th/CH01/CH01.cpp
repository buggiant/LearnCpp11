#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "Sales_item.h"
using namespace std;

void E1_3()
{
	cout<<"Hello World!"<<endl;
}

int E1_4()
{
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "The multi of " << v1 << " and " << v2
		<< " is " << v1 * v2 << endl;
	return 0;
}

int E1_5()
{
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 ;
	cout<< " and " << v2;
	cout<< " is " << v1 + v2 << endl;
	return 0;
}

void E1_8()
{
	cout<<"/*";
	cout<<"*/";
	//cout<</* "*/"*/;
	cout<</* "*/" /* " /*" */ ;
}

void E1_9()
{
	int i = 50;
	int sum =0;
	while (i<=100)
	{
		//cout<<i<<endl;
		sum += i++;
	}
	cout<<sum<<endl;
}

void E1_10()
{
	for (int i = 10; i >= 0; i--)
	{
		cout<<i<<endl;
	}
}

void E1_11()
{
	cout << "Enter two numbers:" << endl;
	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	int startNum = v1>v2 ? v2 : v1;
	int endNum = v1>v2 ? v1 : v2;
	for (int i = startNum; i <= endNum; i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
}

void E1_12()
{
	int sum = 0;
	for (int i = -100; i <= 100; ++i)
		sum += i;
	cout<<sum<<endl;
}

void E1_16()
{
	cout << "Enter several numbers:" << endl;
	int inNum=0;
	int sum = 0;
	while(cin>>inNum)
	{
		sum += inNum;
	}
	cout<<"The sum is "<<sum<<endl;
}

void E1_18()
{
	// currVal is the number we're counting; we'll read new values into val
	int currVal = 0, val = 0;
	// read first number and ensure that we have data to process
	if (std::cin >> currVal) {
		int cnt = 1; // store the count for the current value we're processing
		while (std::cin >> val) { // read the remaining numbers
			if (val == currVal) // if the values are the same
				++cnt; // add 1 to cnt
			else { // otherwise, print the count for the previous value
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val; // remember the new value
				cnt = 1; // reset the counter
			}
		} // while loop ends here
		// remember to print the count for the last value in the file
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	} // outermost if statement ends here
}

void E1_19()
{
	//already think about this case
	E1_10();
}

void E1_20()
{
	ifstream is("./data/book_sales");
	Sales_item si;
	while(is>>si)
	{
		cout<<si<<endl;
	}
}

void E1_21()
{
	Sales_item si1,si2;
	cin>> si1 >> si2;
	if (!compareIsbn(si1,si2))
	{
		cout<<"ISBN not same!"<<endl;
		return;
	}
	cout << endl << si1 + si2<<endl;
}

void E1_22()
{
	Sales_item si, sum;
	int cnt = 1;
	while (cin>>si)
	{
		if (cnt == 1)
		{
			sum = si;
		}else
		{
			if (!compareIsbn(sum,si))
			{
				cout<<"ISBN not same!"<<endl;
				return;
			}
			sum += si;
		}
		cnt++;
	}
	cout << endl << sum <<endl;
}

void E1_23()
{
	map<string, int> isbns;

	Sales_item si;
	int cnt = 1;
	while (cin>>si)
	{

		if (cnt == 1)
		{
			isbns.insert(pair<string,int>(si.isbn(),1));
		}else
		{
			map<string, int>::iterator it;
			it = isbns.find(si.isbn());
			if (it==isbns.end())
			{
				isbns.insert(pair<string,int>(si.isbn(),1));
			}else
			{
				it->second ++;
			}
		}
		cnt++;
	}
	for (map<string, int>::iterator it = isbns.begin(); it!=isbns.end(); it ++)
	{
		cout<<"There are "<<it->second<<" record for book "<<it->first<<"."<<endl;
	}
}

void E1_24()
{
	//operator< for Sales_item is implemented to use STL::set
	multiset<Sales_item> items;

	Sales_item si;
	while (cin>>si)
	{
		items.insert(si);
	}
	for (set<Sales_item>::iterator it = items.begin(); it!=items.end(); it ++)
	{
		cout<< *it <<endl;
	}
}

int E1_25()
{
	Sales_item total; // variable to hold data for the next transaction
	// read the first transaction and ensure that there are data to process
	ifstream is("./data/book_sales");
	if (is >> total) {
		Sales_item trans; // variable to hold the running sum
		// read and process the remaining transactions
		while (is >> trans) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else {
				// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	} else {
		// no input! warn the user
		std::cerr << "No data?!" << std::endl;
		return -1; // indicate failure
	}
	return 0;
}

int main(int argc, char** argv)
{
	cout<<"if input is needed, input ^Z as the end"<<endl;
	E1_25();
	return 0;
}