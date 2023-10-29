# Ninja-Jump-Sample
A wrapper around SDL2 which makes use of SDL much simpler

## Motivation
For years at Shahid Beheshti University, the ITP final project was a game written using the SDL library.
Since the bare SDL library is too verbose and hard to use for first-year students in college, each year TAs create their own wrapper for SDL to ease the SDL for students.
This library is a successor of `Hash<Written for ITP96Fall>` and `Genio2<Written for ITP95Fall>` with a great experience that we learned from those libraries.

## Basic Usage
1. Put `include` directories of `SDL2`,`SDL2_image`,`SDL2_ttf`,`SDL2_mixer` in your compiler's include directory.
2. Put `lib`  directories of `SDL2`,`SDL2_image`,`SDL2_ttf`,`SDL2_mixer` in your linker's path.
3. Put `SDL2Main.lib`,`SDL2.lib`,`SDL2_image.lib`,`SDL2_mixer.lib`,`SDL2_ttf.lib` in linker's dependencies.
4. Start Coding:
```C++
#include "SBDL.h"

using namespace std;

int main(int argc, char *argv[])
{
	const int window_width = 500;
	const int window_height = 500;
	SBDL::InitEngine("SBDL Test", window_width, window_height);

	const int FPS = 60; //frame per second
	const int delay = 1000 / FPS; //delay we need at each frame


	while (SBDL::isRunning()) {
		int startTime = SBDL::getTime();
		
		SBDL::updateEvents();
		SBDL::clearRenderScreen();

		//Game logic code

		SBDL::updateRenderScreen();
		
		int elapsedTime = SBDL::getTime() - startTime;
		if (elapsedTime < delay)
			SBDL::delay(delay - elapsedTime);

	}
}

```
## License
This library is released under GPL v3
