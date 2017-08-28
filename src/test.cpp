
#include <opencv/cv.h>
#include <stdio.h>
#include <string>

using namespace cv;
using namespace std;

int main(void)
{
    FileStorage fs("joint.xml", FileStorage::READ);
    printf("%d\n", fs.isOpened());
    for(int i = 0; i < 15; i++) {
	char buffer[10];
	string value;
	sprintf(buffer, "Node%d", i);
	fs[buffer] >> value;
	printf("%s : %s\n", buffer, value.c_str());
    }
}