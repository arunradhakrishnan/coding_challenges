#include<iostream>    
#include<vector> 
using namespace std;
int main()
{  
	vector<int> vec {1,2,3,4,5};
	
	cout<<"Intially vector: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}
	
	vec.insert(vec.begin(), 10);//Inserting 10 to the vector
    vec.insert(vec.begin(), 20);//Inserting 10 to the vector
    vec.insert(vec.begin(), 30);//Inserting 10 to the vector
    
    vec.pop_back();
    	cout<< "" <<vec.back()<<"\n";
	
	cout<<"\n\nThe modified vector is: ";
	//for(auto i = vec.begin(); i < vec.end(); i++)
    for(auto i : vec)
	{
		cout<<" "<< i;
	}
    cout << "\n";
	return 0;
}