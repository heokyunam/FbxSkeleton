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
	    this->nodes[value] = this->Scene->FindNodeByName(value.c_str());
	}
    
}
void FBXSkeleton::DrawNodeRecursive(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
		FbxAMatrix& pParentGlobalPosition, FbxPose* pPose)
{
	//FbxAMatrix lGlobalPosition = GetGlobalPosition(pNode, pTime, pPose, &pParentGlobalPosition);
	FbxAMatrix lGlobalPosition = this->sk.getJoint((nite::JointType)nodes[pNode->GetName()]);
	if (pNode->GetNodeAttribute())
	{
		// Geometry offset.
		// it is not inherited by the children.
		FbxAMatrix lGeometryOffset = GetGeometry(pNode);
		FbxAMatrix lGlobalOffPosition = lGlobalPosition * lGeometryOffset;

		DrawNode(pNode, pTime, pAnimLayer, pParentGlobalPosition, lGlobalOffPosition, pPose);
	}

	const int lChildCount = pNode->GetChildCount();
	for (int lChildIndex = 0; lChildIndex < lChildCount; ++lChildIndex)
	{
		DrawNodeRecursive(pNode->GetChild(lChildIndex), pTime, pAnimLayer, lGlobalPosition, pPose);
	}
}
/*
void FBXSkeleton::DrawNode(FbxNode* pNode, FbxTime& pTime,FbxAnimLayer* pAnimLayer,FbxAMatrix& pParentGlobalPosition,
	FbxAMatrix& pGlobalPosition,FbxPose* pPose)
{
  
}

void FBXSkeleton::DrawSkeleton(FbxNode* pNode, FbxAMatrix& pParentGlobalPosition, FbxAMatrix& pGlobalPosition)
{
  
}

void FBXSkeleton::DrawMesh(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
	FbxAMatrix& pGlobalPosition, FbxPose* pPose)
{
  
}*/