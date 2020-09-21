#ifndef _SoundEvent_h_
#define _SoundEvent_h_

struct SoundEvent {
	union {
		int timeStamp;
		float secondsAgo;
	};
	float x,y,z,E;
	int id;
	float r,g,b,a;
};

#endif
