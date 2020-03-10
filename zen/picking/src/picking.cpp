//
// Lighthouse3D.com OpenGL Selection Sample
//
//
// This demo was built for learning purposes only.
// Some code could be severely optimised, but I tried to
// keep as simple and clear as possible.
//
// The code comes with no warranties, use it at your own risk.
// You may use it, or parts of it, wherever you want.
//
// If you do use it I would love to hear about it. Just post a comment
// at Lighthouse3D.com

// Have Fun :-)

#include <math.h>
#include <fstream>
#include <map>
#include <string>
#include <vector>


// include GLEW to access OpenGL 3.3 functions
#include <GL/glew.h>

// GLUT is the toolkit to interface with the OS
#include <GL/freeglut.h>

// Use Very Simple Libs
#include "vsShaderLib.h"
#include "vsMathLib.h"
#include "vsResourceLib.h"
#include "vsResSurfRevLib.h"


VSMathLib *vsml;
VSShaderLib shaderM, shaderP;
VSResSurfRevLib mySurfRev;

// Camera Position
float camX, camY, camZ;
float center[] = {0.0, 1.5, 0.0};

// Mouse Tracking Variables
int startX, startY, tracking = 0;

// Camera Spherical Coordinates
float alpha = 330.0f, beta = 30.0f;
float r = 9.5f;


// light direction
float lightDir[4] = {1.0f, 1.0f, 1.0f, 0.0f};

float color[][4] = {{1.0f, 1.0f, 0.0f, 1.0f},
				{1.0f, 0.0f, 0.0f, 1.0f},
				{0.0f, 1.0f, 0.0f, 1.0f},
				{0.0f, 0.0f, 1.0f, 1.0f}};



// ------------------------------------------------------------
//
// Conversion from Spherical to Cartesian Coordinates
//

void spherical2cartesian(float r, float alpha, float beta) {

	camX = center[0] + r * sin(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camZ = center[2] + r * cos(alpha * 3.14f / 180.0f) * cos(beta * 3.14f / 180.0f);
	camY = center[1] + r *   			   		         sin(beta * 3.14f / 180.0f);
}

// ------------------------------------------------------------
//
// Reshape Callback Function
//

void changeSize(int w, int h) {

	float ratio;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	ratio = (1.0f * w) / h;
	vsml->loadIdentity(VSMathLib::PROJECTION);
	vsml->perspective(53.13f, ratio, 0.1f, 10000.0f);
}


// ------------------------------------------------------------
//
// Render stuff
//

// Regular rendering

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);
	// set camera
	vsml->lookAt(camX, camY, camZ, center[0], center[1], center[2], 0,1,0);

	// transform light to camera space and send it to GLSL
	float res[4];
	vsml->multMatrixPoint(VSMathLib::VIEW, lightDir, res);
	vsml->normalize(res);
	shaderM.setBlockUniform("Lights", "l_dir", res);

	// use the regular shader
	glUseProgram(shaderM.getProgramIndex());

	vsml->translate(-2.0f, 0.0f, -2.0f);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, color[0]);
	mySurfRev.render();

	vsml->translate(4.0f, 0.0f, 0.0f);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, color[1]);
	mySurfRev.render();

	vsml->translate(-4.0f, 0.0f, 4.0f);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, color[2]);
	mySurfRev.render();

	vsml->translate(4.0f, 0.0f, 0.0f);
	mySurfRev.setColor(VSResourceLib::DIFFUSE, color[3]);
	mySurfRev.render();

	//swap buffers
	glutSwapBuffers();
}

// Rendering in selection mode

void renderSelection(void) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	vsml->loadIdentity(VSMathLib::VIEW);
	vsml->loadIdentity(VSMathLib::MODEL);
	// set camera
	vsml->lookAt(camX, camY, camZ, center[0], center[1], center[2], 0,1,0);

	// use the selection shader
	glUseProgram(shaderP.getProgramIndex());

	vsml->translate(-2.0f, 0.0f, -2.0f);
	shaderP.setUniform("code", 1);
	mySurfRev.render();

	vsml->translate(4.0f, 0.0f, 0.0f);
	shaderP.setUniform("code", 2);
	mySurfRev.render();

	vsml->translate(-4.0f, 0.0f, 4.0f);
	shaderP.setUniform("code", 3);
	mySurfRev.render();

	vsml->translate(4.0f, 0.0f, 0.0f);
	shaderP.setUniform("code", 4);
	mySurfRev.render();

	//don't swap buffers
	//glutSwapBuffers();

	// restore clear color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void processSelection(int xx, int yy) {

	unsigned char res[4];
	GLint viewport[4]; 

	renderSelection();

	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadPixels(xx, viewport[3] - yy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);
	switch(res[0]) {
		case 0: printf("Nothing Picked \n"); break;
		case 1: printf("Picked yellow\n"); break;
		case 2: printf("Picked red\n"); break;
		case 3: printf("Picked green\n"); break;
		case 4: printf("Picked blue\n"); break;
		default:printf("Res: %d\n", res[0]);
	}
}

// ------------------------------------------------------------
//
// Events from the Keyboard
//

void processKeys(unsigned char key, int xx, int yy)
{
	switch(key) {

		case 27:

			glutLeaveMainLoop();
			break;
		case 'c': printf("Camera Spherical Coordinates (%f, %f, %f)\n", alpha, beta, r);
			break;
	}
}





// ------------------------------------------------------------
//
// Mouse Events
//

void processMouseButtons(int button, int state, int xx, int yy)
{
	// start tracking the mouse
	if (state == GLUT_DOWN)  {
		startX = xx;
		startY = yy;
		if (button == GLUT_RIGHT_BUTTON)
			tracking = 1;
		else if (button == GLUT_LEFT_BUTTON) {
			tracking = 0;
			processSelection(xx,yy);
		}
	}

	//stop tracking the mouse
	else if (state == GLUT_UP) {
		if (tracking == 1) {
			alpha -= (xx - startX);
			beta += (yy - startY);
			if (beta > 85.0f)
				beta = 85.0f;
			else if (beta < -85.0f)
				beta = -85.0f;
		}
		tracking = 0;
	}
}


// Track mouse motion while buttons are pressed

void processMouseMotion(int xx, int yy)
{

	if (!tracking)
		return;

	int deltaX, deltaY;
	float alphaAux, betaAux;
	float rAux;

	deltaX =  - xx + startX;
	deltaY =    yy - startY;

	alphaAux = alpha + deltaX;
	betaAux = beta + deltaY;

	if (betaAux > 85.0f)
		betaAux = 85.0f;
	else if (betaAux < -85.0f)
		betaAux = -85.0f;
	rAux = r;

	spherical2cartesian(rAux, alphaAux, betaAux);

//  uncomment this if not using an idle func
	glutPostRedisplay();
}


void mouseWheel(int wheel, int direction, int x, int y) {

	r += direction * 0.1f;
	if (r < 0.1f)
		r = 0.1f;

	spherical2cartesian(r, alpha, beta);

//  uncomment this if not using an idle func
	glutPostRedisplay();
}

// --------------------------------------------------------
//
// Shader Stuff
//


GLuint setupShaders() {

	// Shader for models
	shaderM.init();

	shaderM.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/pixeldirdifambspec.vert");
	shaderM.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/pixeldirdifambspec.frag");

	// set semantics for the shader variables
	shaderM.setProgramOutput(0,"outputF");
	shaderM.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");
	shaderM.setVertexAttribName(VSShaderLib::NORMAL_ATTRIB, "normal");

	shaderM.prepareProgram();

	printf("InfoLog for Model Shader\n%s\n\n", shaderM.getAllInfoLogs().c_str());
	

	// Shader for selection
	shaderP.init();
	shaderP.loadShader(VSShaderLib::VERTEX_SHADER, "shaders/selection.vert");
	shaderP.loadShader(VSShaderLib::FRAGMENT_SHADER, "shaders/selection.frag");

	// set semantics for the shader variables
	shaderP.setProgramOutput(0,"outputF");
	shaderP.setVertexAttribName(VSShaderLib::VERTEX_COORD_ATTRIB, "position");

	shaderP.prepareProgram();

	printf("InfoLog for selection Shader\n%s\n\n", shaderP.getAllInfoLogs().c_str());

	return(shaderM.isProgramValid() && shaderP.isProgramValid());
}



// ------------------------------------------------------------
//
// Model loading and OpenGL setup
//

void init()
{

	spherical2cartesian(r, alpha, beta);

	mySurfRev.setMaterialBlockName("Materials");
	mySurfRev.createPawn();

// some GL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void initVSL() {

//	 Init VSML
	vsml = VSMathLib::getInstance();
	vsml->setUniformBlockName("Matrices");
	vsml->setUniformName(VSMathLib::PROJ_VIEW_MODEL, "m_pvm");
	vsml->setUniformName(VSMathLib::NORMAL, "m_normal");
	vsml->setUniformName(VSMathLib::VIEW_MODEL, "m_viewModel");
}

// ------------------------------------------------------------
//
// Main function
//


int main(int argc, char **argv) {

//  GLUT initialization
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA|GLUT_MULTISAMPLE);

	glutInitContextVersion (3, 3);
	glutInitContextProfile (GLUT_CORE_PROFILE );
	glutInitContextFlags(GLUT_DEBUG);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(512,512);
	glutCreateWindow("Lighthouse3D - Selection Demo");

//  Callback Registration
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

//	Mouse and Keyboard Callbacks
	glutKeyboardFunc(processKeys);
	glutMouseFunc(processMouseButtons);
	glutMotionFunc(processMouseMotion);

	glutMouseWheelFunc ( mouseWheel ) ;

//	return from main loop
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

//	Init GLEW
	glewExperimental = GL_TRUE;
	glewInit();

   printf ("Vendor: %s\n", glGetString (GL_VENDOR));
   printf ("Renderer: %s\n", glGetString (GL_RENDERER));
   printf ("Version: %s\n", glGetString (GL_VERSION));
   printf ("GLSL: %s\n", glGetString (GL_SHADING_LANGUAGE_VERSION));

   printf("\nInstructions:\n\tleft mouse button -> select a pawn\n\tright mouse button -> move the camera around the pawn set.\n\n");
	if (!setupShaders())
		exit(1);

	init();
	initVSL();

	//  GLUT main loop
	glutMainLoop();

	return(0);

}

