#include <sys/time.h>
#include "ppjoin.h"

int main(int argc, char* argv[])
{
	if (argc < 4) {
		cerr << "Usage: ppjoin [sim_func] [threshold] [binary_input_file] [maxdepth (optional)]" << endl;
		return 1;
	}

	ppjoin ppjoinInstance;
	if (argc >= 5) {
		if (ppjoinInstance.ReadParameters(argv[1], argv[2], argv[4])) {
			cerr << "Similarity Function Missing!" << endl;
			return 1;
		}
	}
	else {
		if (ppjoinInstance.ReadParameters(argv[1], argv[2])) {
			cerr << "Similarity Function Missing!" << endl;
			return 1;
		}
	}

	cerr << "Document: " << argv[3] << endl;

	ppjoinInstance.ReadData(argv[3]);

	timeval timeStart, timeEnd;
	gettimeofday(&timeStart, NULL);
	cerr << "=== BEGIN JOIN (TIMER STARTED) ===" << endl;

	ppjoinInstance.CalcPrefix();
	ppjoinInstance.BuildIndex();
	ppjoinInstance.PerformJoin();
	ppjoinInstance.WriteResults();

	cerr << "=== END JOIN (TIMER STOPPED) ===" << endl;
	gettimeofday(&timeEnd, NULL);
	cerr << "Total Running Time: " << setiosflags(ios::fixed) << setprecision(3) << double(timeEnd.tv_sec - timeStart.tv_sec) + double(timeEnd.tv_usec - timeStart.tv_usec) / 1e6 << endl;
	cerr << endl;
	return 0;
}
