
#include <fbxsdk.h>
#include <stdio.h>
#include <string>
#include <NiTE.h>


using namespace nite;

int main(void)
{
    FILE* fp = fopen("joint.txt", "wb");
    std::string names[] = {"TORSO_TO_NECK", "NECK_TO_HEAD", 
      
      "NECK_TO_RIGHTSHOULDER", "RIGHTSHOULDER_TO_RIGHTELBOW", "RIGHTELBOW_TO_RIGHTHAND", 
      "NECK_TO_LEFTSHOULDER", "LEFTSHOULDER_TO_LEFTELBOW", "LEFTELBOW_TO_LEFTHAND", 
      
      "TORSO_TO_RIGHTHIP", "RIGHTHIP_TO_RIGHTKNEE", "RIGHTKNEE_TO_RIGHTFOOT",
      "TORSO_TO_LEFTHIP", "LEFTHHIP_TO_LEFTKNEE", "LEFTKNEE_TO_LEFTFOOT"
    };
    JointType types[] = {JOINT_TORSO, JOINT_HEAD,
      
      JOINT_RIGHT_SHOULDER, JOINT_RIGHT_ELBOW, JOINT_RIGHT_HAND,
      JOINT_LEFT_SHOULDER, JOINT_LEFT_ELBOW, JOINT_LEFT_HAND,
      
      JOINT_RIGHT_HIP, JOINT_RIGHT_KNEE, JOINT_RIGHT_FOOT,
      JOINT_LEFT_HIP, JOINT_LEFT_KNEE, JOINT_LEFT_FOOT
    };
    
    printf("test1 %d\n", fp);
    for(int i = 0; i < 14; i++) {
	printf("test2 %s %d\n", names[i].c_str(), types[i]);
	fprintf(fp, "%s %d\n", names[i].c_str(), types[i]);
    }
    printf("test3\n");
    fclose(fp);
}