#include <iostream>
#include <stdlib.h>
#include "headers/wave.h"
using namespace std;

int main(int argc, const char * argv[]) {
	MONO_PCM pcm0;
	char f_name[8] = "./a.wav";
	wave_read_8bit_mono(&pcm0, f_name); //入力
	
	for(unsigned long n = 0; n < pcm0.length; n++){
		cout << pcm0.s[n] << endl;
	}
	
	
	free(pcm0.s);
	return 0;
}
