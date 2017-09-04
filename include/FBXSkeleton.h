
#include "FBXLoader.h"
#include <opencv/cv.h>
#include <vector>

using namespace std;
using namespace cv;

class FBXSkeleton : public FBXLoader
{
private:
    vector<FbxNode*> nodes;
public:
    FBXSkeleton(const char* pFileName, int pWindowWidth, int pWindowHeight);
    ~FBXSkeleton();
    void loadJointInfo(char* filename);
    void DrawNodeRecursive(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
		FbxAMatrix& pParentGlobalPosition, FbxPose* pPose);/*
    void DrawNode(FbxNode* pNode, FbxTime& pTime,FbxAnimLayer* pAnimLayer,FbxAMatrix& pParentGlobalPosition,
	    FbxAMatrix& pGlobalPosition,FbxPose* pPose);

    void DrawSkeleton(FbxNode* pNode, FbxAMatrix& pParentGlobalPosition, FbxAMatrix& pGlobalPosition);

    void DrawMesh(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
	    FbxAMatrix& pGlobalPosition, FbxPose* pPose);*/
};