#include "ppjoin.h"

int ppjoin::GetMaxDepth()
{
	return maxDepth;
}

int ppjoin::ReadParameters(char* sim_func, char* threshold)
{
	if (sim_func[0] == 'j' || sim_func[0] == 'J') jaccard = 1;
	else if (sim_func[0] == 'c' || sim_func[0] == 'C') cosine = 1;
	else return 1;
	ppjoin::threshold = atof(threshold);
	cerr << "Similarity Function: ";
	if (jaccard == 1) cerr << "Jaccard" << endl;
	else if (cosine == 1) cerr << "Cosine" << endl;
	cerr << "Threshold: " << ppjoin::threshold << endl;
	return 0;
}

int ppjoin::ReadParameters(char* sim_func, char* threshold, char* maxDepth)
{
	if (sim_func[0] == 'j' || sim_func[0] == 'J') jaccard = 1;
	else if (sim_func[0] == 'c' || sim_func[0] == 'C') cosine = 1;
	else return 1;
	ppjoin::threshold = atof(threshold);
	ppjoin::maxDepth = atoi(maxDepth);
	cerr << "Similarity Function: ";
	if (jaccard == 1) cerr << "Jaccard" << endl;
	else if (cosine == 1) cerr << "Cosine" << endl;
	cerr << "Threshold: " << ppjoin::threshold << endl;
	return 0;
}

void ppjoin::ReadData(char* filename)
{
	int i, rid, rlen;
	int totalLen = 0;
	int inputToken;
	record inputRecord;
	FILE *fp;
	fp = fopen(filename, "rb");

	/* read binary data */
	while (fread(&rid, sizeof(int), 1, fp) == 1) {
		fread(&rlen, sizeof(int), 1, fp);
		totalLen += rlen;
		inputRecord.rid = rid, inputRecord.len = rlen, inputRecord.tokenArray.clear();
		for (i = 0; i < rlen; i++) {
			fread(&inputToken, sizeof(int), 1, fp);
			if (inputToken > tokenNum) tokenNum = inputToken;
			inputRecord.tokenArray.push_back(inputToken);
		}
		joinRecord.push_back(inputRecord);
		++recordNum;
	}
	fclose(fp);
	++tokenNum;

	/* output statistics */
	cerr << "# Records: " << recordNum << endl;	
	cerr << "# Average Record Size: " << double(totalLen) / recordNum << endl;	
	cerr << "# Maximum Record Size: " << joinRecord[recordNum - 1].len << endl;
}

void ppjoin::WriteResults()
{
	int i;
	vector<result>::iterator it;
	for (it = joinResult.begin(); it != joinResult.end(); ++it)
		cout << it->xid << " " << it->yid << " " << setiosflags(ios::fixed) << setprecision(3) << it->sim << endl;
}

