#include<vector>
using namespace std;

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		//���÷�֤�����ҵ��������ص��ļ������
		 return !(rec2[3] <= rec1[1] || rec2[1] >= rec1[3] ||
			 rec2[2] <= rec1[0] || rec2[0] >= rec1[2]);
	}
	//��ѧ�ⷨ
	bool isRectangleOverlap1(vector<int>& rec1, vector<int>& rec2) {
		//���ĵ�֮��ľ���
		int minus_x_center1 = (rec1[0] + rec1[2]) / 2;
		int minus_x_center2 = (rec2[0] + rec2[2]) / 2;
		int dis_x = abs(minus_x_center1 - minus_x_center2);//���ĵ���������
		int minus_y_center1 = (rec1[3] + rec1[1]) / 2;
		int minus_y_center2 = (rec2[3] + rec2[1]) / 2;
		int dis_y = abs(minus_y_center1 - minus_y_center2);//���ĵ����������
	    //���α߳�
		int x1 = rec1[2] - rec1[0];
		int y1 = rec1[3] - rec1[1];
		int x2 = rec2[2] - rec2[0];
		int y2 = rec2[3] - rec2[1];
		
		if (dis_x < abs(x1 + x2)/2 && dis_y < abs(y1 + y2)/2) return true;
		else return false;
	
	}
};