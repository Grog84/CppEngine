//// DbgaEngine.cpp : Defines the entry point for the console application.
////
//

#include "stdafx.h"

//#include <assert.h>
//#include "cstdint"
//#include <vector>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <cmath>
//#include <memory>
//
//#define _CINT8 const uint8_t
//
//class ImageInfo  // alternatively I could have used unsigned int and use them as validation control
//{
//public:
//	ImageInfo(int Width, int Height);
//	void SetDimensions(int Width, int Height);
//	const int & GetWidth() const;
//	const int & GetHeight() const;
//	const int * GetDimensions() const;
//
//private:
//	int Width;
//	int Height;
//	int * Dimensions = new int[2];
//};
//
//ImageInfo::ImageInfo(int TWidth, int THeight) : Width(TWidth), Height(THeight)
//{
//	assert(!((TWidth < 0) || (THeight < 0)));
//	SetDimensions(Width, Height);
//}
//
//void ImageInfo::SetDimensions(int NewWidth, int NewHeight) 
//{
//	Dimensions[0] = NewWidth;
//	Dimensions[1] = NewHeight;
//}
//
//const int & ImageInfo::GetWidth() const
//{
//	return Width;
//}
//
//const int & ImageInfo::GetHeight() const
//{
//	return Height;
//}
//
//const int * ImageInfo::GetDimensions() const
//{
//	return Dimensions;
//}
//
//class Color
//{
//public:
//
//	uint8_t Red = 0;
//	uint8_t Green = 0;
//	uint8_t Blue = 0;
//
//};
//
//
//class Image
//{
//public:
//	Image(const std::string & Name, const ImageInfo & Info);
//	~Image();
//
//	const ImageInfo & GetInfo() const;
//
//	bool SetPixel(unsigned int X, unsigned int Y, Color & Col);
//	const Color * GetPixel(unsigned int X, unsigned int Y) const;
//	void Print();
//	void SavePPM(std::ofstream & MyFile);
//
//private:
//	ImageInfo Info{ 0 , 0 };
//	std::unique_ptr<Color[]> Colors;
//	std::string Name = "";
//
//
//};
//
//Image::Image(const std::string & NewName, const ImageInfo & NewInfo) : Colors(new Color[Info.GetWidth() * Info.GetHeight()])
//{
//	assert(Name.empty());
//
//	Name = NewName;
//	Info = NewInfo;
//}
//
//Image::~Image()
//{
//}
//
//const ImageInfo & Image::GetInfo() const
//{
//	return Info;
//}
//
//bool Image::SetPixel(unsigned int X, unsigned int Y, Color & Col)
//{
//	int arrayPosition = Y * Info.GetWidth() + X ;
//	if (arrayPosition < Info.GetWidth()*Info.GetHeight())
//	{
//		Colors[arrayPosition] = Col;
//		return true;
//	}
//	
//	return false;
//	
//}
//
//const Color * Image::GetPixel(unsigned int X, unsigned int Y) const
//{
//	Color * ptr;
//	unsigned int arrayPosition = Y * Info.GetHeight() + X;
//	if (arrayPosition < Info.GetWidth()*Info.GetHeight())
//	{
//		ptr = &Colors[arrayPosition];
//		return ptr;
//	}
//	else
//	{
//		return nullptr;
//	}
//}
//
//void Image::Print()
//{
//	int arrayLength = Info.GetWidth() * Info.GetHeight();
//	/* molto rischioso!
//	Color * ptr = Colors.get();  < --- occhio
//
//	for (int i = 1; i < arrayLength + 1; i++)
//	{
//		std::cout << (int)ptr->Red << " " << (int)ptr->Green << " " << (int)ptr->Blue;
//		if (i % Info.GetWidth() == 0)
//		{
//			std::cout << std::endl;
//		}
//		else
//		{
//			std::cout << "   ";
//		}
//
//		ptr++;
//	}
//	*/
//
//	for (int i = 1; i < arrayLength + 1; i++)
//	{
//		std::cout << (int)Colors[i - 1].Red << " " << (int)Colors[i - 1].Green << " " << (int)Colors[i - 1].Blue;
//		if (i % Info.GetWidth() == 0)
//		{
//			std::cout << std::endl;
//		}
//		else
//		{
//			std::cout << "   ";
//		}
//	}
//
//}
//
//void Image::SavePPM(std::ofstream & MyFile)
//{
//	
//	MyFile << "P3\n\n" << (int)Info.GetWidth() << " " << (int)Info.GetHeight() << "\n" << 255 << "\n";
//
//	int arrayLength = Info.GetWidth() * Info.GetHeight();
//	/* molto rischioso!
//	Color * ptr = Colors.get();  < --- occhio
//
//	for (int i = 1; i < arrayLength + 1; i++)
//	{
//		MyFile << " " << (int)ptr->Red << " " << (int)ptr->Green << " " << (int)ptr->Blue;
//		if (i % Info.GetWidth() == 0)
//		{
//			MyFile << "\n";
//		}
//		else
//		{
//			MyFile << "   ";
//		}
//
//		ptr++;
//	}
//	*/
//
//	//meglio
//	for (int i = 1; i < arrayLength + 1; i++)
//	{
//		MyFile << " " << (int)Colors[i-1].Red << " " << (int)Colors[i - 1].Green << " " << (int)Colors[i - 1].Blue;
//		if (i % Info.GetWidth() == 0)
//		{
//			MyFile << "\n";
//		}
//		else
//		{
//			MyFile << "   ";
//		}
//
//	}
//
//	MyFile << "\n";
//	MyFile.close();
//}
//
//int main()
//{
//	ImageInfo Info{ 256, 512 };
//	std::string ImageName = "Image";
//
//	Image MyImage{ ImageName, Info };
//
//
//	Color Blue{0, 0, 255};
//	MyImage.SetPixel(1, 5, Blue);
//
//	int gradVal = 0;
//	float dist = std::sqrt((Info.GetWidth() -1)*(Info.GetWidth()-1) + (Info.GetHeight()-1)*(Info.GetHeight()-1));
//	int arrayLength = Info.GetWidth()*Info.GetHeight();
//
//	for (int i = 0; i < arrayLength; i++)
//	{
//		int X = i % (Info.GetWidth());
//		int Y = i / (Info.GetWidth());
//
//		float Xf = (float)X;
//		float Yf = (float)Y;
//
//		float intermVal = (std::sqrt(Xf*Xf + Yf * Yf) / dist)*255.0f;
//		int val = (int)((std::sqrt(Xf*Xf + Yf*Yf) / dist)*255.0f);
//
//		Color pixCol = Color{ (uint8_t)val, (uint8_t)val, (uint8_t)val };
//		MyImage.SetPixel(X, Y, pixCol);
//	}
//
//	// MyImage.Print();
//
//	std::ofstream MyFile;
//	MyFile.open("Test.pbm");
//	MyImage.SavePPM(MyFile);
//
//	getchar();
//
//    return 0;
//}