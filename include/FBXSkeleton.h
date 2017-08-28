
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
};