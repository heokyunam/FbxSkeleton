#include "FBXSkeleton.h"
#include <stdio.h>
#include <string>

FBXSkeleton::FBXSkeleton(const char* pFileName, int pWindowWidth, int pWindowHeight) 
    : FBXLoader(pFileName, pWindowWidth, pWindowHeight)
{
    
}

FBXSkeleton::~FBXSkeleton()
{
    
}


void FBXSkeleton::loadJointInfo(char* filename)
{
    jointInfo = new cv::FileStorage(filename, cv::FileStorage::READ);
    for(int i = 0; i < 15; i++) {
	char buffer[10];
	string value;
	sprintf(buffer, "Node%d", i);
	jointInfo[buffer] >> value;
	memcpy(buffer, value.c_str(), 10); //string을 못써 buffer에 옮김
	FbxNode* node = this->Scene->GetGenericNode(buffer);
	nodes.push_back(node);
    }
    
}
