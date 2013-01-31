#include <string>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef std::map<int, int> Map;

int main()
{
	int array[] = {1,1,2,2,3,3,5,4,2,3,4,3,4,1,2,2,4,3,2,4,4,3,4,3,4};
	int n = 25;
	Map myMap;
	int length = 3;
	int total=0;
	int index=0;
	for(int i=0; i<n; i++)
	{
		if(total < length)
		{
			if(myMap.count(array[i]) > 0)
			{
				for( map<int, int>::iterator ii=myMap.begin(); ii!=myMap.end(); ++ii)
				{
					if((*ii).first == array[i])
						(*ii).second++;
				}
			}
			else
			{
				myMap.insert(pair<int, int>(array[i], 1));
				total++;
			}
			
		}
		else
		{
			for( map<int, int>::iterator ii=myMap.begin(); ii!=myMap.end();)
			{
				--(*ii).second;
				if((*ii).second == 0)
				{
					total--;
					myMap.erase(ii++);
				}
				else
				{
					ii++;
				}
					
			}
			if(total < length)
			{
				if(myMap.count(array[i]) > 0)
				{
					for( map<int, int>::iterator ii=myMap.begin(); ii!=myMap.end(); ++ii)
					{
						if((*ii).first == array[i])
							(*ii).second++;
					}
				}
				else
				{
					myMap.insert(pair<int, int>(array[i], 1));
					total++;
				}
			}
		}
		
//		cout<<"Total = "<<total<<endl;
/*		for( map<int, int>::iterator ii=myMap.begin(); ii!=myMap.end(); ++ii)
		{
			cout<<(*ii).first<<"->"<<(*ii).second<<" ";
		}
		cout<<endl;	
*/		
		
	}
//	cout<<myMap.size()<<endl;

	int count = 0;

	for( map<int, int>::iterator ii=myMap.begin(); ii!=myMap.end(); ++ii)
	{
		count =0;
//		cout<<(*ii).first<<"->"<<(*ii).second<<" ";
		for(int i=0; i<n; i++)
		{
			if(array[i] == (*ii).first)
				count++;
		}
		if(count >= (n/3))
			cout<<(*ii).first<<endl;
	}
}
