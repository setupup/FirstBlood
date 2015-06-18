#include "Trie.h"
#include <string>
using namespace std;

//bool trie::preprocess()
//{
//	ifstream input("finally20000.txt");
//	string temp;
//	double tempd[2];
//	vector<double> a1;
//	vector<double> a2;
//	while (input >> temp)
//	{
//		input >> tempd[0] >> tempd[1];
//		
//		if (temp[0] == 'a')
//		{
//			a1.push_back(tempd[0]);
//			a2.push_back(tempd[1]);
//			ofstream output("tokens/a.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;				
//		}
//		else if (temp[0] == 'b')
//		{
//			ofstream output("tokens/b.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'c')
//		{
//			ofstream output("tokens/c.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'd')
//		{
//			ofstream output("tokens/d.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'e')
//		{
//			ofstream output("tokens/e.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'f')
//		{
//			ofstream output("tokens/f.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'g')
//		{
//			ofstream output("tokens/g.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'h')
//		{
//			ofstream output("tokens/h.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'i')
//		{
//			ofstream output("tokens/i.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'j')
//		{
//			ofstream output("tokens/j.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'k')
//		{
//			ofstream output("tokens/k.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//
//		}
//		else if (temp[0] == 'l')
//		{
//			ofstream output("tokens/l.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'm')
//		{
//			ofstream output("tokens/m.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'n')
//		{
//			ofstream output("tokens/n.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'o')
//		{
//			ofstream output("tokens/o.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//
//		}
//		else if (temp[0] == 'p')
//		{
//			ofstream output("tokens/p.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'q')
//		{
//			ofstream output("tokens/q.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'r')
//		{
//			ofstream output("tokens/r.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 's')
//		{
//			ofstream output("tokens/s.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 't')
//		{
//			ofstream output("tokens/t.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'u')
//		{
//			ofstream output("tokens/u.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'v')
//		{
//			ofstream output("tokens/v.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'w')
//		{
//			ofstream output("tokens/w.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'x')
//		{
//			ofstream output("tokens/x.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'y')
//		{
//			ofstream output("tokens/y.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//		else if (temp[0] == 'z')
//		{
//			ofstream output("tokens/z.txt", ios_base::app);
//			output << temp << ' ' << tempd[0] << ' ' << tempd[1] << endl;
//		}
//	}
//	double mind = *(min_element(a1.begin(), a1.end()));
//	cout <<  << " " << record[1] << " " << record2[0] << " " << record2[1] << endl;
//		
//	return 1;
//
//}
