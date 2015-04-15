#include <math.h>
#include <google/dense_hash_map>
#include "ppjoin.h"

typedef google::dense_hash_map<int, Counter> hashmap_t; // store candidates with google hash map
typedef google::dense_hash_map<int, Counter>::iterator hashmap_iterator_t;


void ppjoin::PerformJoin()
{
	int i, j, x, y, lenx, leny, token, score;
	int lengthLowerBound, hammingDistanceThreshold;
	int candidateNum, intersectionNum, resultNum;
	result resultFound;
	vector<int> requiredOverlap;
	vector<double> sqrtLen;
	hashmap_t candidates;
	hashmap_iterator_t it;
	candidates.set_empty_key(0xffffffff);

	cerr << "Algorithm: ppjoin" << endl;

	candidateNum = intersectionNum = resultNum = 0; // statistics
	
	/* store square root of length for cosine similarity */
	sqrtLen.resize(joinRecord[recordNum - 1].len + 1);
	for (i = 0; i <= joinRecord[recordNum - 1].len; i++) sqrtLen[i] = sqrt(i); 

	for (x = 0; x < recordNum; x++) {
		lenx = joinRecord[x].len; // fetch length of x

		candidates.clear_no_resize(); // initialize candidate set
		
		/* initialize required overlap */
		requiredOverlap.clear();
		requiredOverlap.resize(lenx + 1); 

		/* calculate required overlap */
		if (jaccard) {
			lengthLowerBound = int(lenx * threshold - EPS) + 1;
			for (i = lengthLowerBound; i <= lenx; i++)
				requiredOverlap[i] = int((i + lenx) * threshold / (1 + threshold) - EPS) + 1;
		}
		else if (cosine) {
			lengthLowerBound = int(lenx * threshold * threshold - EPS) + 1;
			for (i = lengthLowerBound; i <= lenx; i++)
				requiredOverlap[i] = int(sqrt(lenx) * sqrtLen[i] * threshold - EPS) + 1;
		}

		/* probing phase */
		for (i = 0; i < joinRecord[x].probePrefixLength; i++) {
			token = joinRecord[x].tokenArray[i]; // fetch token x[i]
			if (invertedList[token].startingPosition == -1) continue; // no inverted list found for x[i]

			for (j = invertedList[token].startingPosition; j < invertedList[token].list.size() && joinRecord[invertedList[token].list[j].rec].len < lengthLowerBound; j++); // move forward the head of inverted list of x[i]

			/* access inverted list of x[i] */
			for (invertedList[token].startingPosition = j; j < invertedList[token].list.size(); j++) {
				y = invertedList[token].list[j].rec; // fetch y
				leny = joinRecord[y].len; // fetch length of y
				if (y >= x) break; // y >= x --> length of y >= length of x; note that we sort records according to length

				it = candidates.find(y); // check if candidate y has been found before
				if (it != candidates.end()) it->second.increment(); // y has been found 
				else {
					if (lenx - i < requiredOverlap[leny] || leny - invertedList[token].list[j].pos < requiredOverlap[leny]) continue; //ppjoin
					candidates[y].increment(); // y has not been found, form new candidate
				}
			}
		}

		/* verification phase */
		for (it = candidates.begin(); it != candidates.end(); ++it) {
			y = it->first, score = it->second.count; // fetch y and A[y]
			leny = joinRecord[y].len; // fetch length of y
			++candidateNum;

			/* optimize verification by comparing the last tokens in x's and y's prefix */
			if (joinRecord[x].tokenArray[joinRecord[x].probePrefixLength - 1] < joinRecord[y].tokenArray[joinRecord[y].indexPrefixLength - 1]) {
				if (score + lenx - joinRecord[x].probePrefixLength >= requiredOverlap[leny]) { // check the upper bound of overlap
					++intersectionNum;
					score += CountOverlap(joinRecord[x].tokenArray, joinRecord[y].tokenArray, lenx, leny, joinRecord[x].probePrefixLength, score, requiredOverlap[leny] - score); // calculate exact similarity

					/* insert into join results */
					if (score >= 0) {
						resultFound.xid = joinRecord[x].rid, resultFound.yid = joinRecord[y].rid;
						if (jaccard) 
							resultFound.sim = double(score) / double(lenx + leny - score);
						else if (cosine) 
							resultFound.sim = double(score) / double(sqrtLen[lenx] * sqrtLen[leny]);
						joinResult.push_back(resultFound);
						++resultNum;
					}
				}
			}
			else {
				if (score + leny - joinRecord[y].indexPrefixLength >= requiredOverlap[leny]) { // check the upper bound of overlap
					++intersectionNum;
					score += CountOverlap(joinRecord[x].tokenArray, joinRecord[y].tokenArray, lenx, leny, score, joinRecord[y].indexPrefixLength, requiredOverlap[leny] - score); // calculate exact similarity

					/* insert into join results */
					if (score >= 0) {
						resultFound.xid = joinRecord[x].rid, resultFound.yid = joinRecord[y].rid;
						if (jaccard) 
							resultFound.sim = double(score) / double(lenx + leny - score);
						else if (cosine) 
							resultFound.sim = double(score) / double(sqrtLen[lenx] * sqrtLen[leny]);
						joinResult.push_back(resultFound);
						++resultNum;
					}
				}
			}
		}
	}

	/* output statistics */
	cerr << "# Results: " << resultNum << endl;
	cerr << "# Candidate Pairs: " << candidateNum << endl;
	cerr << "# Intersections Performed: " << intersectionNum << endl;
}

int ppjoin::CountOverlap(vector<int>& xArray, vector<int>& yArray, int xLen, int yLen, int xStart, int yStart, int requiredOverlap)
{
	int i = xStart, j = yStart, ans = 0;
	while (i < xLen && j < yLen) {
		if (xArray[i] == yArray[j]) ++i, ++j, ++ans;
		else {
			if (xArray[i] < yArray[j]) ++i;
			else ++j;
		}
	}
	if (ans < requiredOverlap) return -INF;
	else return ans;
}
