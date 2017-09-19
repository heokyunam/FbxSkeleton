
#include "FBXLoader.h"
#include <vector>
#include <string>
#include <map>
#include <NiTE.h>

using namespace std;

class FBXSkeleton : public FBXLoader
{
private:
    map<int, FbxCluster*> joints;
    map<string, FbxCluster*> names;
public:
    FBXSkeleton(const char* pFileName, int pWindowWidth, int pWindowHeight);
    ~FBXSkeleton();
    void updateSkeleton(const nite::Skeleton& sk);
    void updateSkeleton(vector<float*> sk);
    void updateSkeleton(char* filename);
    void loadJointInfo(char* filename);
};