#ifndef _VectorCharacter_h_
#define _VectorCharacter_h_

#include <vector>
#include <string>

using std::vector;
using std::string;

class VectorCharacter
{
public:
	VectorCharacter();
	void vertexData(vector<float> &v, float scale, float offsetX, float offsetY, int digit);
	void vertexData(vector<float> &v, float scale, float offsetX, float offsetY, string character);
private:
	void generateColon(vector<float> &v);
	void generateDegree(vector<float> &v);
	void generateDigit0(vector<float> &v);
	void generateDigit1(vector<float> &v);
	void generateDigit2(vector<float> &v);
	void generateDigit3(vector<float> &v);
	void generateDigit4(vector<float> &v);
	void generateDigit5(vector<float> &v);
	void generateDigit6(vector<float> &v);
	void generateDigit7(vector<float> &v);
	void generateDigit8(vector<float> &v);
	void generateDigit9(vector<float> &v);
	void generateLowerCaseAM(vector<float> &v);
	void generateLowerCasePM(vector<float> &v);
	void generateMinus(vector<float> &v);
	void generatePercent(vector<float> &v);
	void generatePlus(vector<float> &v);
	void generatePoint(vector<float> &v);
	void generateUpperCaseAM(vector<float> &v);
	void generateUpperCasePM(vector<float> &v);
	void m(vector<float> &v, float x, float y);
	void c(vector<float> &v, float x1, float y1, float x2, float y2, float x, float y);
	void q(vector<float> &v, float x1, float y1, float x, float y);
	void l(vector<float> &v, float x, float y);
	void z(vector<float> &v);

	float s, dx, dy;
	float cx, cy;
	float sx, sy;
	bool started;
};

#endif
