#include "cap_ffmpeg_impl.hpp"

int main()
{
	CvCapture_FFMPEG c;
	c.init();
	auto success = c.open("rtsp://192.168.3.173/media/video1");

	while (c.grabFrame())
	{
		timespec timespec;
		get_monotonic_time(&timespec);
		printf("got frame %ld\n", timespec.tv_nsec);		;
	}

	return 0;
}

