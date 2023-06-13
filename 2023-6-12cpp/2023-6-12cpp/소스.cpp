#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class member {
public:
	string name;
	int age;
};

bool compare(member& a, member& b) {
	return a.age > b.age;
}
void BinarySearch(vector<int>& age);
int main() {
	//vector<int> vt1{ 6,3,4,5,2,1,7 };
	//sort(vt1.begin(), vt1.end());
	//sort(vt1.begin(), vt1.end(), greater<int>());
	//vector<member> vt2{ {"고라파덕",8},{"피카츄", 7}, {"잠만보",10 } };
	//sort(vt2.begin(), vt2.end(), compare);
	//for (auto item : vt2) {
	//	cout << item.name << endl;
	//}
	//return 0;

	vector<int> age;
	int min, max;
	cout << "나이의 최소값, 최대값 입력 : ";
	cin >> min >> max;
	for (int i = min; i <= max; ++i)
	{
		age.push_back(i);
	}
	cout << "나이가 맞다면 YES, 더 많다면 UP, 더 적다면 DOWN을 입력하세요.\n";
	BinarySearch(age);
}
void BinarySearch(vector<int>& age) {
	int left = 0, right = age.size() - 1;
	while (left <= right)
	{
		int mid = floor((right + left) / 2 + 0.5);
		string answer;
		cout << age[mid] << "살 입니까? : ";
		cin >> answer;
		if (answer == "YES") {
			cout << "이김";
			return;
		}
		else if (answer == "DOWN")
			right = mid - 1;
		else if (answer == "UP")
			left = mid + 1;
	}
	cout << "제대로 하세요";
	return;
}