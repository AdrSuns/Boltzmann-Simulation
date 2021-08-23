#include <iostream>
#include <vector>
using namespace std;

const int num = 200;

class Grid{
public:
	static int nextIndex;
 	static Grid grids[num];
	int index;
	int quant = 1;
	Grid() : index(nextIndex++) {}
	void move(){
		if (quant == 0) return;
		quant--;
		grids[randIndex()].recieve();
	}
	void recieve(){
		quant++;
	}
	int randIndex(){
		int randind = rand() % num;
		return randind != index ? randind : randIndex();
	}
};
	
int Grid::nextIndex = 0;
Grid Grid::grids[num]{};
	
int main()
{
	srand((unsigned)time(NULL)); 
	int swap_times = 500;
	vector<int> stats(num);
	
	for (int i = 0; i != swap_times; i++)
		for (int t = 0; t != num; t++)
			Grid::grids[t].move();
		
	for (int i = 0; i != num; i++)
		stats[Grid::grids[i].quant]++;
	for (int i = 0; i != num; i++){
		cout << i << " : ";
		int value = stats[i];
		for (int t = 0; t != value; t++) cout << "|";
		cout << endl;
	}
	
   return 0;
}
