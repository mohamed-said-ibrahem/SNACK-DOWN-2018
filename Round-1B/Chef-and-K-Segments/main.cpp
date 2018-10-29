#include <bits/stdc++.h>
using namespace std;
struct structure
{   int left, right;
    bool operator < (const structure& temp)
    {	if(left != temp.left)
        return left < temp.left;
        else
        return right < temp.right;}
}struc[200100];
int arra[200100];int var;
int sumValues(int input){
    int value = 0;
    while(input){
    	value += arra[input];
    	input -= input&-input;
    }
    return value;}
int main()
{	int t;
    cin>>t;
    while(t--){
    	for(int i=0;i<200100;i++)
        arra[i]=0;
        int n, k;
        cin>>n>>k;
        vector<int> myVec;
        for(int i = 0; i < n; i++){
        	cin>>struc[i].left>>struc[i].right;
        	myVec.push_back(struc[i].left); myVec.push_back(struc[i].right);
        }
        sort(myVec.begin(), myVec.end());
        myVec.erase(unique(myVec.begin(),myVec.end()), myVec.end());
        var = myVec.size();
        sort(struc, struc+n);
        int answer = 0;
        for(int i = 0; i < n; i++){
            int lowerRight = lower_bound(myVec.begin(),myVec.end(), struc[i].right)-myVec.begin()+1;
            int lowerLeft = lower_bound(myVec.begin(),myVec.end(), struc[i].left)-myVec.begin()+1;
            while(lowerRight <= var){
                arra[lowerRight] += 1;
                lowerRight += lowerRight&-lowerRight;
            }
            int rgt = var,lft = lowerLeft;
            while(lft <= rgt){
                int maxii = (lft+rgt)/2;
                if(sumValues(var)-sumValues(maxii-1) >= k){
                    answer = max(answer, myVec[maxii-1]-myVec[lowerLeft-1]);
                    lft = maxii+1;
                }else rgt = maxii-1;
            }
        }
        cout<<answer<<endl;
    }
    return 0;
}
