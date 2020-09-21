#include <iostream>
#include <exception>

#include "VectorCharacter.h"

using std::vector;
using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;

// include generator function generated externally here
#include "generator.h"

VectorCharacter::VectorCharacter()
{
}

void VectorCharacter::vertexData(vector<float> &v, float scale, float offsetX, float offsetY, int digit)
{
	if (digit < 0 || digit > 9)
	{
		cerr << digit << "is not a decimal digit" << endl;
		throw runtime_error("decimal digit out of range");
	}
	string c = "0";
	c[0]+=digit;
	vertexData(v, scale, offsetX, offsetY, c);
}

void VectorCharacter::vertexData(vector<float> &v, float scale, float offsetX, float offsetY, string character)
{
	s = scale;
	dx = offsetX;
	dy = offsetY;
	cx = 0;
	cy = 0;

	if(character == "")
	{
		return;
	}
	if(character == "AM")
	{
		generateUpperCaseAM(v);
	}
	else if (character == "PM")
	{
		generateUpperCasePM(v);
	}
	else if (character == "am")
	{
		generateLowerCaseAM(v);
	}
	else if (character == "pm")
	{
		generateLowerCasePM(v);
	}
	else if (character == "°")
		generateDegree(v);
	else if (character.size() > 1)
	{
		cerr << "received unknown multi character sequence " << character << endl;
		throw runtime_error("can't handle this character sequence");
	}
	else switch(character[0])
	{
	case '0':
		generateDigit0(v);
		break;
	case '1':
		generateDigit1(v);
		break;
	case '2':
		generateDigit2(v);
		break;
	case '3':
		generateDigit3(v);
		break;
	case '4':
		generateDigit4(v);
		break;
	case '5':
		generateDigit5(v);
		break;
	case '6':
		generateDigit6(v);
		break;
	case '7':
		generateDigit7(v);
		break;
	case '8':
		generateDigit8(v);
		break;
	case '9':
		generateDigit9(v);
		break;
	case ':':
		generateColon(v);
		break;
	case '-':
		generateMinus(v);
		break;
	case '%':
		generatePercent(v);
		break;
	case '+':
		generatePlus(v);
		break;
	case '.':
		generatePoint(v);
		break;
	default:
		v.push_back(-0.2 * scale + offsetX); v.push_back(0.8 * scale + offsetY);
		v.push_back( 0.2 * scale + offsetX); v.push_back(0.8 * scale + offsetY);

		v.push_back( 0.2 * scale + offsetX); v.push_back(0.8 * scale + offsetY);
		v.push_back( 0.2 * scale + offsetX); v.push_back(0.2 * scale + offsetY);

		v.push_back( 0.2 * scale + offsetX); v.push_back(0.2 * scale + offsetY);
		v.push_back(-0.2 * scale + offsetX); v.push_back(0.2 * scale + offsetY);

		v.push_back(-0.2 * scale + offsetX); v.push_back(0.2 * scale + offsetY);
		v.push_back(-0.2 * scale + offsetX); v.push_back(0.8 * scale + offsetY);
	}
}

void VectorCharacter::m(vector<float> &v, float x, float y)
{
	// relative move to
	cx+=x;
	cy+=y;
}

void VectorCharacter::c(vector<float> &v, float x1, float y1, float x2, float y2, float x, float y)
{
	// relative cubic bezier
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
	cx+=x;
	cy+=y;
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
}

void VectorCharacter::q(vector<float> &v, float x1, float y1, float x, float y)
{
	// relative cubic bezier
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
	cx+=x;
	cy+=y;
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
}

void VectorCharacter::l(vector<float> &v, float x, float y)
{
	// relative line
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
	cx+=x;
	cy+=y;
	v.push_back(cx/100.0*s+dx);
	v.push_back(-cy/100.0*s+dy);
}

void VectorCharacter::z(vector<float> &v)
{
	//close path
}
