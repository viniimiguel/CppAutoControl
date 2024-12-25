#include "screen.h"


void Screen::screenshotSave(std::string locate)
{
    HWND hDesktop = GetDesktopWindow();


    RECT desktopRect;
    GetWindowRect(hDesktop, &desktopRect);
    int screenWidth = desktopRect.right;
    int screenHeight = desktopRect.bottom;


    cv::Mat screenshot = cv::Mat(screenHeight, screenWidth, CV_8UC4);
    HDC hScreenDC = GetDC(hDesktop);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, screenWidth, screenHeight);
    SelectObject(hMemoryDC, hBitmap);
    BitBlt(hMemoryDC, 0, 0, screenWidth, screenHeight, hScreenDC, 0, 0, SRCCOPY);
    GetBitmapBits(hBitmap, screenshot.total() * screenshot.elemSize(), screenshot.data);

    cv::imwrite(locate, screenshot);

    ReleaseDC(hDesktop, hScreenDC);
    DeleteDC(hMemoryDC);
    DeleteObject(hBitmap);
}
void Screen::screenshotRegion(std::string locate, int xStart, int yStart, int xEnd, int yEnd) {
    HWND hDesktop = GetDesktopWindow();

    int xMin = min(xStart, xEnd);
    int xMax = max(xStart, xEnd);
    int yMin = min(yStart, yEnd);
    int yMax = max(yStart, yEnd);

    int regionWidth = xMax - xMin;
    int regionHeight = yMax - yMin;

    cv::Mat screenshot = cv::Mat(regionHeight, regionWidth, CV_8UC4);
    HDC hScreenDC = GetDC(hDesktop);
    HDC hMemoryDC = CreateCompatibleDC(hScreenDC);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, regionWidth, regionHeight);
    SelectObject(hMemoryDC, hBitmap);
    BitBlt(hMemoryDC, 0, 0, regionWidth, regionHeight, hScreenDC, xMin, yMin, SRCCOPY);
    GetBitmapBits(hBitmap, screenshot.total() * screenshot.elemSize(), screenshot.data);
    cv::imwrite(locate, screenshot);
    ReleaseDC(hDesktop, hScreenDC);
    DeleteDC(hMemoryDC);
    DeleteObject(hBitmap);
}


std::pair<bool, std::pair<int, int>>Screen::locateonScreen(std::string imgREF, std::string imgFIND, double confidence)
{
    cv::Mat largerImage = cv::imread(imgREF);
    cv::Mat smallerImage = cv::imread(imgFIND);

    if (largerImage.empty() || smallerImage.empty()) {
        std::cerr << "Erro: Imagem vazia." << std::endl;
        return { false, {0,0} };
    }

    cv::Mat result;
    cv::matchTemplate(largerImage, smallerImage, result, cv::TM_CCOEFF_NORMED);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);


    double threshold = confidence;

    if (maxVal >= threshold) {
        std::cout << "a imagem menor esta contida na imagem maior" << std::endl;
        return { true, {maxLoc.x, maxLoc.y} };

    }
    else {
        std::cout << "a imagem menor nao esta contida na imagem maior" << std::endl;
        return { false, {0,0} };
    }


}
std::pair<bool, std::pair<int, int>>Screen::locatecenteronScreen(std::string imgREF, std::string imgFIND, double confidence)
{
    cv::Mat largerImage = cv::imread(imgREF);
    cv::Mat smallerImage = cv::imread(imgFIND);

    if (largerImage.empty() || smallerImage.empty()) {
        std::cerr << "Erro: Imagem vazia." << std::endl;
        return { false, {0,0} };
    }

    cv::Mat result;
    cv::matchTemplate(largerImage, smallerImage, result, cv::TM_CCOEFF_NORMED);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);


    double threshold = confidence;

    if (maxVal >= threshold) {
        int largura = smallerImage.cols;
        int altura = smallerImage.rows;
        int center_x = maxLoc.x + (largura / 2);
        int center_y = maxLoc.y + (altura / 2);
        std::cout << "Tamanho da imagem - Altura: " << altura << " pixels, Largura: " << largura << " pixels" << std::endl;
        std::cout << "a imagem menor esta contida na imagem maior" << std::endl;
        std::cout << "no local x: " << maxLoc.x << " y: " << maxLoc.y << std::endl;
        return { true, {center_x, center_y} };

    }
    else {
        std::cout << "a imagem menor nao esta contida na imagem maior" << std::endl;
        return { false, {0,0} };
    }
}
bool Screen::findWindow(std::string nameWindow)
{
    int len = MultiByteToWideChar(CP_ACP, 0, nameWindow.c_str(), -1, NULL, 0);
    wchar_t* wNameWindow = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, nameWindow.c_str(), -1, wNameWindow, len);

    HWND hwnd = FindWindow(NULL, wNameWindow);
    if (!hwnd)
    {
        std::cout << "janela nao encontrada" << std::endl;
        exit(-1);
    }
    std::cout << "janela encontada" << std::endl;
    return hwnd;
}

std::string Screen::imageToText(std::string target, char language[45])
{
    std::string path = target;
    cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);

    if (img.empty())
    {
        std::cerr << "N�o foi poss�vel abrir a imagem: " << path << std::endl;
    }

    tesseract::TessBaseAPI* ocr = new tesseract::TessBaseAPI();
    if (ocr->Init(NULL, language, tesseract::OEM_LSTM_ONLY) != 0)
    {
        std::cerr << "N�o foi poss�vel inicializar o Tesseract.\n";
    }

    ocr->SetPageSegMode(tesseract::PSM_AUTO);
    ocr->SetImage(img.data, img.cols, img.rows, 3, img.step);

    std::string text = std::string(ocr->GetUTF8Text());

    ocr->End();
    return text;
}
void Screen::recordCordenites(int& xS, int& yS, int& xE, int& yE)
{
    bool controller = false;
    Mal m1;
    while (!controller)
    {
        if (GetAsyncKeyState(0x01) & 0x8000)
        {
            xS = m1.mGetPosition().first;
            yS = m1.mGetPosition().second;

            std::cout << "xStart: " << xS << " yStart: " << yS << std::endl;
            Sleep(500);

            std::cout << "Grave mais uma vez" << std::endl;

            while (!(GetAsyncKeyState(0x01) & 0x8000));

            xE = m1.mGetPosition().first;
            yE = m1.mGetPosition().second;

            std::cout << "xEnd: " << xE << " yEnd: " << yE << std::endl;
            controller = true;
        }
    }
}