#ifndef TOOLS_H
#define TOOLS_H

#include "video.h"
#include "videolist.h"

//function prototypes
int readInt(const char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, VideoList &);
void addVideo(Video &);
void convertCase(char tempStr[]);

#endif
