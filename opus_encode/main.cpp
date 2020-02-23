#include <iostream>
#include <stdlib.h>
#include "headers/wave.h"
#include "headers/opus.h"

using namespace std;

int main(int argc, const char * argv[]) {
	MONO_PCM pcm0;
	char f_name[8] = "./a.wav";
	wave_read_16bit_mono(&pcm0, f_name); //入力
	
	float *f_pcm = (float *)calloc(960, sizeof(float));
	for(int n = 0; n < 960; n++){
		//cout << pcm0.s[n] << endl;
		f_pcm[n] = pcm0.s[n];
	}

	OpusEncoder *enc;
	int err = 0;
	enc = opus_encoder_create(48000, 1, 2051, &err); // setting
	//cout << err << endl;
	if(err != -1 || enc != NULL){ // check encoder init
		cout << "ENCODER CREATED!" << endl;
	}else{
		cout << "fault creating encoder" << endl;
	}

	unsigned char *packet = (unsigned char *)calloc(960, sizeof(unsigned char));; // opus payload
	opus_int32 output_len;
	output_len = opus_encode_float(enc, f_pcm, 960, packet, sizeof(packet));
	cout << "output_len is " << output_len << endl;

	// show packet
	for(int x = 0; x < output_len; x++){
		cout << +packet[x] << endl; //charを数字として出力
	}
	
	
	free(packet);
	free(f_pcm);
	free(pcm0.s);
	
	return 0;
}
