#pragma once
#include <string>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "Windows.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
#include "mouse.h"

class Screen
{
public:
	void screenshotSave(std::string locate);
	void screenshotRegion(std::string locate, int xStart, int yStart, int xEnd, int yEnd);
	std::pair<bool, std::pair<int, int>>locateonScreen(std::string imgREF, std::string imgFIND, double confidence);
	std::pair<bool, std::pair<int, int>>locatecenteronScreen(std::string imgREF, std::string imgFIND, double confidence);
	bool findWindow(std::string nameWindow);
	void sendInputToWindow();
	std::string imageToText(std::string target, char language[45]);
	void recordCordenites(int& xS, int& yS, int& xE, int& yE);
private:
};