//Author: Tharith Sovann
#include <iostream>
#include <string>

using namespace std;

class LFSR {
	public:
	
	LFSR(string seed, int t){ bits = seed; tap_position = t;} // constructor to create LFSR with
			       	  // the given initial seed and tap
	int step(); 		  // simulate one step and return the
				  // new bit as 0 or 1
	int generate(int k);      // simulate k steps and return
			          // k-bit integer
	friend ostream& operator << (ostream& out, LFSR &pLFSR);

	private:
	int tap_position;
	string bits;
};
