#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> v1;
	cout << "v1: {size: " << v1.size() << " values: [";
	for(auto i: v1)
		cout << i << ",";
	if(!v1.empty())
		cout << '\b';
	cout << "]\n";

	vector<int> v2(10);
	cout << "v2: {size: " << v2.size() << " values: [";
	for(auto i: v2)
		cout << i << ",";
	if(!v2.empty())
		cout << '\b';
	cout << "]\n";

	vector<int> v3(10, 42);
	cout << "v3: {size: " << v3.size() << " values: [";
	for(auto i: v3)
		cout << i << ",";
	if(!v3.empty())
		cout << '\b';
	cout << "]\n";

	vector<int> v4{10};
	cout << "v4: {size: " << v4.size() << " values: [";
	for(auto i: v4)
		cout << i << ",";
	if(!v4.empty())
		cout << '\b';
	cout << "]\n";
	
	vector<int> v5{10, 42};
	cout << "v5: {size: " << v5.size() << " values: [";
	for(auto i: v5)
		cout << i << ",";
	if(!v5.empty())
		cout << '\b';
	cout << "]\n";
	
	vector<string> v6{10};
	cout << "v6: {size: " << v6.size() << " values: [";
	for(auto i: v6)
		cout << i << ",";
	if(!v6.empty())
		cout << '\b';
	cout << "]\n";

	vector<string> v7{10, "hi"};
	cout << "v7: {size: " << v7.size() << " values: [";
	for(auto i: v7)
		cout << i << ",";
	if(!v7.empty())
		cout << '\b';
	cout << "]\n";
	return 0;
}








