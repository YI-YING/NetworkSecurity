// AES.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define BYTE unsigned char

//BYTE AES_xtime[256];
BYTE Multi02(BYTE s) {
	return ((s << 1) ^ (((s >> 7) & 1) * 0x1b));
}

BYTE Multi03(BYTE s) {
	return ((s << 1) ^ (((s >> 7) & 1) * 0x1b)) ^ s;
}
void AES_MixColumns(BYTE state[]) {
	
	for (int i = 0; i < 4; i++) {
		BYTE s0 = state[i];
		BYTE s1 = state[i + 4];
		BYTE s2 = state[i + 8];
		BYTE s3 = state[i + 12];

		state[i] = Multi02(s0) ^ Multi03(s1) ^ s2 ^ s3;
		state[i + 4] = s0 ^ Multi02(s1) ^ Multi03(s2) ^ s3;
		state[i + 8] = s0 ^ s1 ^ Multi02(s2) ^ Multi03(s3);
		state[i + 12] = Multi03(s0) ^ s1 ^ s2 ^ Multi02(s3);

/*
		BYTE s0 = state[i + 0], s1 = state[i + 1];
		BYTE s2 = state[i + 2], s3 = state[i + 3];
		BYTE h = s0 ^ s1 ^ s2 ^ s3;		
		state[i + 0] ^= h ^ AES_xtime[s0 ^ s1];
		state[i + 1] ^= h ^ AES_xtime[s1 ^ s2];
		state[i + 2] ^= h ^ AES_xtime[s2 ^ s3];
		state[i + 3] ^= h ^ AES_xtime[s3 ^ s0];
*/		
	}
}

int main()
{
	BYTE state[] = {
/*
		0x87, 0xF2, 0x4D, 0x97,
		0x6E, 0x4C, 0x90, 0xEC,
		0x46, 0xE7, 0x4A, 0xC3,
		0xA6, 0x8C, 0xD8, 0x95
*/
		0x7C, 0x6B, 0x01, 0xD7,
		0xF2, 0x30, 0xFE, 0x63,
		0x2B, 0x76, 0x7B, 0xC5,
		0xAB, 0x77, 0x6F, 0x67

	};
/*
	for (int i = 0; i < 128; i++) {
		AES_xtime[i] = i << 1;
		AES_xtime[128 + i] = (i << 1) ^ 0x1b;
	}
*/
	AES_MixColumns(state);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << hex << (int)state[i * 4 + j] << " ";
		cout << endl;
	}
	cout << endl;


	

	getchar();

    return 0;
}

