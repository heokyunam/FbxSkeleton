
#include "FBXSkeleton.h"
#include "simpletracker.h"
#include <GL/glut.h>

bool InitializeOpenGL();
void renderScene(void);
void changeSize(int w, int h);
void init();

FBXSkeleton * gSceneContext;

int value = 0;
int main(int argc, char **argv) {
	// init GLUT and create window	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("FBX Loading");
	
	// Initialize OpenGL.
	const bool lSupportVBO = InitializeOpenGL();
	
	FbxString lFilePath("human3.FBX");

	gSceneContext = new FBXSkeleton(lFilePath, 800, 600);
	//gSceneContext->InitControlSet();
	//updateJoint를 해야함. 결국 합쳐야됨
	
	init();
	gSceneContext->loadJointInfo("joint.txt");
	gSceneContext->updateSkeleton("joint_data.txt");
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// OpenGL init
	//glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();
	return 1;
}

void init()
{

	GLfloat light_ambient[] =
	{0.2, 0.2, 0.2, 1.0};
	GLfloat light_diffuse[] =
	{1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[] =
	{1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[] =
	{1.0, 1.0, 1.0, 0.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);



	//to do to load model..
	gSceneContext->LoadFile();

	//choose spicefic animation
	//animations in the fbx file array from 0 to --> no of animations..
	//gSceneContext->SetCurrentAnimStack(0); //Animation Array Selection..

	//we need timer to calculate frame time..
	// Call the timer to display the first frame.
	//glutTimerFunc((unsigned int)gSceneContext->GetFrameTime().GetMilliSeconds(), TimerCallback, 0);


}
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(60.0f, ratio, 10.0f, 10000.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
void renderScene(void)   //to do render here..
{

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(0, 200.0f, 800,
		0, 200.0f,  799,
		0.0f, 1.0f,  0.0f);

	glScalef(0.2,0.2,0.2);
	value += 1;
	glRotatef(value, 0, 1, 0);
	
	gSceneContext->Draw();   //<<----------draw from library..
	
	glutSwapBuffers();
} 

bool InitializeOpenGL()
{
	// Initialize GLEW.
	GLenum lError = glewInit();
	if (lError != GLEW_OK)
	{
		return false;
	}

	//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	return true;
}