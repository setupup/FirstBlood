#include <iostream>
#include <string>
#include <cassert>
//#include "Timer.h"
#include "trie.h"
#include <Windows.h>


using namespace std;
int main()
{
	double elapsetime;
	
	trie t;
	
	/*This is the preprocess region of the string*/
	bool flag;
	flag=t.preprocess();
	
	//fstream output("finalDMV.txt", ios_base::in|ios_base::app);

	
	/*t.insert("wargame",1,1);
	t.insert("wombat",2,2);
	t.insert("wolfram",3,3);
	t.insert("world",4,4);
	t.insert("work",5,5);*/
	//generate something according to the origin data into the output
	//ifstream input("finally.txt"); //origin source
	//double coor[2];
	//string temp;
	//while (input >> temp)
	//{
	//	input >> coor[0] >> coor[1];
	//	t.generate_DMV(temp,coor[0],coor[1], output);
	//}
	
	
	//string dmv;
	//double coordinate[2];
	//output.seekg(0); //
	//double start = GetTickCount();
	//while (output >> dmv) //output format text co1 co2
	//{
	//	output >> coordinate[0] >> coordinate[1];
	//	t.insert(dmv,coordinate[0],coordinate[1]);
	//}
	//double end = GetTickCount();
	//cout << end-start << endl;
	//t.printlist(t.complete("wo"));
	//start = GetTickCount();
	//auto list = t.complete("pl");
	//end = GetTickCount();
	//cout << end-start << endl;
	//double left[2] = { 48.0, -125.0 };
	//double right[2] = { 31, -83 };
	//auto result = t.singleGeoQuery(list,left ,right );
	//t.printlist(list);
	
	
	

	std::cout << "All ok." << std::endl;
	return 0;
}

//assert(t.size() == 5);
//assert(t.has("war") == false);
//assert(t.has("wargame") == true);

//auto candidates = t.complete("wo");
//assert(candidates.size() == 4);

//candidates = t.complete("warg");
//assert(candidates.size() == 1);
//assert(*candidates[0] == "wargame");
