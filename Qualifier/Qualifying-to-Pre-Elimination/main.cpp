#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;

	int n,a,b,number,counter=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a>>b;
		counter=0;
		for(int h = 1;h<=a;h++){
			cin>>number;
			v.push_back(number);
		}
		sort(v.begin(),v.end(),std::greater<int>());
		for(int k = 0;k<a;k++){
			if(v[k]>=v[b-1]){
				counter++;
			}
		}
		cout<<counter<<endl;
		  v.clear();
	}
}
