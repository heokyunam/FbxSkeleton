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
    FileStorage fs(filename, FileStorage::READ);
    for(int i = 0; i < 15; i++) {
	char buffer[10];
	string value;
	sprintf(buffer, "Node%d", i);
	fs[buffer] >> value;
	nodes.push_back(this->Scene->FindNodeByName(value.c_str()));
    }
    
}
