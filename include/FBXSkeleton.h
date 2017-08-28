
#include "FBXLoader.h"
#include <opencv/cv.h>
#include <vector>

using namespace std;

class FBXSkeleton : public FBXLoader
{
private:
    cv::FileStorage* jointInfo;
    vector<FbxNode*> nodes;
public:
    FBXSkeleton(const char* pFileName, int pWindowWidth, int pWindowHeight);
    ~FBXSkeleton();
    void loadJointInfo(char* filename);
};