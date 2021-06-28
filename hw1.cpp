#include<iostream>

using namespace std;

int divide(int x, int y){  // x/y�� x=dy+r�� �̿��� ���ϴ� �Լ�
	
	int d=x/y;
	int unlimit=0;
	while(unlimit==0){
		if(y*d <= x) return d;
		else d--;
	}

}

int remain(int x, int y){  // x%y�� x=dy+r�� �̿��� ���ϴ� �Լ�
	
	int i=0;
	int d=x/y;
	while(i!=d){
		if(y*d <= x) i=d;
		else d--;
	}

	int r = x-y*d;
	return r;

}
	

int main(){

	int h;    // h: '��'�� �Է¹ޱ� ���� ����
	int m;    // m: '��'�� �Է¹ޱ� ���� ����
	int s;    // s: '��'�� �Է¹ޱ� ���� ����
	int l_s;  // l_s: 'lapse time'�� �Է¹ޱ� ���� ����

	cout << "Enter an hour (0...23) : ";
	cin >> h;
	cout << "Enter a minute (0...59) : ";
	cin >> m;
	cout << "Enter a second (0...59) : ";
	cin >> s;
	cout << "Enter a lapse time in seconds (-..+): ";
	cin >> l_s;
	            // ���� �Է¹���

	int t_s = h * 3600 + m * 60 + s;  // �Է¹��� h,m,s(��,��,��)�� ��� �� ������ ��ȯ

	int n_s = remain(l_s + t_s , 60);  // '��'�� 60 �̻��� ��� ��������
	int t_m = divide(l_s + t_s , 60);  // '��'�� 60 �̻��� ��� '��'���� �Ѱ���
	int n_m = remain(t_m, 60);         // '��'�� 60 �̻��� ��� ��������
	int t_h = divide(t_m, 60);         // '��'�� 60 �̻��� ��� '��'�� �Ѱ���
	int n_h = remain(t_h, 24);         // '��'�� 24 �̻��� ��� ��������

	if(t_s+l_s <= -1) {  // ��� ���� ������ ��� ������

		if(t_s+l_s <= -1 && t_s+l_s >= -60+1){
			n_s = 60 + n_s;
			n_m = 60 + n_m;
			n_h = 24 + n_h;
		}
		else if(t_s+l_s <= -60 && t_s+l_s >= -3600+1){
			n_m = 60 + n_m;
			n_h = 24 + n_h;
		}
		else if(t_s+l_s <= -3600 && t_s+l_s >= -3600*24+1){
			n_h = 24 + n_h;
		}
	}
	
	cout << h << ":" << m << ":" << s << " after "
		<< l_s << " seconds will be " << n_h << ":"
		<< n_m << ":" << n_s << "." << endl;   // ��� �� ���
	
	return 0;
}