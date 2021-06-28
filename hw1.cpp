#include<iostream>

using namespace std;

int divide(int x, int y){  // x/y를 x=dy+r를 이용해 구하는 함수
	
	int d=x/y;
	int unlimit=0;
	while(unlimit==0){
		if(y*d <= x) return d;
		else d--;
	}

}

int remain(int x, int y){  // x%y를 x=dy+r를 이용해 구하는 함수
	
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

	int h;    // h: '시'를 입력받기 위한 변수
	int m;    // m: '분'를 입력받기 위한 변수
	int s;    // s: '초'를 입력받기 위한 변수
	int l_s;  // l_s: 'lapse time'을 입력받기 위한 변수

	cout << "Enter an hour (0...23) : ";
	cin >> h;
	cout << "Enter a minute (0...59) : ";
	cin >> m;
	cout << "Enter a second (0...59) : ";
	cin >> s;
	cout << "Enter a lapse time in seconds (-..+): ";
	cin >> l_s;
	            // 값을 입력받음

	int t_s = h * 3600 + m * 60 + s;  // 입력받은 h,m,s(시,분,초)를 모두 초 단위로 변환

	int n_s = remain(l_s + t_s , 60);  // '초'가 60 이상일 경우 정리해줌
	int t_m = divide(l_s + t_s , 60);  // '초'가 60 이상일 경우 '분'으로 넘겨줌
	int n_m = remain(t_m, 60);         // '분'이 60 이상일 경우 정리해줌
	int t_h = divide(t_m, 60);         // '분'이 60 이상일 경우 '시'로 넘겨줌
	int n_h = remain(t_h, 24);         // '시'가 24 이상일 경우 정리해줌

	if(t_s+l_s <= -1) {  // 결과 값이 음수일 경우 재정리

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
		<< n_m << ":" << n_s << "." << endl;   // 결과 값 출력
	
	return 0;
}