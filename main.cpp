#include <iostream>
#include <graphics.h>
#include <stack>
#include <string>
#include <conio.h> 

using namespace std;

class code_class{
	private:
		int origin_x = 300;
		int origin_y = 300;
		int direct_xy[8][2] = {{1, 0}, {1.414, 1.414}, {0, 1}, {-1.414, 1.414}, 
							   {-1, 0}, {-1.414, -1.414}, {0, -1}, {1.414, -1.414}};
		int op_direct = 0;   //control the directions
		int op_color = 0;    //control the directions
		int color[8] = {5, 4, 14, 2, 3, 1, 15, 0};
		
	
	public:
		void c_code();
		void f_code();
		void r_code();
		void back_origin();
		void getLength(int f_len);
};

void code_class::f_code(){
	setcolor(this->color[this->op_color]);
	setlinestyle(PS_SOLID, 3, 3);
	line(this->origin_x, 
		 this->origin_y, 
		 this->origin_x + 10 * direct_xy[this->op_direct][0], 
	     this->origin_y + 10 * direct_xy[this->op_direct][1]);
	     
	this->origin_x = this->origin_x + 10 * direct_xy[this->op_direct][0];
	this->origin_y = this->origin_y + 10 * direct_xy[this->op_direct][1];
}


void code_class::r_code(){
	if(this->op_direct == 7){
		this->op_direct = 0;
	}
	else{
		this->op_direct++;
	}
} 

void code_class::c_code(){
	if(this->op_color == 7){
		this->op_color = 0;
	}
	else{
		this->op_color++;
	}
} 

void code_class::back_origin(){
	this->origin_x = 300;
	this->origin_y = 300;
}

//-----------------------------------------------------------------------------------------


int main(int argc, char** argv) {
	
	int gd = DETECT, gm;  
    initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	int f_len = 0;
	cout << "enter the code : " << endl;
	stack<char> st_len;
	code_class cc;
	char tmp;
	while(1){
		tmp = getche();
		if(tmp == '['){
			cout << "got you!";
		}
		if(tmp == 'f'){
			cc.f_code();
		}
		else if(tmp == 'r'){
			cc.r_code();
		}
		else if(tmp == 'c'){
			cc.c_code();
		}
		else if(tmp == 's'){  
			cleardevice();
			cc.back_origin();
		}
		else if(tmp == 'j'){
			cout << endl;
			cc.back_origin();
			continue;
		}
	}
	
	return 0;
}


