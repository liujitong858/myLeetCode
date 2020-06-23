#include<map>
#include<vector>
using namespace std;
namespace leetcode860 {
	class Solution {
	public:
		bool lemonadeChange(vector<int>& bills) {
			if (bills.empty()) return false;
			map<int, int> packet;
			for (int i = 0; i < bills.size(); ++i) {
				if (bills[i] == 5) {
					packet[5]++;
				}
				else if (bills[i] == 10) {
					if (packet[5] == 0) {//Ã»ÓÐÁãÇ®ÁË
						return false;
					}
					else {
						packet[5]--;
						packet[10]++;
					}
				}
				else {

					if (packet[5] >= 3 && packet[10] == 0) {
						packet[5] -= 3;
					}
					else if (packet[5] >= 1 && packet[10] >= 1) {
						packet[5]--;
						packet[10]--;
					}
					else return false;
				}
			}
			return true;
		}
	};
	bool lemonadeChange1(vector<int>& bills) {
		if (bills.empty()) return false;
		int dol_5 = 0;
		int dol_10 = 0;
		for (int cus : bills) {
			switch (cus) {
			case 5: {
				dol_5++;
				break;
			}
			case 10: {
				dol_10++;
				dol_5--;
				break;
			}
			case 20: {
				if (dol_10 > 0) {
					dol_10--;
					dol_5--;
				}
				else dol_5 -= 3;
			}
			}
			if (dol_5 < 0) return false;
		}
		return true;
	}
}