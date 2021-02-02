//Author: Tharith Sovann
#include "LFSR.hpp"

using namespace std;

int LFSR::step(){
	int tap = bits.size() - tap_position - 1;
	int xor_result;

	if(bits.at(tap) == bits.at(0)){
		xor_result = 0;
		bits.append("0");
	}
	else{
		xor_result = 1;
		bits.append("1");
	}
	bits.erase(0, 1);
	
	return xor_result;
}

int LFSR::generate(int k){
	int var = 0;
	for(int i = 0; i < k; i++){
		var = (var * 2) + LFSR::step();
	}
	return var;
}

ostream& operator << (ostream& out, LFSR& pLFSR){
	out << pLFSR.bits;
	return out;
}
