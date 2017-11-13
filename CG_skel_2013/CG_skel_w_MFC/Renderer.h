#pragma once
#include <vector>
#include "CG_skel_w_MFC.h"
#include "vec.h"
#include "mat.h"
#include "GL/glew.h"

using namespace std;
class Renderer
{
private:
	float *m_outBuffer; // 3*width*height
	float *m_zbuffer; // width*height
	int m_width, m_height;

	void CreateBuffers(int width, int height);
	void CreateLocalBuffer();

	mat4 cameraTransform;
	mat4 projection;
	mat4 objectTransform;
	mat3 normalTransform;

	//////////////////////////////
	// openGL stuff. Don't touch.

	GLuint gScreenTex;
	GLuint gScreenVtc;
	void CreateOpenGLBuffer();
	void InitOpenGLRendering();
	//////////////////////////////
public:
	Renderer();
	Renderer(int width, int height);
	~Renderer(void);
	void Init();
	void DrawTriangles(vec3* vertexPositions, int vertexPositionsSize, vec3* vertexNormals, int vertexNormalsSize);
	void drawLine(vec2 v0, vec2 v1);
	void setLineInBuffer(int* lineParameters, float *m_outBuffer);
	void plotPixel(int x, int y, float* m_outBuffer);
	void SetCameraTransform(const mat4& chosenCameraTransform);
	void SetProjection(const mat4& chosenProjection);
	void SetObjectMatrices(const mat4& chosenObjectTransform, const mat3& chosenNormalTransform);
	void SwapBuffers();
	void ClearColorBuffer();
	void ClearDepthBuffer();
	void SetDemoBuffer();
};