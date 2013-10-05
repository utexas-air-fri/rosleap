
#include <stdio.h>
#include <math.h>
#include "ros/ros.h"
#include "rosleap/leap.h"
#include "Leap.h"
#include "Listener.h"

ros::Publisher publisher;
Leap::Controller controller;
rosleap::Listener listener;
rosleap::leap output;

#define DEGREES(x) ((x)/M_PI*180.0)

int main(int argc, char** argv) {

	ros::init(argc, argv, "rosleap");
	ros::NodeHandle n;

	publisher = n.advertise<rosleap::leap>("leap", 1000);

	controller.addListener(listener);
	ros::spin();
	controller.removeListener(listener);

	return 0;

}

void rosleap::Listener::onFrame(const Leap::Controller& ctrl) {

	const Leap::Frame f = ctrl.frame();

	if (!f.hands().empty()) {
		
		const Leap::Hand& h = f.hands()[0];

		output.pos.x = DEGREES(h.palmPosition().x);
		output.pos.y = DEGREES(h.palmPosition().y);
		output.pos.z = DEGREES(h.palmPosition().z);

		output.pitch = DEGREES(h.palmNormal().pitch());
		output.roll  = DEGREES(h.palmNormal().roll());
		output.yaw   = DEGREES(h.direction().yaw());
		
		publisher.publish(output);

	}

}

