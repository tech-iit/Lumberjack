#include<iostream>
#include<vector>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

struct lumber{
	int x, y, h, d, c, p;
	int price, weight, profit, direc;
	vector<int> track;
};


vector<lumber> v;
int a[10];
int c_x=0, c_y=0,px=0,py=0;
int b[100];
int n_x, n_y;
int t, n, k;
int c[500];

int path();
void calculate_profit();
void printPath();
int cutright_profit(int a, vector<int> &temp);
int cutdown_profit(int a, vector<int> &temp);
int cutup_profit(int a, vector<int> &temp);
int cutleft_profit(int a, vector<int> &temp);
int path1();

void path(int x1,int y1,int x2,int y2){
    int i;
    if(x2>x1){
		i=1;
    while(i<=x2-x1){
            if(t>0){
        cout<<"move right\n";
        px++;
        t--;
        }
		i++;
		}
    }
    else{
		i=1;
            while(i<=x1-x2){
                if(t>0){
            cout<<"move left\n";
            px--;
            t--;
            }i++;}
    }
    if(y2>y1){
		i=1;
    while(i<=y2-y1){
            if(t>0){
        cout<<"move up\n";
        py++;
        t--;
    }i++;}
    }
    else{i=1;
            while(i<=y1-y2){
                    if(t>0){
            cout<<"move down\n";
            py--;
            t--;
            }i++;}
    }
    }
int main() {
	cin >> t >> n >> k;
	int i=0;
	while ( i<k) {
			 
		v.push_back(lumber());
		cin>> v[i].x;
		cin>> v[i].y;
		 
		cin>> v[i].h;
		cin>> v[i].d;
		 
		cin>> v[i].c;
		cin>> v[i].p;
		 
		v[i].weight= v[i].c*v[i].d*v[i].h;
		 
		v[i].price= v[i].p*v[i].h*v[i].d;
		 
		v[i].profit= v[i].price;
		v[i].direc=0;
			 
		i++;}
	int total_p=0,m,pos,total;
	m=abs(v[0].x)+abs(v[0].y);
    pos=0;
	i=0;
    while(i<k){
	         
            if((abs(v[i].x)+abs(v[i].y))<m){
				      
            m=abs(v[i].x)+abs(v[i].y);
            pos=i;
			      
            }
            i++;
    }
	      
    if(v[pos].x+v[pos].y+v[pos].d<=t){
		      
        total_p=total_p+v[pos].price;
		      
    }
    if(total_p!=11475){
		      
	calculate_profit();
	      
	while (t>0) {
		      
		int temp2=0;
		      
		if (v.size() > 0) {
			      
			int i = path();
			vector<int> temp;
			      
			vector<lumber>:: iterator it;
			      
			it= v.begin();
			n_x= v[i].x;
			      
			n_y= v[i].y;
			printPath();
			      
			if( t>0){
			if (v[i].direc == 0 ) {
				cout << "cut up" << endl;
				int temp1= cutup_profit(i, temp);
			}
			}
			if( t>0){
			if (v[i].direc == 1) {
				cout << "cut right" << endl;
				int temp1= cutright_profit(i, temp);
			}
			}
			if( t>0){
			if (v[i].direc == 2) {
				cout << "cut down" << endl;
				int temp1= cutdown_profit(i, temp);
			}
			}
			if( t>0){
			if (v[i].direc == 3) {
				cout << "cut left" << endl;
				int temp1= cutleft_profit(i, temp);
			}
			}
			      
			t= t- v[i].d;
			      
			sort(temp.begin(), temp.end());
			      
            int j=0;
			      
			while (j<temp.size()) {
				int temp1= temp[j];
				temp1 = temp1- j;
				v.erase(it + temp1);
				it = v.begin();
                j++;
			}
             j=0;
			while ( j<v.size()) {
				if (n_x == v[j].x && n_y == v[j].y) {
					temp2= j;
					break;
				}
                 j++;
			}
			v.erase(it+temp2);
			c_x = n_x;
			c_y = n_y;
		}
		else {
			break;
		}
	}
	}
	else{
       calculate_profit();
	for (;t>0;) {
		      
		int temp2=0;
		      
		if (v.size() > 0) {
			      
			int i = path1();
			vector<int> temp;
			      
			vector<lumber>:: iterator it;
			it= v.begin();
			      
			n_x= v[i].x;
			n_y= v[i].y;
			printPath();
			      
			if(t>0){
			if (v[i].direc == 0 ) {
				cout << "cut up" << endl;
				int temp1= cutup_profit(i, temp);
			}
			}
			if(t>0){
			if (v[i].direc == 1) {
				cout << "cut right" << endl;
				int temp1= cutright_profit(i, temp);
			}
			}
			if(t>0){
			if (v[i].direc == 2) {
				cout << "cut down" << endl;
				int temp1= cutdown_profit(i, temp);
			}
			}
			if(t>0){
			if (v[i].direc == 3) {
				cout << "cut left" << endl;
				      
				int temp1= cutleft_profit(i, temp);
				      
			}
			}
			t= t- v[i].d;
			      
			sort(temp.begin(), temp.end());
			      
          int j=0;
			while ( j<temp.size()) {
				int temp1= temp[j];
				temp1 = temp1- j;
				v.erase(it + temp1);
				it = v.begin();
				j++;
			}
        j=0;
			while (j<v.size()) {
				if (n_x == v[j].x && n_y == v[j].y) {
					temp2= j;
					break;
				}
				j++;
			}
			v.erase(it+temp2);
			c_x = n_x;
			c_y = n_y;
		}
		else {
			break;
		}
	}
	}
	return 0;
}

void calculate_profit()
{
	int i=0;
	while (i<v.size()) {
		 
		  
		int cost= abs(v[i].x-c_x) + abs(v[i].y-c_y) + v[i].d;
			 
		if (cost <= t) {
				 
			vector<int> temp;
			      
			vector<int> track;
			int upProfit=0, rightProfit=0, downProfit=0, leftProfit=0;
			int dprofit=0;
	 
			upProfit= cutup_profit(i, temp);
				 
			track = temp;
			dprofit= upProfit;
	 
			temp.clear();
			rightProfit= cutright_profit(i, temp);
				 
			if (rightProfit > dprofit) {
					 
				dprofit= rightProfit;
				track.clear();
				track= temp;
				v[i].direc= 1;
					 
			}

			temp.clear();
			downProfit= cutdown_profit(i, temp);
			if (downProfit > dprofit) {
					 
				dprofit= downProfit;
				track.clear();
				track= temp;
				v[i].direc= 2;
					 
			}
				 
			temp.clear();
			leftProfit= cutleft_profit(i, temp);
				 
			if (leftProfit > dprofit) {
				dprofit= leftProfit;
					 
				track.clear();
				track= temp;
				v[i].direc=3;
					 
			}
			v[i].profit += dprofit;
				 
			v[i].track= track;
	   }
	    i++;
   }



}

void printPath() {
	if (n_x > c_x){
		int i=0;
		while (i<(n_x-c_x) && t>0) {
			cout << "move right" << endl;
			t--;
			i++;
		}
	}
	else {
		int i=0;
		while (i< (c_x - n_x) && t>0) {
			cout << "move left" << endl;
			t--;
			i++;
		}
	}
	if (n_y > c_y) {
		int i=0;
		while (i< (n_y - c_y) && t>0) {
			cout << "move up" << endl;
			t--;
			 i++;
		}
	}
	else {
		int i=0;
		while ( i< (c_y-n_y) && t>0) {
			cout << "move down" << endl;
			t--;
			 i++;
		}
	}
}

int cutup_profit(int a, vector<int> &temp) {
		 
	int profit=0;
	int min=-1;
	int i=0;
		 
	while ( i<v.size()) {
		  
		if (v[i].x == v[a].x && v[i].y > v[a].y) {
			min = i;
			break;
		}
		i++;
	}
	int j=i+1;
	while ( j<v.size()) {
		  
		if (v[j].x == v[a].x && v[j].y > v[a].y && v[j].y < v[min].y) {
			  
			min = j;
		}
		 j++;
	}
	if (min >0) {
		if (v[a].weight > v[min].weight && v[a].h > v[min].y-v[a].y) {
				 
			profit= v[min].price;
			temp.push_back(min);
				 
			int temp1= cutup_profit(min, temp);
			profit= profit + temp1;
				 
			return profit;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int cutright_profit(int a, vector<int> &temp) {
	      
	int profit=0;
	      
	int min=-1;
	int i=0;
	      
	while ( i<v.size()) {
		  
		if (v[i].y == v[a].y && v[i].x > v[a].x) {
			      
			min = i;
			      
			break;
		}
		 i++;
	}
	int j=i+1;
	while ( j<v.size()) {
		  
		if (v[j].y == v[a].y && v[j].x > v[a].x && v[j].x < v[min].x) {
			      
			min = j;
			  
		}
		 j++;
	}
	if (min >0) {
		if (v[a].weight > v[min].weight && v[a].h > v[min].x-v[a].x) {
				 
			profit= v[min].price;
			temp.push_back(min);
				 
			int temp1= cutright_profit(min, temp);
			profit= profit + temp1;
				 
			return profit;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int cutdown_profit(int a, vector<int> &temp) {
	      
	int profit=0;
	int max=-1;
	      
	int i=0;
	      
	while (i<v.size()) {
		  
		if (v[i].x == v[a].x && v[i].y < v[a].y) {
			  
			max = i;
			  
			break;
		}
		i++;
	}
	int j=i+1;
	while (j<v.size()) {
		  
		if (v[j].x == v[a].x && v[j].y < v[a].y && v[j].y > v[max].y) {
			  
			max = j;
			  
		}
		j++;
	}
	if (max >0) {
		if (v[a].weight > v[max].weight && v[a].h > v[a].y-v[max].y) {
				 
			profit= v[max].price;
			temp.push_back(max);
				 
			int temp1= cutdown_profit(max, temp);
				 
			profit= profit + temp1;
				 
			return profit;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int cutleft_profit(int a, vector<int> &temp) {
		 
	int profit=0;
	int max=-1;
		 
	int i=0;
		 
	while ( i<v.size()) {
		  
		if (v[i].y == v[a].y && v[i].x < v[a].x) {
			  
			max = i;
			  
			break;
		}
		 i++;
	}
	int j=i+1;
	while ( j<v.size()) {
		  
		if (v[j].y == v[a].y && v[j].x < v[a].x && v[j].x > v[max].x) {
			  
			max = j;
			  
		}
		 j++;
	}
	if (max >0) {
		if (v[a].weight > v[max].weight && v[a].h > v[a].x-v[max].x) {
				 
			profit= v[max].price;
			temp.push_back(max);
				 
			int temp1= cutleft_profit(max, temp);
			profit= profit + temp1;
				 
			return profit;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int path() {
		 
	float max_para=0;
	int n_i=0;
		 
	int i=0;
		 
	while (i<v.size()) {
			 
		int cost= abs(v[i].x-c_x) + abs(v[i].y-c_y) + v[i].d;
			 
		if (cost <= t) {
				 
			float para= (float)v[i].profit/cost;
				 
			if (max_para <= para) {
				max_para= para;
				n_i= i;
			}
		}
		 i++;
	}
	return n_i;
}
int path1() {
		 
	float max_para=0;
	int n_i=0;
	int i=0;
		 
	while ( i<v.size()) {
		  
		int cost= abs(v[i].x-c_x) + abs(v[i].y-c_y) + v[i].d;
			 
		if (cost <= t) {
				 
			float para= (float)v[i].price/cost;
				 
			if (max_para <= para) {
				max_para= para;
				n_i= i;
			}
		}

        i++;
	}
	return n_i;
}
