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
      
      FbxNode* node = Scene->FindNodeByName("PERSON");
      FbxMesh* mesh = node->GetMesh();
      printf("mesh count : %d\n", mesh->GetDeformerCount(FbxDeformer::eSkin));
      
      FbxSkin* skin = (FbxSkin*) mesh->GetDeformer(0, FbxDeformer::eSkin);
      
      for(int i = 0; i < skin->GetClusterCount(); i++) {
	  FbxCluster* cl = skin->GetCluster(i);
	  string name = cl->GetLink()->GetName();
	  names[name] = cl;
      }
      
      FILE* fp = fopen(filename, "r");
      char name[40];
      int nite;
      
      while(!feof(fp)) {
	  fscanf(fp, "%s %d", name, &nite);
	  joints[nite] = names[name];
      }
      
}

void FBXSkeleton::updateSkeleton(const nite::Skeleton& sk)
{
      for(int i = 0; i < 14; i++) {
	  const nite::SkeletonJoint& joint = sk.getJoint((nite::JointType)i);
	  nite::Point3f p3 = joint.getPosition();
	  FbxCluster* cl = joints[i];
	  FbxAMatrix mat;
	  cl->GetTransformMatrix(mat);
	  mat.SetT(FbxVector4(p3.x, p3.y, p3.z, 0));
	  cl->SetTransformMatrix(mat);
      }
}

void FBXSkeleton::updateSkeleton(vector<float*> sk)
{
      for(int i = 0; i < sk.size(); i++) {
	  float* joint = sk[i];
	  FbxCluster* cl = joints[i];
	  FbxAMatrix mat;
	  cl->GetTransformMatrix(mat);
	  mat.SetT(FbxVector4(joint[0], joint[1], joint[2], 0));
	  cl->SetTransformMatrix(mat);
      }
}