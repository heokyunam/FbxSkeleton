
#include "FBXLoader.h"
#include <opencv/cv.h>
#include <vector>
#include <string>
#include <map>
#include <NiTE.h>

using namespace std;
using namespace cv;

class FBXSkeleton : public FBXLoader
{
private:
    map<string, FbxNode*> nodes;
    nite::Skeleton& sk;
public:
    FBXSkeleton(const char* pFileName, int pWindowWidth, int pWindowHeight);
    ~FBXSkeleton();
    void updateSkeleton(nite::Skeleton& sk) {
	this->sk = sk;
    }
    void loadJointInfo(char* filename);
    void DrawNodeRecursive(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
		FbxAMatrix& pParentGlobalPosition, FbxPose* pPose);/*
    void DrawNode(FbxNode* pNode, FbxTime& pTime,FbxAnimLayer* pAnimLayer,FbxAMatrix& pParentGlobalPosition,
	    FbxAMatrix& pGlobalPosition,FbxPose* pPose);

    void DrawSkeleton(FbxNode* pNode, FbxAMatrix& pParentGlobalPosition, FbxAMatrix& pGlobalPosition);

    void DrawMesh(FbxNode* pNode, FbxTime& pTime, FbxAnimLayer* pAnimLayer,
	    FbxAMatrix& pGlobalPosition, FbxPose* pPose);*/
};