#ifndef ROSLEAP_LISTENER_H
#define ROSLEAP_LISTENER_H

class Leap::Listener;

namespace rosleap {

class Listener : public Leap::Listener {

public:
	Listener() : Leap::Listener() {}
	~Listener() {}

	virtual void onFrame(const Leap::Controller&);

};

}

#endif
